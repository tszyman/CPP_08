#include <iostream>
#include "Span.hpp"
#include <vector>

int main(){
	// Subject Test
	std::cout << "--- Subject Test ---" << std::endl;
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	// Large Test (10 000 numbers)
	std::cout << "\n--- Large Test (10 000+ numbers)" << std::endl;
	Span bigSp(10000);
	std::vector<int> bigData;
	for (int i = 0; i < 10000; ++i)
		bigData.push_back(i * 2);

	try {
		bigSp.addRange(bigData.begin(), bigData.end());
		std::cout << "Shortest span: " << bigSp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << bigSp.longestSpan() << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
