#pragma once

namespace cpplab
{
	template<typename T>
	class unique_ptr{

	private:
		T* m_Pointer;

	public:
		unique_ptr(): m_Pointer(nullptr) {}
		unique_ptr(T* ptr): m_Pointer(ptr) {}
		unique_ptr(unique_ptr&& ptr) noexcept : m_Pointer(ptr.m_Pointer) { ptr.m_Pointer = nullptr; }

		unique_ptr& operator=(unique_ptr&& ptr) noexcept
		{
			if (this != &ptr)
			{
				reset();
				m_Pointer = ptr.m_Pointer;
				ptr.m_Pointer = nullptr;
			}
			return *this;
		}

		unique_ptr(const unique_ptr&) = delete;
		unique_ptr& operator=(const unique_ptr&) = delete;

		~unique_ptr() { reset(); }


		T& operator*() const
		{
			return *m_Pointer;
		}


		void reset(T* ptr = nullptr)
		{
			if (m_Pointer)
			{
				delete m_Pointer;
			}
			
			m_Pointer = ptr;
		}

		void swap(unique_ptr<T>& ptr)
		{
			T* temp = m_Pointer;
			m_Pointer = ptr.get();
			ptr.m_Pointer = temp;
		}


		T* get() const
		{
			return m_Pointer;
		}

		explicit operator bool() const
		{
			return m_Pointer != nullptr;
		}
		
	};

}
