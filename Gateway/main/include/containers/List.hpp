#pragma once
#include <cassert>
#include <stdint.h>

#include "math/Math.hpp"

//Used from the Doom3 BFG Source Code, modified by RB @ https://github.com/RobertBeckebans/RBDOOM-3-BFG
//Slightly modified

namespace Gateway
{
	//@TODO: Implement Memory manager in place of new/delete
	template<typename T>
	class List
	{
	public:
		List();
		List(int32_t t_size);
		List(const List& t_list);
		~List();

		T& Create();
		void Resize(int32_t t_size);
		void Clear();

		int32_t Add(const T& t_obj);
		int32_t Insert(const T& t_obj, int32_t t_index);
		bool Remove(const T& t_obj);
		bool RemoveIndex(int32_t t_index);

		int32_t FindIndex(const T& t_obj);

		void SetCount(int32_t t_count);

		int32_t GetCount() const;
		int32_t GetSize() const;

		List<T>& operator=(const List<T>& t_list);
		const T& operator[](int32_t t_index) const;
		T& operator[](int32_t t_index);

		T* Ptr();
		const T* Ptr() const;

	private:
		void* InternalNew(int32_t t_new_count);
		void* InternalResize(void* t_old_ptr, int32_t t_old_count, int32_t t_new_count);
		void InternalDelete(void* t_old_ptr, int32_t t_old_count);
	private:
		int32_t m_count;
		int32_t m_size;
		int32_t m_gran;
		T* m_list;
	};

	template<typename T>
	inline List<T>::List()
		: m_list(NULL), m_count(0), m_size(0), m_gran(16)
	{
		Clear();
	}

	template<typename T>
	inline List<T>::List(int32_t t_size)
	{
		m_size = t_size;
		Resize(m_size);
	}

	template<typename T>
	inline List<T>::List(const List& t_list)
	{
		m_list = NULL;
		*this = t_list;
	}

	template<typename T>
	inline List<T>::~List()
	{
		Clear();
	}

	template<typename T>
	inline T& List<T>::Create()
	{
		if (!list)
		{
			Resize(m_gran);
		}

		if (t_count == m_size)
		{
			Resize(m_size + m_gran);
		}

		return m_list[m_count++];
	}

	template<typename T>
	inline void List<T>::Resize(int32_t t_size)
	{
		assert(t_size >= 0);

		if (t_size <= 0)
		{
			Clear();
			return;
		}

		if (t_size == m_size)
		{
			return;
		}

		m_list = reinterpret_cast<T*>(InternalResize(m_list, m_count, t_size));
		m_size = t_size;
		if (m_size < m_count)
		{
			m_count = m_size;
		}

	}

	template<typename T>
	inline void List<T>::Clear()
	{
		if (m_list)
		{
			InternalDelete(m_list, m_size);
		}

		m_list = NULL;
		m_count = 0;
		m_size = 0;
	}

	template<typename T>
	inline int32_t List<T>::Add(const T& t_obj)
	{
		if (!m_list)
		{
			Resize(m_gran);
		}

		if (m_count == m_size)
		{
			int size;
			size = m_size + m_gran;
			size -= size % m_gran;
			Resize(size);
		}

		m_list[m_count] = t_obj;
		m_count++;

		return m_count - 1;
	}

	template<typename T>
	inline int32_t List<T>::Insert(const T& t_obj, int32_t t_index)
	{
		if (!m_list)
		{
			Resize(m_gran);
		}

		if (m_count == m_size)
		{
			int size;
			size = m_size + m_gran;
			size -= size % m_gran;
			Resize(size);
		}

		//If the index is < 0 then set it to 0, else if the index is greater than our count, set it to the count
		//else set it to t_index
		t_index = t_index < 0 ? 0 : t_index > m_count ? m_count : t_index;

		for (int32_t i = t_count; i > t_index; --i)
		{
			m_list[i] = m_list[i - 1];
		}
		m_count++;
		m_list[t_index] = t_obj;
		return t_index;
	}

	template<typename T>
	inline bool List<T>::Remove(const T& t_obj)
	{
		int32_t index = FindIndex(t_obj);

		if (index >= 0)
			return RemoveIndex(index);

		return false;
	}

	template<typename T>
	inline bool List<T>::RemoveIndex(int32_t t_index)
	{
		assert(m_list != NULL);
		assert(t_index >= 0);
		assert(t_index < m_count);

		if ((t_index < 0) || (t_index >= m_count))
		{
			return false;
		}

		m_count--;

		for (int32_t i = t_index; i < m_count; i++)
		{
			m_list[i] = m_list[i + 1];
		}

		return true;
	}

	template<typename T>
	inline int32_t List<T>::FindIndex(const T& t_obj)
	{
		for (int32_t i = 0; i < m_count; i++)
		{
			if (m_list[i] == t_obj)
				return i;
		}

		return -1;
	}

	template<typename T>
	inline void List<T>::SetCount(int32_t t_count)
	{
		assert(t_count >= 0);

		if (t_count > m_size)
		{
			Resize(t_count);
		}

		m_count = t_count;
	}

	template<typename T>
	inline int32_t List<T>::GetCount() const
	{
		return m_count;
	}

	template<typename T>
	inline int32_t List<T>::GetSize() const
	{
		return m_size;
	}

	template<typename T>
	inline List<T>& List<T>::operator=(const List<T>& t_list)
	{
		Clear();

		m_count = t_list.m_count;
		m_size = t_list.m_size;
		m_gran = t_list.m_gran;

		if (m_size)
		{
			m_list = reinterpret_cast<T*>(InternalNew(m_size));
			for (int32_t i = 0; i < m_count; i++)
			{
				m_list[i] = t_list.m_list[i];
			}
		}

		return *this;
	}

	template<typename T>
	inline const T& List<T>::operator[](int32_t t_index) const
	{
		assert(t_index >= 0);
		assert(t_index < m_count);

		return list[t_index];
	}

	template<typename T>
	inline T& List<T>::operator[](int32_t t_index)
	{
		assert(t_index >= 0);
		assert(t_index < m_count);

		return m_list[t_index];
	}

	template<typename T>
	inline T* List<T>::Ptr()
	{
		return m_list;
	}

	template<typename T>
	inline const T* List<T>::Ptr() const
	{
		return m_list;
	}
	
	template<typename T>
	inline void* List<T>::InternalNew(int32_t t_new_count)
	{
		T* ptr = NULL;

		ptr = reinterpret_cast<T*>(malloc(t_new_count * sizeof(T)));
		for (int32_t i = 0; i < t_new_count; i++)
		{
			new(&ptr[i]) T;
		}

		return ptr;
	}

	template<typename T>
	inline void* List<T>::InternalResize(void* t_old_ptr, int32_t t_old_count, int32_t t_new_count)
	{
		T* old_ptr = reinterpret_cast<T*>(t_old_ptr);
		T* new_ptr = NULL;

		if (t_new_count > 0)
		{
			new_ptr = reinterpret_cast<T*>(InternalNew(t_new_count));
			int32_t over = Math::Min(t_old_count, t_new_count);
			for (int32_t i = 0; i < over; i++)
			{
				new_ptr[i] = old_ptr[i];
			}
		}
		InternalDelete(t_old_ptr, t_old_count);

		return new_ptr;
	}
	
	template<typename T>
	inline void List<T>::InternalDelete(void* t_old_ptr, int32_t t_old_count)
	{
		for (int32_t i = 0; i < t_old_count; i++)
		{
			reinterpret_cast<T*>(t_old_ptr)[i].~T();
		}
		free(t_old_ptr);
	}
};