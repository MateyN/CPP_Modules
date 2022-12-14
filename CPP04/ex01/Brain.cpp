/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:06:12 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 11:33:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain:: Brain(void)
{
    std::cout << GREEN << "Brain constructor is called." << RESET << std::endl;
}

Brain:: Brain(Brain const &obj)
{
    std::cout << YELLOW << "Brain copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void Brain:: operator=(Brain const &obj)
{
    std::cout << YELLOW << "Brain copy assignment operator is called." << RESET << std::endl;
    for (int i = 0; i < 100; i++)
    ideas[i] = obj.ideas[i];
}

Brain:: ~Brain(void)
{
    std::cout << RED << "Brain destructor is called." << RESET << std::endl;
    return ;
}

void    Brain:: setIdeas(int i, std::string idea)
{
    if (i < 100)
    ideas[i] = idea;
}

void    Brain:: showIdeas(void)
{
    for (int i = 0; i < 100; i++)
    {
        if (ideas[i] != "")
        std::cout << ideas[i] << i + 1 << std::endl;
    }
}