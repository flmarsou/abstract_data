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

		private:
			Iterator	_it;
	};
}
