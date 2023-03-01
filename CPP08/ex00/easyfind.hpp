/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:11:07 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/14 19:43:44 by mnikolov         ###   ########.fr       */
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

template < typename T >
typename T::iterator easyfind(T &container, int i)
{
    typename T::iterator it;
    
    it = std::find(container.begin(), container.end(), i); 
    if (it == container.end())
        throw std::exception();
    return it;
}

#endif