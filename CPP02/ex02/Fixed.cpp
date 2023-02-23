/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:38 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 09:15:39 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed:: Fixed(void)
{
    this->fixedPointValue = 0;
    return ;
}

Fixed:: ~Fixed(void)
{
    return ;
}

Fixed:: Fixed(Fixed const &a)
{
    *this = a;
}

Fixed:: Fixed(const int a)
{
    this->fixedPointValue = (a << fractionalBits);
}

Fixed:: Fixed(const float a)
{
    this->fixedPointValue = roundf(a * (1 << fractionalBits));
}

Fixed &	Fixed:: operator=(Fixed const &a)
{
    this->fixedPointValue = a.getRawBits();
    return (*this);
}

int Fixed:: getRawBits(void) const
{
    return (this->fixedPointValue);
}

void    Fixed:: setRawBits(int const raw)
{
    this->fixedPointValue = raw;
    return ;
}

float   Fixed:: toFloat(void) const
{
    return ((float)(this->fixedPointValue) / (float) (1 << fractionalBits));
}

int Fixed:: toInt(void) const
{
    return (this->fixedPointValue >> fractionalBits);
}

Fixed   Fixed:: operator+(Fixed const &a) const
{
    return (this->toFloat() + a.toFloat());
}

Fixed   Fixed:: operator-(Fixed const &a) const
{
    return (this->toFloat() - a.toFloat());
}

Fixed   Fixed:: operator*(Fixed const &a) const
{
    return (this->toFloat() * a.toFloat());
}

Fixed   Fixed:: operator/(Fixed const &a) const
{
    return (this->toFloat() / a.toFloat());
}

bool   Fixed:: operator>(Fixed const &a) const
{
   return (this->fixedPointValue > a.getRawBits());
}

bool   Fixed:: operator<(Fixed const &a) const
{
   return (this->fixedPointValue < a.getRawBits());
}

bool   Fixed:: operator>=(Fixed const &a) const
{
   return (this->fixedPointValue >= a.getRawBits());
}

bool   Fixed:: operator<=(Fixed const &a) const
{
   return (this->fixedPointValue <= a.getRawBits());
}

bool   Fixed:: operator==(Fixed const &a) const
{
   return (this->fixedPointValue == a.getRawBits());
}

bool   Fixed:: operator!=(Fixed const &a) const
{
   return (this->fixedPointValue != a.getRawBits());
}

Fixed const  &Fixed:: min(Fixed const &a, Fixed const &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed    &Fixed:: min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed const  &Fixed:: max(Fixed const &a, Fixed const &b)
{
    if (a > b)
        return a;
    return b;
}

Fixed    &Fixed:: max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

Fixed   Fixed:: operator++()
{
    this->fixedPointValue++;
    return (*this);
}

Fixed   Fixed:: operator++(int)
{
    Fixed   temp;
    temp = *this;

    this->fixedPointValue++;
    return (temp);
}

Fixed   Fixed:: operator--()
{
    this->fixedPointValue--;
    return (*this);
}

Fixed   Fixed:: operator--(int)
{
    Fixed   temp;
    temp = *this;

    this->fixedPointValue--;
    return (*this);
}

std::ostream & operator<<(std::ostream& os, Fixed const &obj)
{
    os << obj.toFloat();
    return (os);
}