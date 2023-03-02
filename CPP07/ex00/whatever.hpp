/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:07:18 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/08 17:38:17 by mnikolov         ###   ########.fr       */
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
T swap(T &a, T &b)
{
    char tmp;

    tmp = a;
    a = b;
    b = tmp;

    return tmp;
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