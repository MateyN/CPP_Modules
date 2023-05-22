/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:44:52 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/22 10:59:34 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange:: BitcoinExchange(void)
{
    return ;
}

BitcoinExchange:: BitcoinExchange(const BitcoinExchange &obj)
{
    this->_data = obj.getBtcData();
}

BitcoinExchange:: ~BitcoinExchange(void)
{
    return ;
}

BitcoinExchange & BitcoinExchange:: operator=(const BitcoinExchange &obj)
{
    this->_data = obj.getBtcData();
    return *this;
}

int BitcoinExchange:: readBtcData()
{
    std::ifstream   file("./data.csv");
    if (!file)
    {
        std::cerr << RED << "Error: cannot open file." << RESET << std::endl;
        return 0;
    }

    std::string line;
    std::string priceBtc;
    while (std::getline(file, line))
    {
        priceBtc = line.substr(line.find(",") + 1); // get the substr from the line, +1 to take the value after the comma.
        line.erase(4, 1).erase(6, 1).erase(8); // remove chars to get the correct date
        _data.insert(std::make_pair(line, stringToFloat(priceBtc))); // making pair (key is the line, and the value is
        // the converted BTC price to float)
    }
    file.close();
    return 1;
}

std::map<std::string, float> BitcoinExchange:: getBtcData() const
{
    return _data;
}

void    BitcoinExchange::printBtc(std::string str) const
{
    std::map<std::string, float>::const_iterator it = _data.end(); // using const iterator because not need to modify the map's elements.
    float   value = stringToFloat(str.substr(str.find(" | ")).erase(0,3)); // search for | and erase the first 3 chars from the substr

    str.erase(4,1).erase(6,1).erase(8);
    it = _data.find(str); // finds the iterator corresponding to the given date in the map
    if (it == _data.end())
    {
        it = _data.upper_bound(str);  // finds the iterator pointing to the first element greater than the given date
        if (it == _data.begin()) // If the iterator points to the first element or the map is empty
        {
            std::cerr << RED << "Error: no data available for this date." << RESET << std::endl;
            return;
        }
        --it; // moving the iterator to the previous element
    }
    float result = value * it->second;
    std::cout << str.insert(4, "-").insert(7, "-") << " => ";
    if (std::floor(value) == value)
        std::cout << std::setprecision(0) << std::fixed << value; // the correct and precise value
    else
        std::cout << std::setprecision(1) << std::fixed << value; // the correct and precise value for the 2nd part
    std::cout << " = ";
    if (static_cast<int>(result * 100) % 10 == 0) // checks whether to use precision of 1 or precision of 2 for the output
        std::cout << std::setprecision(1) << std::fixed << result; // output the first part with the correct numbers
    else
        std::cout << std::setprecision(2) << std::fixed << result; // output the seconnd part with the correct numbers
    std::cout << "\n";
}

int BitcoinExchange:: validateInput(std::string str) const
{
    // generating a temp string to avoid changes in the original string and to display the exact cause of error
    std::string tmp = str;
    if (str.find(" | ") == std::string::npos || str.size() < 14)
    {
        std::cout << RED << "Error: bad input => " << tmp << RESET << std::endl;
        return -1;
    }
    std::string value = str.substr(str.find(" | ") + 3);
    str.erase(str.find(" | "));
    if (str.size() != 10 || str[4] != '-' || str[7] != '-')
    {
        std::cout << RED << "Error: bad input => " << tmp << RESET << std::endl;
        return -1;
    }
    str.erase(4,1).erase(6,1);
    if (!isDigit(str))
    {
        std::cout << RED << "Error: bad input => " << tmp << RESET << std::endl;
        return -1;
    }
    int y = stringToInt(str.substr(0,4));
    int m = stringToInt(str.substr(4, 2));
    int d = stringToInt(str.substr(6,2));
    int m_list[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (y < 2009 || y > 2023 || m < 1 || m > 12 || d < 1 || d > m_list[m - 1])
    {
        std::cout << RED << "Error: bad input => " << tmp << RESET << std::endl;
        return -1;
    }
    float floatValue;
    try
    {
        floatValue = std::stof(value);
    }
    catch (const std::exception&)
    {
        std::cout << "Error: converting string to float" << std::endl;
        return -1;
    }
    if (floatValue <= 0.0f)
    {
        std::cout << RED << "Error: not a positive number" << RESET << std::endl;
        return -1;
    }
    if (floatValue > 1000.0f)
    {
        std::cout << RED << "Error: number too large." << RESET << std::endl;
        return -1;
    }
    return 1;
}

float   BitcoinExchange:: stringToFloat(std::string str) const
{
	std::stringstream ss;
	float res = 0.0;

	ss << str;
	ss >> res;
	return (res);
}

int BitcoinExchange:: stringToInt(std::string str) const
{
	std::stringstream ss;
	int res = 0;

	ss << str;
	ss >> res;
	return (res);
}

long    BitcoinExchange:: stringToLong(std::string str) const
{
	std::stringstream ss;
	long res = 0;

	ss << str;
	ss >> res;
	return (res);
}

bool    BitcoinExchange:: isDigit(const std::string &str) const
{
    for (std::string::const_iterator it = str.begin(); it != str.end(); ++it)
    {
        if (!std::isdigit(*it))
        {
            return false;
        }
    }
    return true;
}