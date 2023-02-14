/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:38:11 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/06 12:19:06 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"

#include <iostream>

template <typename T>
void    iter(T *array, size_t length, void(*func)(T &t))
{
    if(array == NULL || func == NULL)
        return ;
    for (int i = 0; i < length; i++)
        func(array[i]);
}

#endif