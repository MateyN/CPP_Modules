/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:38 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 09:10:13 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static void ft_putchar(std::string str)
{
    std::cout << str << std::endl;
}

Fixed:: Fixed(void)
{
    ft_putchar(BLUE "Default constructor called" RESET);
    this->fixedPointValue = 0;
    return ;
}

Fixed:: ~Fixed(void)
{
    ft_putchar(RED "Destructor is called" RESET);
    return ;
}

Fixed:: Fixed(Fixed const &a)
{
    ft_putchar(YELLOW "Copy constructor called" RESET);
    *this = a;
}

Fixed:: Fixed(const int a)
{
    ft_putchar("Int constructor called");
    this->fixedPointValue = (a << fractionalBits);
}

Fixed:: Fixed(const float a)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixedPointValue = roundf(a * (1 << fractionalBits)); // roundf(42.42f * (1 << 8))
                                        // 10853.76f
}

Fixed &	Fixed:: operator=(Fixed const &a)
{
    ft_putchar(YELLOW "Copy assignment operator called" RESET);
    this->fixedPointValue = a.getRawBits();
    return (*this);
}

int Fixed:: getRawBits(void) const
{
    ft_putchar(GREEN "getRawBits member function called" RESET);
    return (this->fixedPointValue);
}

void    Fixed:: setRawBits(int const raw)
{
    ft_putchar(GREEN "setRawBits member function called" RESET);
    this->fixedPointValue = raw;
    return ;
}
// casting the fixed-point value to a float and dividing it by 2 to the power of fractionalBits.
float   Fixed:: toFloat(void) const
{
    return ((float)fixedPointValue / (1 << fractionalBits)); // (float)10854 / (1 << 8);
                                    // 42.421875 roundf( = 42.4219)
}
// shifting the fixed-point value to the right >> by fractionalBits,
// removing the fractional part (after the .-> rest is removed), and returning the result as an integer
int Fixed:: toInt(void) const
{
    return (this->fixedPointValue >> fractionalBits);
}

std::ostream & operator<<(std::ostream& os, Fixed const &obj)
{
    os << obj.toFloat();
    return (os);
}