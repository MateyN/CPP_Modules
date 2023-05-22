/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:44:56 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/20 15:20:40 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#define RED "\033[31m"
#define RESET "\033[0m"

#include <fstream>
#include <sstream>
#include <iostream>
#include <map>
#include <iomanip>

class   BitcoinExchange
{
    public:
            BitcoinExchange(void);
            BitcoinExchange(const BitcoinExchange &obj);
            ~BitcoinExchange(void);
            BitcoinExchange & operator=(const BitcoinExchange &obj);

            int     readBtcData();
            int     validateInput(std::string str) const;
            void    printBtc(std::string str) const;
            std::map<std::string, float>    getBtcData() const;

    private:
            std::map<std::string, float>    _data;

            float   stringToFloat(std::string str) const;
            long    stringToLong(std::string str) const;
            int     stringToInt(std::string str) const;
            bool    isDigit(const std::string &str) const;
};

#endif