#include "MutantStack.hpp"
#include <iostream>
#include <algorithm>

void printElement(int i)
{
	std::cout << i << " ";
}

int main(){
	std::cout << "--- Test with stack ---" << std::endl;
	MutantStack<int>	mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Stack top element: " << mstack.top() << std::endl;

	std::cout << "Removing top element" << std::endl;
	mstack.pop();

	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	std::cout << "\n-- Stack print --" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Stack elements (printed with for_each): ";
	// Use std::for_each with your MutantStack iterators
	std::for_each(mstack.begin(), mstack.end(), printElement);
	std::cout << std::endl;

	std::stack<int> s(mstack);
	std::cout << "\n--- Test with list ---" << std::endl;

	std::list<int>	l;

	l.push_back(5);
	l.push_back(17);

	std::cout << "List top element: " << l.back() << std::endl;
	std::cout << "Removing top element" << std::endl;
	l.pop_back();

	std::cout << "List size: " << l.size() << std::endl;

	l.push_back(3);
	l.push_back(5);
	l.push_back(737);
	//[...]
	l.push_back(0);

	std::list<int>::iterator list_it = l.begin();
	std::list<int>::iterator list_ite = l.end();

	++list_it;
	--list_it;

	std::cout << "\n-- List print --" << std::endl;
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}

	std::cout << "List elements (printed with for_each): ";
	// Use std::for_each with list iterators
	std::for_each(l.begin(), l.end(), printElement);
	std::cout << std::endl;

	std::list<int> ll(l);

	return 0;
}
