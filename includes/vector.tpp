#pragma once

# include "vector.hpp"

namespace	ft
{
	// ====================================================================== //
	//    Constructor & Destructor                                            //
	// ====================================================================== //

	template <class T, class Alloc>
	vector<T, Alloc>::vector(const allocator_type &alloc)
		: _data(NULL), _size(0), _capacity(0), _alloc(alloc)
	{

	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(size_type n, const value_type &val, const allocator_type &alloc)
		: _size(n), _capacity(n), _alloc(alloc)
	{
		_data = _alloc.allocate(n);
		for (size_type i = 0; i < n; ++i)
			_alloc.construct(_data + i, val);
	}

	template <class T, class Alloc>
	template <class InputIterator>
	vector<T, Alloc>::vector(InputIterator first, InputIterator last, const allocator_type &alloc)
		: _alloc(alloc)
	{
		const size_type	size = last - first;

		_data = _alloc.allocate(size);
		_size = size;
		_capacity = size;
		for (size_type i = 0; first != last; ++i)
			_alloc.construct(_data + i, *(first++));
	}

	template <class T, class Alloc>
	vector<T, Alloc>::vector(const vector &x)
		: _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
	{
		_data = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
			_alloc.construct(_data + i, x._data[i]);
	}

	template <class T, class Alloc>
	vector<T, Alloc>	&vector<T, Alloc>::operator=(const vector &x)
	{
		if (this == &x)
			return (*this);

		if (_data)
		{
			clear();
			_alloc.deallocate(_data, _capacity);
		}

		_data = NULL;
		_size = x._size;
		_capacity = x._capacity;
		_alloc = x._alloc;

		if (!x._data)
			return (*this);

		_data = _alloc.allocate(_capacity);
		for (size_type i = 0; i < _size; ++i)
			_alloc.construct(_data + i, x._data[i]);

		return (*this);
	}

	template <class T, class Alloc>
	vector<T, Alloc>::~vector()
	{
		if (_data)
		{
			clear();
			_alloc.deallocate(_data, _capacity);
		}
	}

	// ====================================================================== //
	//    Iterators                                                           //
	// ====================================================================== //

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::begin()
	{
		return (iterator(_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::begin() const
	{
		return (const_iterator(_data));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::end()
	{
		return (iterator(_data + _size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_iterator	vector<T, Alloc>::end() const
	{
		return (const_iterator(_data + _size));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rbegin()
	{
		return (reverse_iterator(end()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rbegin() const
	{
		return (const_reverse_iterator(end()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reverse_iterator	vector<T, Alloc>::rend()
	{
		return (reverse_iterator(begin()));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reverse_iterator	vector<T, Alloc>::rend() const
	{
		return (const_reverse_iterator(begin()));
	}

	// ====================================================================== //
	//    Capacity                                                            //
	// ====================================================================== //

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::size() const
	{
		return (_size);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::max_size() const
	{
		return (_alloc.max_size());
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::resize(size_type n, value_type val)
	{
		if (n > max_size())
			throw std::length_error("ft::vector.resize() exceeds max_size");

		if (n < _size)
		{
			for (size_type i = n; i < _size; ++i)
				_alloc.destroy(_data + i);
		}
		else
		{
			if (n > _capacity)
				reserve(n > _capacity * 2 ? n : _capacity * 2);
			for (size_type i = _size; i < n; ++i)
				_alloc.construct(_data + i, val);
		}

		_size = n;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::size_type	vector<T, Alloc>::capacity() const
	{
		return (_capacity);
	}

	template <class T, class Alloc>
	bool	vector<T, Alloc>::empty() const
	{
		return (_size == 0);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::reserve(size_type n)
	{
		if (n > max_size())
			throw std::length_error("ft::vector.reserve() exceeds max_size");
		else if (n <= _capacity)
			return ;

		pointer	new_data = _alloc.allocate(n);
		for (size_type i = 0; i < _size; ++i)
		{
			_alloc.construct(new_data + i, _data[i]);
			_alloc.destroy(_data + i);
		}
		if (_data)
			_alloc.deallocate(_data, _capacity);

		_capacity = n;
		_data = new_data;
	}

	// ====================================================================== //
	//    Element access                                                      //
	// ====================================================================== //

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::operator[](size_type n)
	{
		return (_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::operator[](size_type n) const
	{
		return (_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::at(size_type n)
	{
		if (n >= _size)
			throw std::out_of_range("ft::vector.at()");
		return (_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::at(size_type n) const
	{
		if (n >= _size)
			throw std::out_of_range("ft::vector.at()");
		return (_data[n]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::front()
	{
		return (_data[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::front() const
	{
		return (_data[0]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::reference	vector<T, Alloc>::back()
	{
		return (_data[_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::const_reference	vector<T, Alloc>::back() const
	{
		return (_data[_size - 1]);
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::value_type	*vector<T, Alloc>::data()
	{
		return (_data);
	}

	template <class T, class Alloc>
	const typename vector<T, Alloc>::value_type	*vector<T, Alloc>::data() const
	{
		return (_data);
	}

	// ====================================================================== //
	//    Modifiers                                                           //
	// ====================================================================== //

	// template <class T, class Alloc>
	// template <class InputIterator>
	// void	vector<T, Alloc>::assign(InputIterator first, InputIterator last)
	// {
	// 	(void)first;
	// 	(void)last;
	// }

	template <class T, class Alloc>
	void	vector<T, Alloc>::assign(size_type n, const value_type &val)
	{
		const size_type	size_tpm = _size;

		resize(_size + n);

		for (size_type i = size_tpm; i < n; ++i)
			_alloc.construct(_data + i, val);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::push_back(const value_type &val)
	{
		if (_size == _capacity)
			reserve(_capacity == 0 ? 1 : _capacity * 2);

		_alloc.construct(_data + _size, val);
		++_size;
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::pop_back()
	{
		_alloc.destroy(_data + _size - 1);
		--_size;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::insert(iterator position, const value_type &val)
	{
		const size_type	index = position - begin();

		if (_size == _capacity)
			reserve(_capacity == 0 ? 1 : _capacity * 2);

		for (size_type i = _size - 1; i >= index; --i)
			_data[i + 1] = _data[i];
		_alloc.construct(_data + index, val);

		++_size;
		return (iterator(_data + index));
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::insert(iterator position, size_type n, const value_type &val)
	{
		const size_type	index = position - begin();

		if (_size + n >= _capacity)
			reserve(_size + n);

		for (size_type i = _size - 1; i >= index; --i)
			_data[i + n] = _data[i];
		for (size_type i = index; i <= n; ++i)
			_alloc.construct(_data + i, val);

		_size += n;
	}

	// template <class T, class Alloc>
	// template <class InputIterator>
	// void	vector<T, Alloc>::insert(iterator position, InputIterator first, InputIterator last)
	// {

	// }

	template <class T, class Alloc>
	void	vector<T, Alloc>::clear()
	{
		for (size_type i = 0; i < _size; ++i)
			_alloc.destroy(_data + i);

		_size = 0;
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
	{
		const size_type	index = position - begin();

		_alloc.destroy(_data + position);
		for (size_type i = index; i < _size - 1; ++i)
			_data[i] = _data[i + 1];
		_alloc.destroy(_data + _size - 1);

		--_size;

		return (iterator(_data + index));
	}

	template <class T, class Alloc>
	typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator first, iterator last)
	{
		const size_type	indexFirst = first - begin();
		const size_type	indexLast = last - begin();

		for (size_type i = indexFirst; i < indexLast; ++i)
			_alloc.destroy(_data + indexFirst);
	}

	template <class T, class Alloc>
	void	vector<T, Alloc>::swap(vector &x)
	{
		pointer			data_tmp = _data;
		size_type		size_tmp = _size;
		size_type		capacity_tpm = _capacity;
		allocator_type	alloc_tmp = _alloc;

		_data = x._data;
		_size = x._size;
		_capacity = x._capacity;
		_alloc = x._alloc;

		x._data = data_tmp;
		x._size = size_tmp;
		x._capacity = capacity_tpm;
		x._alloc = alloc_tmp;
	}

	// ====================================================================== //
	//    Allocator                                                           //
	// ====================================================================== //

	template <class T, class Alloc>
	typename vector<T, Alloc>::allocator_type	vector<T, Alloc>::get_allocator() const
	{
		return (_alloc);
	}

	// ====================================================================== //
	//    Non-member function overloads                                       //
	// ====================================================================== //

	template <class U, class A>
	bool	operator==(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);

		for (typename vector<U, A>::size_type i = 0; i < lhs.size(); ++i)
			if (lhs[i] != rhs[i])
				return (false);

		return (true);
	}

	template <class U, class A>
	bool	operator!=(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		return (!(lhs == rhs));
	}

	template <class U, class A>
	bool	operator<(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		const typename vector<U, A>::size_type	size = (lhs.size() < rhs.size() ? lhs.size() : rhs.size());

		for (typename vector<U, A>::size_type i = 0; i < size; ++i)
		{
			if (lhs[i] < rhs[i])
				return (true);
			if (lhs[i] > rhs[i])
				return (false);
		}

		return (lhs.size() < rhs.size());
	}

	template <class U, class A>
	bool	operator<=(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		return (!(rhs < lhs));
	}

	template <class U, class A>
	bool	operator>(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		return (rhs < lhs);
	}

	template <class U, class A>
	bool	operator>=(const vector<U, A> &lhs, const vector<U, A> &rhs)
	{
		return (!(lhs < rhs));
	}

	template <class U, class A>
	void	swap(vector<U, A> &x, vector<U, A> &y)
	{
		x.swap(y);
	}
}
