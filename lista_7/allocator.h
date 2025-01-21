#pragma once

namespace cpplab
{
    template<typename T>
    class allocator
    {
    public:
        typedef T value_type;

        allocator() = default;

        T* allocate(std::size_t n)
        {
            if (n == 0)
            {
                return nullptr;
            }
                       
            return (T*)(::operator new(n * sizeof(T)));
        }

        void deallocate(T* p, std::size_t n)
        {
            if (p != nullptr)
            {
                ::operator delete((void*)p, n);
            }
        }
    };
}
