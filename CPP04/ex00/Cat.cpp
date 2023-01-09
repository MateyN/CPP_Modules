/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:53 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:00:27 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat:: Cat(void)
{
    type = "Cat";
    std::cout << GREEN << "Cat constructor is called." << RESET << std::endl;
}

Cat:: Cat(Cat const &obj)
{
    std::cout << YELLOW << "Cat copy constructor is called." << RESET << std::endl;
    *this = obj;
}

void Cat:: operator=(Cat const &obj)
{
    std::cout << YELLOW << "Cat copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
}

Cat:: ~Cat(void)
{
    std::cout << RED << "Cat destructor is called." << RESET << std::endl;
    return ;
}

void    Cat:: makeSound(void) const
{
    std::cout << BLUE << "Cat: Meow meow!" << RESET << std::endl;
}
