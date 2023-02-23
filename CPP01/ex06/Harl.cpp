/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:36 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:43:20 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl:: Harl(void)
{
    return ;
}

Harl:: ~Harl(void)
{
    return ;
}

void    Harl:: debug(void)
{
    std::cout << RED << "[ DEBUG ]" << RESET << std::endl;
    std::cout << GREEN << "I love having extra sauce for my burger!" << RESET << std::endl;
    return ;
}

void    Harl:: info(void)
{
    std::cout << RED << "[ INFO ]" << RESET << std::endl;
    std::cout << GREEN << "You didn't put enough sauce on my burger!" << RESET << std::endl;
    return ;
}

void    Harl:: warning(void)
{
    std::cout << RED << "[ WARNING ]" << RESET << std::endl;
    std::cout << GREEN << "I think I deserve all the sauce for free!" << RESET << std::endl;
    return ;
}

void    Harl:: error(void)
{
    std::cout << RED << "[ ERROR ]" << RESET << std::endl;
    std::cout << GREEN << "This is unacceptable! I want to speak to the manager immediately!" << RESET << std::endl;
    return ;
}

void Harl::complain(std::string level)
{   
    std::string lvls[] = { // Define an array of levels
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    int i = 0;

    // Find the index of the given level in the levels array
    while (i < 4)
    {
        if (level == lvls[i])
            break ;
        i++;
    }
    
    switch (i) // Call the appropriate complain function based on the level using switch
    {
        case 0:
            this->debug(); // If level is DEBUG, call the debug function and then move to the INFO case
            i++;
        case 1:
            this->info(); // If level is INFO, call the info function and then move to the WARNING case an so on.
            i++;
        case 2:
            this->warning();
            i++;
        case 3:
            this->error();  // If level is ERROR, call the error function and break out of the switch statement
            break;
        default:
            std::cout << YELLOW << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
    }
    return;
}