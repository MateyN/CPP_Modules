/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:05 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/31 09:52:03 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

Convert:: Convert(void)
{
    std::cout << GREEN << "Default constructor is called." << RESET << std::endl;
}

Convert:: Convert(const std::string input) : _input(input)
{
    std::cout << GREEN << "Convert constructor for '" << this->getInput() << "' is called." << RESET << std::endl;
    this->_double = atof(this->getInput().c_str()); // Parses the string, interpreting its content as a floating point number and returns its value as a double.
    this->convertInput();
    this->displayOutput();
}

Convert:: Convert(Convert const &obj) : _input(obj.getInput())
{
    std::cout << YELLOW << "Convert copy constructor is called." << RESET << std::endl;
    *this = obj;
    this->displayOutput();
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
int Convert::checkInput() // catches, handle and prevents all kind of misalignments in the output
{
	if (this->getInput().compare("nan") == 0 || this->getInput().compare("+inf") == 0 ||
		this->getInput().compare("-inf") == 0 || this->getInput().compare("+inff") == 0 ||
		this->getInput().compare("-inff") == 0)
	{
		return (NAN_INF);
	}
	else if (this->getInput().size() == 1 &&
		(this->getInput()[0] == '+' || this->getInput()[0] == '-' || // prevents that the input of single digit integers get interpreted as a char
		this->getInput()[0] == 'f' || this->getInput()[0] == '.'))
	{
		return (CHAR);
	}
    else if (this->getInput().find_first_of("+-") != this->getInput().find_last_of("+-")) // prevents mixed + and -
        return (ERROR);
    else if (this->getInput().find_first_not_of("+-0123456789") == std::string::npos)
        return (INT);
    else if (this->getInput().find_first_not_of("+-0123456789.") == std::string::npos)
    {
        if (this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // finds 0..0
        isdigit(this->getInput()[this->getInput().find_first_of(".") + 1]) == false ||  // finds 0.
        this->getInput().find_first_of(".") == 0) // finds .0
            return (ERROR);
        else
            return (DOUBLE); 
    }
    else if (this->getInput().find_first_not_of("+-0123456789.f") == std::string::npos)
    {
        if (this->getInput().find_first_of("f") != this->getInput().find_last_of("f") || // finds 0.0ff
        this->getInput().find_first_of(".") != this->getInput().find_last_of(".") || // finds 0..0f
        this->getInput().find_first_of("f") - this->getInput().find_first_of(".") == 1 || // finds 0.f
        this->getInput().find_first_of(".") == 0 || this->getInput()[this->getInput().find_first_of("f") + 1] != '\0') // finds 0.0f0
            return (ERROR);
        else
            return (FLOAT);
    }
    else if ((this->getInput().size() == 1 && std::isprint(this->getInput()[0])) ||
		(this->getInput().size() == 1 && std::isalpha(this->getInput()[0])))
	{
		return (CHAR);
	}
    else
        return (ERROR);
}

void	Convert::convertInput(void) // used to select a function to be executed based on the run-time values.
{
	void (Convert:: *funcPTR[])(void) = {&Convert:: fromChar, &Convert:: fromInt, &Convert:: fromDouble, &Convert:: fromFloat};
    int types[] = {CHAR, INT, DOUBLE, FLOAT};
    this->_type = checkInput();
    if (this->getType() == NAN_INF)
        return ;
    int i;
    for (i = 0; i < 4; i++)
    {
        if (this->getType() == types[i])
        {
            (this->*funcPTR[i])();
            break;
        }
    }
    if (i == 4)
    throw Convert:: ErrorException();
}

void    Convert:: displayOutput(void) const
{
    //CHAR
    if (this->getType() != NAN_INF && this->getChar() >= 0)
    {
        if(isprint(this->getChar()))
            std::cout << COLOR << "char: " << RESET << "'" << this->getChar() << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }
    else
        std::cout << "char: impossible" << std::endl;
    //INT
    if (this->getType() != NAN_INF && this->getInt() >= std::numeric_limits<int>::min() && this->getInt() <= std::numeric_limits<int>::max())
    {
        std::cout << COLOR << "int: " << RESET << this->getInt() << std::endl;
    }
    else
        std::cout << "int: impossible" << std::endl;
    //FLOAT
    if (this->getType() != NAN_INF)
    {
        std::cout << COLOR << "float: " << RESET << this->getFloat();
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
        std::cout << COLOR << "double: " << RESET << this->getDouble();
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