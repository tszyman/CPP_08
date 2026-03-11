#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <iterator>
#include "easyfind.hpp"

// Helper function to print integers
void printElement(int i){
	std::cout << i << " ";
}


int main(){
	// Test 1: Using a Vector
	std::cout << "--- Test 1: Using std::vector ---" << std::endl;
	std::vector<int> v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	try {
		// List all vector elements
		std::cout << "Container(vector) elements: ";
		std::for_each(v.begin(), v.end(), printElement);
		std::cout << std::endl;
		// List the value that is searched for
		int toFind = 20;
		std::cout << "Searching for value: " << toFind << std::endl;

		std::vector<int>::iterator it = easyfind(v, toFind);
		if (it != v.end()){
			// std::distance returns the number of steps from v.begin() to it
			int pos = std::distance(v.begin(), it);
			std::cout << "Found: " << *it << " (@index: " << pos << ")" << std::endl;
		}

		std::cout << "Searching for missing value (42)..." << std::endl;
		easyfind(v, 42);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// Test 2: Using a List
	std::cout << "\n--- Test 2: Using std::list ---" << std::endl;
	std::list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	try {
		//List all list elements
		std::cout << "Container(list) elements: " << std::endl;
		std::for_each(l.begin(), l.end(), printElement);
		std::cout << std::endl;
		//List the value that is searched for
		int toFind = 3;
		std::cout << "Searching for value: " << toFind << std::endl;
		std::list<int>::iterator it = easyfind(l, toFind);

		if (it != l.end()){
			int pos = std::distance(l.begin(), it);
			std::cout << "Found: " << *it << " (@index: " << pos << ")" << std::endl;
		}

		std::cout << "Searching again for 42..." << std::endl;
		easyfind(l, 42);
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
}
