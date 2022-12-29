/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:41 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/29 10:26:08 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"

#include <cmath>
#include <iostream>
#include <string>

class Fixed
{
    public:
            Fixed(void);
            Fixed(const int a);
            Fixed(Fixed const &a);
            Fixed(const float a);
            Fixed & operator=(Fixed const &a);
            ~Fixed(void);
            
            int         getRawBits(void) const;
            void        setRawBits(int const raw);
            float       toFloat(void) const;
            int         toInt(void) const;

    private:
            static const int    storeBits = 8;
            int                 number;
};
        std::ostream & operator<<(std::ostream& os, Fixed const &obj);
#endif