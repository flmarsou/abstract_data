#pragma once

# include <memory>

# include "iterators/random_access_iterator.hpp"
# include "iterators/reverse_iterator.hpp"

namespace	ft
{
	template < class T, class Alloc = std::allocator<T> >
	class	vector
	{
		public:
			typedef T														value_type;
			typedef Alloc													allocator_type;
			typedef typename allocator_type::reference						reference;
			typedef typename allocator_type::const_reference				const_reference;
			typedef typename allocator_type::pointer						pointer;
			typedef typename allocator_type::const_pointer					const_pointer;
			typedef typename ft::random_access_iterator<value_type>			iterator;
			typedef typename ft::random_access_iterator<const value_type>	const_iterator;
			typedef typename ft::reverse_iterator<iterator>					reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>			const_reverse_iterator;
			typedef std::ptrdiff_t											difference_type;
			typedef std::size_t												size_type;

		private:
			pointer			_data;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};
}
