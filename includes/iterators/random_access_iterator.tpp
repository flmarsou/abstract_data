#pragma once

# include "random_access_iterator.hpp"

namespace	ft
{
	// ====================================================================== //
	//    Constructor & Destructor                                            //
	// ====================================================================== //

	template <typename T>
	random_access_iterator<T>::random_access_iterator()
		: _ptr(NULL)
	{

	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(pointer ptr)
		: _ptr(ptr)
	{

	}

	template <typename T>
	random_access_iterator<T>::random_access_iterator(const random_access_iterator &other)
		: _ptr(other._ptr)
	{

	}

	template <typename T>
	random_access_iterator<T>::~random_access_iterator()
	{

	}

	// ====================================================================== //
	//    Dereference                                                         //
	// ====================================================================== //

	template <typename T>
	typename random_access_iterator<T>::pointer	random_access_iterator<T>::base() const
	{
		return (_ptr);
	}

	template <typename T>
	typename random_access_iterator<T>::reference	random_access_iterator<T>::operator*() const
	{
		return (*_ptr);
	}

	template <typename T>
	typename random_access_iterator<T>::pointer	random_access_iterator<T>::operator->() const
	{
		return (_ptr);
	}

	template <typename T>
	typename random_access_iterator<T>::reference	random_access_iterator<T>::operator[](difference_type n) const
	{
		return (_ptr[n]);
	}

	// ====================================================================== //
	//    Increment & Decrement                                               //
	// ====================================================================== //

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator++()
	{
		++_ptr;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator++(int)
	{
		random_access_iterator	copy(*this);
		++_ptr;
		return (copy);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator--()
	{
		--_ptr;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator--(int)
	{
		random_access_iterator	copy(*this);
		--_ptr;
		return (copy);
	}

	// ====================================================================== //
	//    Arithmetic                                                          //
	// ====================================================================== //

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator+=(difference_type n)
	{
		_ptr += n;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	&random_access_iterator<T>::operator-=(difference_type n)
	{
		_ptr -= n;
		return (*this);
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator+(difference_type n) const
	{
		return (random_access_iterator<T>(_ptr + n));
	}

	template <typename T>
	random_access_iterator<T>	random_access_iterator<T>::operator-(difference_type n) const
	{
		return (random_access_iterator<T>(_ptr - n));
	}

	template <typename T>
	random_access_iterator<T>	operator+(typename random_access_iterator<T>::difference_type n, const random_access_iterator<T> &it)
	{
		return (random_access_iterator<T>(it._ptr + n));
	}

	template <typename T>
	typename random_access_iterator<T>::difference_type	random_access_iterator<T>::operator-(const random_access_iterator<T> &rhs) const
	{
		return (_ptr - rhs._ptr);
	}

	// ====================================================================== //
	//    Comparison                                                          //
	// ====================================================================== //

	template <typename T>
	bool	random_access_iterator<T>::operator==(const random_access_iterator<T> &rhs) const
	{
		return (_ptr == rhs._ptr);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator!=(const random_access_iterator<T> &rhs) const
	{
		return (_ptr != rhs._ptr);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<(const random_access_iterator<T> &rhs) const
	{
		return (_ptr < rhs._ptr);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator<=(const random_access_iterator<T> &rhs) const
	{
		return (_ptr <= rhs._ptr);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>(const random_access_iterator<T> &rhs) const
	{
		return (_ptr > rhs._ptr);
	}

	template <typename T>
	bool	random_access_iterator<T>::operator>=(const random_access_iterator<T> &rhs) const
	{
		return (_ptr >= rhs._ptr);
	}
}
