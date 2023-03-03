/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:07:18 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/03 10:30:47 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/*
 * Passing the parameters as "T &a" instead of "T a" is better
 * because the program does not create a copy of "a".
 * const T&, because this allows the function to return a reference to one of the input objects,
 * which is more efficient than returning a copy of the object.
 */

template <typename T>
void swap(T &a, T &b)
{
    T tmp;

    tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
const T& min(const T& a, const T& b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif