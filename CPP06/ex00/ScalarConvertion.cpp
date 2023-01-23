/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:05 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/23 13:34:02 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

Convert:: Convert(void)
{
    std::cout << GREEN << "Default constructor is called." << RESET << std::endl;
}

Convert:: Convert(std::string _input)
{
    std::cout << GREEN << "Convert constructor for " << this->getInput() << " is called." << RESET << std::endl;
}

Convert:: Convert(Convert const &obj)
{
    std::cout << YELLOW << "Convert copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Convert:: ~Convert(void)
{
    std::cout << RED << "Convert destructor is called." << RESET << std::endl;
    return ;
}

Convert & Convert:: operator=(Convert const &obj)
{
    std::cout << YELLOW << "Convert copy assignment operator is called." << RESET << std::endl;
    if (this == &obj)
        return *this;
    this->_type = obj.getType();
    this->_int = obj.getInt();
    this->_double = obj.getDouble();
    this->_char = obj.getChar();
    this->_float = obj.getFloat();
        return *this;
}

// Getters
std::string Convert:: getInput() const
{
    return this->_input;
}

int Convert:: getType() const
{
    return this->_type;
}

char Convert:: getChar() const
{
    return this->_char;
}

int Convert:: getInt() const
{
    return this->_int;
}

float Convert:: getFloat() const
{
    return this->_float;
}

double Convert:: getDouble() const
{
    return this->_double;
}

// *convert from int, char, float, double
// handle/check input, pseudo literals, *numeric limits
// exceptions
// display output