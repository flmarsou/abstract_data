#pragma once

namespace	ft
{
	template <class Iterator>
	class	reverse_iterator
	{
		public:
			typedef Iterator								iterator_type;
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::iterator_category	iterator_category;

			// ============================================================== //
			//    Constructor & Destructor                                    //
			// ============================================================== //

			reverse_iterator();

			explicit reverse_iterator(iterator_type it);

			reverse_iterator(const reverse_iterator &other);

			~reverse_iterator();

			// ============================================================== //
			//    Dereference                                                 //
			// ============================================================== //

			iterator_type	base() const;

			reference	operator*() const;
			pointer		operator->() const;
			reference	operator[](difference_type n) const;

			// ============================================================== //
			//    Increment & Decrement                                       //
			// ============================================================== //

			reverse_iterator<Iterator>	&operator++();
			reverse_iterator<Iterator>	operator++(int);
			reverse_iterator<Iterator>	&operator--();
			reverse_iterator<Iterator>	operator--(int);

			// ============================================================== //
			//    Arithmetic                                                  //
			// ============================================================== //

			reverse_iterator<Iterator>			&operator+=(difference_type n);
			reverse_iterator<Iterator>			&operator-=(difference_type n);

			reverse_iterator<Iterator>			operator+(difference_type n) const;
			reverse_iterator<Iterator>			operator-(difference_type n) const;

			friend reverse_iterator<Iterator>	operator+(difference_type n, const reverse_iterator<Iterator> &rit);
			difference_type						operator-(const reverse_iterator<Iterator> &rhs) const;

			// ============================================================== //
			//    Comparison                                                  //
			// ============================================================== //

			bool	operator==(const reverse_iterator &rhs) const;
			bool	operator!=(const reverse_iterator &rhs) const;
			bool	operator<(const reverse_iterator &rhs) const;
			bool	operator<=(const reverse_iterator &rhs) const;
			bool	operator>(const reverse_iterator &rhs) const;
			bool	operator>=(const reverse_iterator &rhs) const;

		private:
			Iterator	_it;
	};
}

# include "reverse_iterator.tpp"
