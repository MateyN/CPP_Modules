/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:05 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/26 11:16:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

Convert:: Convert(void)
{
    std::cout << GREEN << "Default constructor is called." << RESET << std::endl;
}

Convert:: Convert(const std::string input)
{
    std::cout << GREEN << "Convert constructor for " << this->getInput() << " is called." << RESET << std::endl;
    this->displayOutput();
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

char    Convert:: getChar() const
{
    return this->_char;
}

int Convert:: getInt() const
{
    return this->_int;
}

float   Convert:: getFloat() const
{
    return this->_float;
}

double  Convert:: getDouble() const
{
    return this->_double;
}

void    Convert:: fromChar(void)
{
    this->_char = static_cast<char>(this->getInput()[0]);
    this->_int = static_cast<int>(this->getChar());
    this->_float = static_cast<float>(this->getChar());
    this->_double = static_cast<double>(this->getChar());
}

void    Convert:: fromInt(void)
{
    this->_int = static_cast<int>(this->getDouble());
    this->_char = static_cast<char>(this->getInt());
    this->_float = static_cast<float>(this->getDouble());
}

void    Convert:: fromFloat(void)
{
    this->_float = static_cast<float>(getDouble());
    this->_char = static_cast<char>(getFloat());
    this->_int = static_cast<int>(getFloat());
}

void    Convert:: fromDouble(void)
{
    this->_char = static_cast<char>(getDouble());
    this->_int = static_cast<int>(getDouble());
    this->_float = static_cast<float>(getDouble());
}

void    Convert:: displayOutput(void) const
{
    //CHAR
    if (this->getType() != NAN_INF && this->getChar() >= 0)
    {
        if(isprint(this->getChar()))
            std::cout << "char: " << this->getChar() << " " << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    //INT
    if (this->getType() != NAN_INF && this->getInt() >= std::numeric_limits<int>::min() && this->getInt() <= std::numeric_limits<int>::max())
    {
        std::cout << "int: " << this->getInt() << std::endl;
    }
    else
        std::cout << "int: impossible" << std::endl;
    //FLOAT
    if (this->getType() != NAN_INF)
    {
        std::cout << "float: " << this->getFloat();
        if (this->getFloat() - this->getInt() == 0)
            std::cout << ".0f" << std::endl;
        else
            std::cout << "f" << std::endl;
    }
    else
    {
        if(this->getInput() == "nan" || this->getInput() == "nanf")
            std::cout << "float: nanf" << std::endl;
        else if(this->getInput()[0] == '+')
            std::cout << "float: +inff" << std::endl;
        else
            std::cout << "float: -inff" << std::endl;
    }
    //DOUBLE
    if (this->getType() != NAN_INF)
    {
        std::cout << "double: " << this->getDouble() << std::endl;
        if (this->getDouble() <= std::numeric_limits<int>::min() ||
            this->getDouble() >= std::numeric_limits<int>::max() || this->getDouble() - this->getInt() == 0)
            {
                std::cout << ".0" << std::endl;
            }
            else
                std::cout << std::endl;
    }
    else
    {
        if(this->getInput() == "nan" || this->getInput() == "nanf")
            std::cout << "double: nan" << std::endl;
        else if (this->getInput()[0] == '+')
            std::cout << "double: +inf" << std::endl;
        else
            std::cout << "double: -inf" << std::endl;
    }
}

// handle/check input, pseudo literals, *numeric limits
// exceptions
// 