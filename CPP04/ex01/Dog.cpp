/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:40:46 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 11:37:58 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog:: Dog(void)
{
    type = "Dog";
    brain = new Brain();
    std::cout << GREEN << "Dog constructor is called." << RESET << std::endl;
}

Dog:: Dog(Dog const &obj)
{
    std::cout << YELLOW << "Dog copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Dog & Dog:: operator=(Dog const &obj)
{
    std::cout << YELLOW << "Dog copy assignment operator is called." << RESET << std::endl;
    type = obj.type;
    return *this;
}

Dog:: ~Dog(void)
{
    delete brain;
    std::cout << RED << "Dog destructor is called." << RESET << std::endl;
    return ;
}

void    Dog:: makeSound(void) const
{
    std::cout << BLUE << "Dog: Woof woof!" << RESET << std::endl;
}

void    Dog:: setDogIdea(int i, std::string idea)
{
    brain->setIdeas(i, idea);
}

void    Dog:: showDogIdea()
{
    brain->showIdeas();
}