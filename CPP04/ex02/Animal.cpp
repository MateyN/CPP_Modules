/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:47 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/06 10:36:44 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal:: Animal(void) : type("None")
{
    std::cout << GREEN << "Animal constructor is called." << RESET << std::endl;
}

Animal:: Animal(Animal const &obj)
{
    std::cout << YELLOW << "Animal copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void Animal:: operator=(Animal const &obj)
{
    std::cout << YELLOW << "Animal copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
}

Animal:: ~Animal(void)
{
    std::cout << RED << "Animal destructor is called." << RESET << std::endl;
}

void    Animal:: makeSound(void) const
{
    std::cout << BLUE << "Animal sound!" << RESET << std::endl;
}

std::string Animal:: getType(void) const
{
    return (type);
}
