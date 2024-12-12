#pragma once

namespace cpplab
{
	template<typename T>
	class unique_ptr
	{

	private:
		T* pointer;

	public:
		unique_ptr(): pointer(nullptr) {}
		unique_ptr(T* ptr): pointer(ptr) {}
		unique_ptr(unique_ptr&& ptr) noexcept : pointer(ptr.pointer) { ptr.pointer = nullptr; }

		unique_ptr& operator=(unique_ptr&& ptr) noexcept
		{
			if (this != &ptr)
			{
				reset();
				pointer = ptr.pointer;
				ptr.pointer = nullptr;
			}
			return *this;
		}

		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		~unique_ptr() { reset(); }


		T& operator*() const
		{
			return *pointer;
		}


		T* release()
		{
			T* temp = pointer;
			pointer = nullptr;
			return temp;
		}

		void reset(T* ptr = nullptr)
		{
			if (pointer)
			{
				delete pointer;
			}
			pointer = ptr;
		}

		void swap(unique_ptr<T>& ptr)
		{
			T* temp = pointer;
			pointer = ptr.get();
			ptr.pointer = temp;
		}


		T* get() const
		{
			return pointer;
		}

		explicit operator bool() const
		{
			return pointer != nullptr;
		}
		
	};

}
