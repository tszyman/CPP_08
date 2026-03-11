#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <exception>

class Span {
	private:
		unsigned int _n;
		std::vector<int> _vec;
		Span();

	public:
		Span(unsigned int n);
		Span(const Span& src);
		Span& operator=(const Span& rhs);
		~Span();

		void addNumber(int n);
		template <typename T>
		void addRange(T begin, T end){
			if(_vec.size() + std::distance(begin, end) > _n)
				throw FullException();
			_vec.insert(_vec.end(), begin, end);
		}
		int shortestSpan();
		int longestSpan();

		class FullException : public std::exception {
			virtual const char* what() const throw() {
				return "Span is Full";
			}
		};

		class NoSpanException : public std::exception {
			virtual const char* what() const throw() {
				return "Not enough numbers to calculate Span";
			}
		};
};

#endif
