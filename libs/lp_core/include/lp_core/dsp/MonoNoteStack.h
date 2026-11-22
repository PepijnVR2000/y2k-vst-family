#pragma once

#include <array>
#include <cstdint>

namespace lp::dsp
{
// Held-note stack for monophonic last-note priority. Fixed capacity (one slot
// per MIDI note), no allocation. Pressing a held note again moves it to the top.
class MonoNoteStack
{
public:
    static constexpr int capacity = 128;

    struct Note
    {
        int number = -1;
        float velocity = 0.0f;
    };

    void clear() noexcept { count = 0; }
    bool isEmpty() const noexcept { return count == 0; }
    int size() const noexcept { return count; }

    // Most recently pressed note still held, or {-1, 0} when empty.
    Note top() const noexcept { return count > 0 ? notes[static_cast<size_t> (count - 1)] : Note{}; }

    void push (int number, float velocity) noexcept
    {
        if (number < 0 || number >= capacity)
            return;
        remove (number);
        notes[static_cast<size_t> (count++)] = { number, velocity };
    }

    // Returns true if the note was held.
    bool remove (int number) noexcept
    {
        for (int i = 0; i < count; ++i)
        {
            if (notes[static_cast<size_t> (i)].number == number)
            {
                for (int j = i; j < count - 1; ++j)
                    notes[static_cast<size_t> (j)] = notes[static_cast<size_t> (j + 1)];
                --count;
                return true;
            }
        }
        return false;
    }

private:
    std::array<Note, capacity> notes {};
    int count = 0;
};

} // namespace lp::dsp
