/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:07:18 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/06 10:34:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

/**
 * Passing the parameters as "T &a" instead of "T a" is better
 * because the program does not create a copy of "a" so is more efficient.
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
T min(T &a, T &b)
{
    if (a < b)
        return a;
    else
        return b;
}

template <typename T>
T max(T &a, T &b)
{
    if (a > b)
        return a;
    else
        return b;
}

#endif