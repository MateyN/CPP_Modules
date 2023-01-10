/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:36 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:00:11 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat:: WrongCat(void)
{
    type = "WrongCat";
    std::cout << GREEN << "WrongCat constructor is called." << RESET << std::endl;
}

WrongCat:: WrongCat(WrongCat const &obj)
{
    std::cout << YELLOW << "WrongCat copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void WrongCat:: operator=(WrongCat const &obj)
{
    std::cout << YELLOW << "WrongCat copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
}

WrongCat:: ~WrongCat(void)
{
    std::cout << RED << "WrongCat destructor is called." << RESET << std::endl;
    return ;
}

void    WrongCat:: makeSound(void) const
{
    std::cout << BLUE << "WrongCat: Meow meow!" << RESET << std::endl;
}