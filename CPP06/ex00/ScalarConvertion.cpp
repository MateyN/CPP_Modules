/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:05 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/02 10:38:15 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

ScalarConvertion::ScalarConvertion(void)
{
    std::cout << "ScalarConversion constructor is called." << std::endl;
}

ScalarConvertion::ScalarConvertion(ScalarConvertion const & obj)
{
    (void) obj;
    std::cout << "ScalarConversion copy constructor is called." << std::endl;
}

ScalarConvertion::~ScalarConvertion(void)
{
    std::cout << "ScalarConversion destructor is called." << std::endl;
}

ScalarConvertion ScalarConvertion::operator = (ScalarConvertion const & obj)
{
    (void) obj;
    std::cout << "ScalarConversion Copy assignment operator is called." << std::endl;
    return *this;
}

int findDecimal(const std::string & dbl)
{
    if (dbl.find('.') == std::string::npos) // If the string does not contain a decimal point, return 0.
        return 0;

    int decimalPlaces = 0;
    bool isFractionalPart = false;

    // Iterate through each character of the string after the decimal point
    for (std::size_t i = dbl.find('.') + 1; i < dbl.length(); ++i) {
        // If a non-digit character is found after the decimal point, break
        if (!std::isdigit(dbl[i]))
        break;

        // If the current character is a digit and not char
        // increment the number of decimal places
        if (std::isdigit(dbl[i]) && !isFractionalPart)
        ++decimalPlaces;
        // If the current character is a digit and found non-digit char,
        // set the isFractionalPart flag to true
        else if (std::isdigit(dbl[i]) && isFractionalPart)
        isFractionalPart = true;
    }
    return decimalPlaces;
}

/*
 inserts into the stream object the d value converted to string with fixed-point notation
 and with the specified precision number of digits after the decimal point.
 The std::fixed and std::setprecision() functions are used to set the precision and fixed flags of the stream.
 */
std::string convertDoubleToString(double value, int numDecimalPlaces)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(numDecimalPlaces) << value; //set fixed and precision flags, and convert double to string
    return stream.str();
}

std::string convertFloatToString(float value, int numDecimalPlaces)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(numDecimalPlaces) << value;
    return stream.str();
}

void ScalarConvertion::convert(std::string arg)
{
    if (arg == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    return;
  }

  if (arg == "+inff" || arg == "-inff")
  {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << arg << std::endl;
        std::cout << "double: " << arg.substr(0, 4) << std::endl;
    return;
  }

  if (arg == "+inf" || arg == "-inf")
  {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << arg << 'f' << std::endl;
    std::cout << "double: " << arg << std::endl;
    return;
  }

  if (findDecimal(arg) == 0)
  {
    if (arg[0] >= '0' && arg[0] <= '9')
    {
        int c = stoi(arg); // converts the arg into integer.
        if (std::isprint(c))
            std::cout << "char: '" << static_cast < char > (c) << "'" << std::endl; // casting the integer into a char
        else
            std::cout << "char: non displayable" << std::endl;
            std::cout << "int: " << c << std::endl;
            std::cout << "float: " << convertFloatToString(static_cast<float>(c), 0) << ".0f" << std::endl;
            std::cout << "double: " << convertDoubleToString(static_cast<double>(c), 0) << ".0" << std::endl;
      return;
    }
    char c = arg[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << convertFloatToString(static_cast<float>(c), 0) << 'f' << std::endl;
    std::cout << "double: " << convertDoubleToString(static_cast<double>(c), 0) << std::endl;
    return;
  }
  std::string str = arg;
  double argDouble = stod(str);
  int decimalDigits = findDecimal(str);

  if (convertDoubleToString(argDouble, decimalDigits) == str)
  {
    double d = argDouble;
    char c = static_cast <char>(d);
    std::cout << "char: '" << (std::isprint(c) ? c : '?') << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << convertFloatToString(static_cast<float>(d), decimalDigits) << "f" << std::endl;
    std::cout << "double: " << convertDoubleToString(d, decimalDigits) << std::endl;

    return;
  }
  std::string double_str = convertDoubleToString(stod(arg), findDecimal(arg));
  if (double_str + 'f' == arg)
  {
    float d = stof(arg);
    char c = static_cast<char>(d);
    if (std::isprint(c))
      std::cout << "char: '" << c << "'" << std::endl;
    else
      std::cout << "char: non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << convertFloatToString(static_cast<float>(d), findDecimal(arg)) << 'f' << std::endl;
    std::cout << "double: " << convertDoubleToString(static_cast<double>(d), findDecimal(arg)) << std::endl;
    return;
  }
}