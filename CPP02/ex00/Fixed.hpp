/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:41 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/28 10:49:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#include <iostream>
#include <string>

class Fixed
{
    public:
            Fixed(void);
            Fixed(Fixed &a);
            ~Fixed(void);

            Fixed &	operator=(Fixed &a);

            int     getRawBits(void) const;
            void    setRawBits(int const raw);

    private:
            static const int    storeBits = 8;
            int                 number;
};

#endif