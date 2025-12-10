#pragma once

# include "reverse_iterator.hpp"

namespace	ft
{
	// ====================================================================== //
	//    Constructor & Destructor                                            //
	// ====================================================================== //

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator()
		: _it()
	{

	}

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(iterator_type it)
		: _it(it)
	{

	}

	template <class Iterator>
	reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator &other)
		: _it(other._it)
	{

	}

	template <class Iterator>
	reverse_iterator<Iterator>::~reverse_iterator()
	{

	}

	// ====================================================================== //
	//    Dereference                                                         //
	// ====================================================================== //

	template <class Iterator>
	typename reverse_iterator<Iterator>::iterator_type	reverse_iterator<Iterator>::base() const
	{
		return (_it);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator*() const
	{
		Iterator	tmp = _it;
		--tmp;
		return (*tmp);
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::pointer	reverse_iterator<Iterator>::operator->() const
	{
		Iterator	tmp = _it;
		--tmp;
		return (&(*tmp));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::reference	reverse_iterator<Iterator>::operator[](difference_type n) const
	{
		return (*(_it - 1 - n));
	}

	// ====================================================================== //
	//    Increment & Decrement                                               //
	// ====================================================================== //

	template <class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator++()
	{
		--_it;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator++(int)
	{
		reverse_iterator	copy(*this);
		--_it;
		return (copy);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator--()
	{
		++_it;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator--(int)
	{
		reverse_iterator	copy(*this);
		++_it;
		return (copy);
	}

	// ====================================================================== //
	//    Arithmetic                                                          //
	// ====================================================================== //

	template <class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator+=(difference_type n)
	{
		_it -= n;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	&reverse_iterator<Iterator>::operator-=(difference_type n)
	{
		_it += n;
		return (*this);
	}

	template <class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator+(difference_type n) const
	{
		return (reverse_iterator<Iterator>(_it - n));
	}

	template <class Iterator>
	reverse_iterator<Iterator>	reverse_iterator<Iterator>::operator-(difference_type n) const
	{
		return (reverse_iterator(_it + n));
	}

	template <class Iterator>
	reverse_iterator<Iterator>	operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rit)
	{
		return (reverse_iterator(rit._it - n));
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type	reverse_iterator<Iterator>::operator-(const reverse_iterator<Iterator> &rhs) const
	{
		return (rhs._it - _it);
	}

	// ====================================================================== //
	//    Comparison                                                          //
	// ====================================================================== //

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator==(const reverse_iterator &rhs) const
	{
		return (_it == rhs._it);
	}

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator!=(const reverse_iterator &rhs) const
	{
		return (_it != rhs._it);
	}

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator<(const reverse_iterator &rhs) const
	{
		return (_it > rhs._it);
	}

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator<=(const reverse_iterator &rhs) const
	{
		return (_it >= rhs._it);
	}

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator>(const reverse_iterator &rhs) const
	{
		return (_it < rhs._it);
	}

	template <class Iterator>
	bool	reverse_iterator<Iterator>::operator>=(const reverse_iterator &rhs) const
	{
		return (_it <= rhs._it);
	}
}
