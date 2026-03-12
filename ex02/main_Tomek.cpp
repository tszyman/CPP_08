#include "MutantStack.hpp"
#include <iostream>
#include <list>

template <typename T>
void printContainer(T &container)
{
	// 1. Always use typename for dependent types like T::iterator
	typename T::iterator it = container.begin();
	typename T::iterator ite = container.end();

	// 2. Standard for-loop syntax
	for (; it != ite; ++it)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

int main(){
	std::cout << "--- Test with stack ---" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	// MutantStack<int>::iterator it = mstack.begin();
	// MutantStack<int>::iterator ite = mstack.end();

	// ++it;
	// --it;
	std::cout << "\n-- Stack print --" << std::endl;
	// while (it != ite)
	// {
	// 	std::cout << *it << std::endl;
	// 	++it;
	// }
	printContainer(mstack);
	std::stack<int> s(mstack);
	std::cout << "\n--- Test with list ---" << std::endl;

	std::list<int>	l;

	l.push_back(5);
	l.push_back(17);

	std::cout << l.back() << std::endl;

	l.pop_back();

	std::cout << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	// std::list<int>::iterator list_it = l.begin();
	// std::list<int>::iterator list_ite = l.end();

	// ++list_it;
	// --list_it;

	std::cout << "\n-- List print --" << std::endl;
	// while (list_it != list_ite)
	// {
	// 	std::cout << *list_it << std::endl;
	// 	++list_it;
	// }
	printContainer(l);
	std::list<int> ll(l);

	return 0;
}
