/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:38 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/30 12:32:17 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed:: Fixed(void)
{
    this->number = 0;
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
    this->number = (a << storeBits);
}

Fixed:: Fixed(const float a)
{
    this->number = roundf(a * (1 << storeBits));
}

Fixed &	Fixed:: operator=(Fixed const &a)
{
    this->number = a.getRawBits();
    return (*this);
}

int Fixed:: getRawBits(void) const
{
    return (this->number);
}

void    Fixed:: setRawBits(int const raw)
{
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
   return (this->number > a.getRawBits());
}

bool   Fixed:: operator<(Fixed const &a) const
{
   return (this->number < a.getRawBits());
}

bool   Fixed:: operator>=(Fixed const &a) const
{
   return (this->number >= a.getRawBits());
}

bool   Fixed:: operator<=(Fixed const &a) const
{
   return (this->number <= a.getRawBits());
}

bool   Fixed:: operator==(Fixed const &a) const
{
   return (this->number == a.getRawBits());
}

bool   Fixed:: operator!=(Fixed const &a) const
{
   return (this->number != a.getRawBits());
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
    this->number++;
    return (*this);
}

Fixed   Fixed:: operator++(int)
{
    Fixed   temp;
    temp = *this;

    this->number++;
    return (temp);
}

Fixed   Fixed:: operator--()
{
    this->number--;
    return (*this);
}

Fixed   Fixed:: operator--(int)
{
    Fixed   temp;
    temp = *this;

    this->number--;
    return (*this);
}

std::ostream & operator<<(std::ostream& os, Fixed const &obj)
{
    os << obj.toFloat();
    return (os);
}