/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:11:07 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/03 10:25:06 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define RED     "\033[1m\033[31m"

#include <iostream>
#include <list>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int i)
{
    typename T::iterator it; // create an iterator of the container of type T
    it = std::find(container.begin(), container.end(), i); // use the STL find algorithm to search for the first occurrence of i in the container 
    if (it == container.end()) // if the iterator is equal to the end of the container
        throw std::exception(); // not found exception
    return it; // return the iterator pointing to the first occurrence of i in the container
}

#endif