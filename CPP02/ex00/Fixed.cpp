/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:38 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 09:14:36 by mnikolov         ###   ########.fr       */
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

Fixed:: Fixed(Fixed &a)
{
    ft_putchar(YELLOW "Copy constructor called" RESET);
    *this = a;
}

Fixed &	Fixed:: operator=(Fixed &a)
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