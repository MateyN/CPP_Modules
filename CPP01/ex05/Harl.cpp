/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:36 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/25 12:09:28 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
/*
 Array "complains" of four function pointers that correspond to each of the recognized log levels.
 Each function pointer points to a member function of the Harl class that handles the specified log level.
 * loops through the lvls array and checks each string against the specified level.
 If a match is found, the function uses the corresponding function pointer in the complains array
 to call the appropriate member function on the current Harl instance.
*/
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
    typedef void (Harl::*fptr)(void); // fptr is defined as a pointer to a member function of the Harl class that takes no arguments and returns void. 

    std::string lvls[4] = { // defines an array of std::string objects named lvls. 
                            // The array contains four strings, each representing a log level.
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };
        // Array of function pointers. 
        // Each element of the array points to a member function of the Harl class that corresponds to a log level.
    fptr complains[4] = {
        &Harl::debug,   // complains[0]
        &Harl::info,    // complains[1]
        &Harl::warning, // complains[2]
        &Harl::error    // complains[3]
    };
    
    int i = 0;
    // iterate through the lvls array, comparing each string to the level argument passed to the complain method
    while (i < 4)
    {
        if (lvls[i] == level) // If the log level matches the specified level, call the corresponding log function
        {
            (this->*complains[i])(); // Use the function pointer to call the appropriate log function on the current Harl instance
            return;
        }
        i++;
    }
    return;
}