/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:38 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/29 10:29:09 by mnikolov         ###   ########.fr       */
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
    this->number = 0;
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
    this->number = (a << storeBits);
}

Fixed:: Fixed(const float a)
{
    std::cout << "Float constructor called" << (1 << storeBits) << std::endl;
    this->number = roundf(a * (1 << storeBits));
}

Fixed &	Fixed:: operator=(Fixed const &a)
{
    ft_putchar(YELLOW "Copy assignment operator called" RESET);
    this->number = a.getRawBits();
    return (*this);
}

int Fixed:: getRawBits(void) const
{
    ft_putchar(GREEN "getRawBits member function called" RESET);
    return (this->number);
}

void    Fixed:: setRawBits(int const raw)
{
    ft_putchar(GREEN "setRawBits member function called" RESET);
    this->number = raw;
    return ;
}

float   Fixed:: toFloat(void) const
{
    return ((float)(this->number) / (float) (1 << storeBits));
}

int Fixed:: toInt(void) const
{
    return (this->number >> storeBits);
}

std::ostream & operator<<(std::ostream& os, Fixed const &obj)
{
    os << obj.toFloat();
    return (os);
}