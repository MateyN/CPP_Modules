/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:44 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 09:42:09 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) 
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "Tests given in the subject" << std::endl;
    std::cout << std::endl;

    std::cout << a << std::endl;
    std::cout << ++a << std::endl; // 1 / 2^8 = 0.00390625
    std::cout << a << std::endl; // a = 0.00390625
    std::cout << a++ << std::endl; // a++ returns the original value of a before incrementing it
    std::cout << a << std::endl; // 0.00390625 * 2 = 0.0078125

    std::cout << b << std::endl; // 10.1, then toFloat is called and is converted to floating point, which gives
                                 // the result of 10.1016 since lack of precision.
    
    std::cout << Fixed::max(a, b) << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "================================" << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "[ pre-increment ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "[ post-increment ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << "[ pre-decrement ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << --a << std::endl;
    std::cout << "[ post-decrement ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << a-- << std::endl;
    std::cout << a << std::endl;
    std::cout << "[ pre-increment ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << "[ post-increment ]" << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;

    std::cout << "[ max ]" << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    std::cout << "[ min ]" << std::endl;
    std::cout << Fixed::min(a, b) << std::endl;

    std::cout << "[ Plus ]" << std::endl;
    std::cout << a + b << std::endl;

    std::cout << "[ Minus ]" << std::endl;
    std::cout << a - b << std::endl;

    std::cout << "[ Multi ]" << std::endl;
    std::cout << a * b << std::endl;

    std::cout << "[ Div ]" << std::endl;
    std::cout << a / a << std::endl;

    return 0;
}