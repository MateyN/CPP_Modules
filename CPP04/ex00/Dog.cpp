/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:40:46 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:00:21 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog:: Dog(void)
{
    type = "Dog";
    std::cout << GREEN << "Dog constructor is called." << RESET << std::endl;
}

Dog:: Dog(Dog const &obj)
{
    std::cout << YELLOW << "Dog copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void Dog:: operator=(Dog const &obj)
{
    std::cout << YELLOW << "Dog copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
}

Dog:: ~Dog(void)
{
    std::cout << RED << "Dog destructor is called." << RESET << std::endl;
    return ;
}

void    Dog:: makeSound(void) const
{
    std::cout << BLUE << "Dog: Woof woof!" << RESET << std::endl;
}
