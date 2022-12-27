/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:36 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/22 12:49:25 by mnikolov         ###   ########.fr       */
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

void    Harl:: complain(std::string level)
{
    typedef void(Harl:: *fptr)(void);
    
    std::string lvls[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR"
    };

    fptr    complains[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    int i = 0;
    while (i < 4)
    {
        if (lvls[i] == level)
        {
            (this->*complains[i])();
            return ;
        }
        i++;
    }
    return ;
}