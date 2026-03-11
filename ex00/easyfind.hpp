/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 19:58:06 by tszymans          #+#    #+#             */
/*   Updated: 2026/03/11 20:13:03 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>

//Exception for when the element is not found
class NotFoundException : public std::exception {
	public:
		virtual const char* what()
			const throw() {
				return "Element not found in container";
			}
};



template <typename T>
typename T::iterator easyfind(T & container, int x){
	// std::find searches to the end of the container
	// It returns an iterator to the first occurence or container.end() if not found
	typename T::iterator it = std::find(container.begin(), container.end(), x);
	if (it == container.end()){
		throw NotFoundException();
	}
	return it;
}

#endif
