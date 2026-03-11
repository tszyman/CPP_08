#include "Span.hpp"
#include <numeric>

Span::Span(unsigned int n) : _n(n) {}
Span::Span(const Span& src) : _n(src._n), _vec(src._vec) {}
Span& Span::operator=(const Span& rhs) {
	if(this != &rhs){
		_n = rhs._n;
		_vec = rhs._vec;
	}
	return *this;
}
Span::~Span() {}

void Span::addNumber(int n){
	if (_vec.size() >= _n)
		throw FullException();
	_vec.push_back(n);
}

int Span::longestSpan(){
	if (_vec.size() < 2)
		throw NoSpanException();
	// use STL to find min and max
	int min = *std::min_element(_vec.begin(), _vec.end());
	int max = *std::max_element(_vec.begin(), _vec.end());
	return max - min;
}

int Span::shortestSpan(){
	if(_vec.size() < 2)
		throw NoSpanException();
	// use STL to sort values and find min distance
		std::vector<int> sorted = _vec;
	std::sort(sorted.begin(), sorted.end());
	int minSpan = sorted[1] = sorted[0];
	for(size_t i = 1; i < sorted.size() - 1; ++i){
		int span = sorted[i+1] - sorted[i];
		if (span < minSpan)
			minSpan = span;
	}
	return minSpan;
}

