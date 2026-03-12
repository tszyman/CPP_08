#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <vector>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		// OCF
		// Default constructor
		MutantStack() : std::stack<T> () {}
		// Copy constructor
		MutantStack(const MutantStack& src) : std::stack<T>(src) {}
		// Copy Assignment Operator
		MutantStack& operator=(const MutantStack& rhs) {
			if (this != &rhs)
				std::stack<T>::operator=(rhs);
			return *this;
		}
		// Destructor
		virtual ~MutantStack() {}

		// Iterators
		typedef typename std::stack<T>::container_type::iterator iterator; //iterator

		// Return the iterators of the underying container 'c'
		iterator begin() { return this->c.begin(); }
		iterator end() { return this->c.end(); }

};

#endif
