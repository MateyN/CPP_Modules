/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:23:44 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 08:21:13 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void)
{
    Fixed a; // create a Fixed object a using default constructor
    Fixed b(a); // create a Fixed object b using copy constructor with `a` as argument
    Fixed c; // create a Fixed object c using default constructor
    
    c = b; // assign b to c using the copy assignment operator
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
    return 0; //  returns the raw value stored inside the object, which in this case is the internal number variable.
}