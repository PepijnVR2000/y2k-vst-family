#include "AllocationGuard.h"

#include <cstdlib>
#include <new>

namespace
{
thread_local int tracking = 0;
thread_local int allocations = 0;

void* allocate (std::size_t size)
{
    if (tracking > 0)
        ++allocations;
    return std::malloc (size == 0 ? 1 : size);
}
} // namespace

namespace lp::test
{
int allocationsOnThisThread() noexcept { return allocations; }

ScopedAllocationCheck::ScopedAllocationCheck() noexcept : start (allocations) { ++tracking; }
ScopedAllocationCheck::~ScopedAllocationCheck() noexcept { --tracking; }
int ScopedAllocationCheck::count() const noexcept { return allocations - start; }
} // namespace lp::test

// Replaceable global allocation functions (non-aligned variants). -----------------
void* operator new (std::size_t size)
{
    if (auto* p = allocate (size))
        return p;
    throw std::bad_alloc();
}

void* operator new[] (std::size_t size)
{
    if (auto* p = allocate (size))
        return p;
    throw std::bad_alloc();
}

void* operator new (std::size_t size, const std::nothrow_t&) noexcept { return allocate (size); }
void* operator new[] (std::size_t size, const std::nothrow_t&) noexcept { return allocate (size); }

void operator delete (void* p) noexcept { std::free (p); }
void operator delete[] (void* p) noexcept { std::free (p); }
void operator delete (void* p, std::size_t) noexcept { std::free (p); }
void operator delete[] (void* p, std::size_t) noexcept { std::free (p); }
void operator delete (void* p, const std::nothrow_t&) noexcept { std::free (p); }
void operator delete[] (void* p, const std::nothrow_t&) noexcept { std::free (p); }
