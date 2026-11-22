#pragma once

// Counts heap allocations made on the current thread while a ScopedAllocationCheck
// is alive. Implemented by replacing the global operator new in AllocationGuard.cpp
// (test executable only). Used to prove processBlock() never allocates.

namespace lp::test
{
int allocationsOnThisThread() noexcept;

class ScopedAllocationCheck
{
public:
    ScopedAllocationCheck() noexcept;
    ~ScopedAllocationCheck() noexcept;
    int count() const noexcept;

private:
    int start;
};

} // namespace lp::test
