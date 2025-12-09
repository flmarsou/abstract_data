#pragma once

# include <cstddef>
# include <iterator>

namespace	ft
{
	template <typename T>
	class	random_access_iterator
	{
		public:
			typedef T								value_type;
			typedef T								*pointer;
			typedef T								&reference;
			typedef std::ptrdiff_t					difference_type;
			typedef std::random_access_iterator_tag	iterator_category;

			// ============================================================== //
			//    Constructor & Destructor                                    //
			// ============================================================== //

			random_access_iterator();

			explicit random_access_iterator(pointer ptr);

			random_access_iterator(const random_access_iterator &other);

			~random_access_iterator();

			// ============================================================== //
			//    Dereference                                                 //
			// ============================================================== //

			pointer	base() const;

			reference	operator*() const;
			pointer		operator->() const;
			reference	operator[](difference_type n) const;

			// ============================================================== //
			//    Increment & Decrement                                       //
			// ============================================================== //

			random_access_iterator<T>	&operator++();
			random_access_iterator<T>	operator++(int);
			random_access_iterator<T>	&operator--();
			random_access_iterator<T>	operator--(int);

			// ============================================================== //
			//    Arithmetic                                                  //
			// ============================================================== //

			random_access_iterator<T>			&operator+=(difference_type n);
			random_access_iterator<T>			&operator-=(difference_type n);

			random_access_iterator<T>			operator+(difference_type n) const;
			random_access_iterator<T>			operator-(difference_type n) const;

			friend random_access_iterator<T>	operator+(difference_type n, const random_access_iterator<T> &it);
			difference_type						operator-(const random_access_iterator<T> &rhs) const;

			// ============================================================== //
			//    Comparison                                                  //
			// ============================================================== //

			bool	operator==(const random_access_iterator<T> &rhs) const;
			bool	operator!=(const random_access_iterator<T> &rhs) const;
			bool	operator<(const random_access_iterator<T> &rhs) const;
			bool	operator<=(const random_access_iterator<T> &rhs) const;
			bool	operator>(const random_access_iterator<T> &rhs) const;
			bool	operator>=(const random_access_iterator<T> &rhs) const;

		private:
			pointer	_ptr;
	};
}

# include "random_access_iterator.tpp"
