/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:30 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 09:59:59 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal:: WrongAnimal(void) : type("None")
{
    std::cout << GREEN << "WrongAnimal constructor is called." << RESET << std::endl;
}

WrongAnimal:: WrongAnimal(WrongAnimal const &obj)
{
    std::cout << YELLOW << "WrongAnimal copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void WrongAnimal:: operator=(WrongAnimal const &obj)
{
    std::cout << YELLOW << "WrongAnimal copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
}

WrongAnimal:: ~WrongAnimal(void)
{
    std::cout << RED << "WrongAnimal destructor is called." << RESET << std::endl;
}

void    WrongAnimal:: makeSound(void) const
{
    std::cout << BLUE << "WrongAnimal sound!" << RESET << std::endl;
}

std::string WrongAnimal:: getType(void) const
{
    return (type);
}