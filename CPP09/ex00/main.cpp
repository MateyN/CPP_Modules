/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 09:45:00 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/20 15:08:22 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool    isTxt(const std::string &str)
{
    std::string ext = ".txt";
    if (str.size() < ext.size())
        return false;
    std::string fileTxt = str.substr(str.size() - ext.size());
    return fileTxt == ext;
}

void    readBtcInput(BitcoinExchange &btc, const std::string &filename)
{
    std::ifstream   in(filename);
    if (!in.is_open())
    {
        std::cerr << RED << "Error: cannot open file." << RESET << std::endl;
        return ;
    }
    std::string line;
    std::getline(in, line);
    if (line != "date | value")
    {
        std::cerr << RED << "Error: Invalid file format." << RESET << std::endl;
        return ;
    }
    while (std::getline(in, line))
    {
        if (btc.validateInput(line) != -1)
        btc.printBtc(line);
    }
    in.close();
}

int main(int ac, char **av)
{
    if (ac != 2 || !isTxt(av[1]))
    {
        std::cerr << RED << "Error: ./btc input.txt" << RESET << std::endl;
        return 1;
    }
    BitcoinExchange btc;
    if (!btc.readBtcData())
    {
        std::cerr << RED << "Error: data not found" << RESET << std::endl;
        return 1;
    }
    readBtcInput(btc, av[1]);
    return 0;
}