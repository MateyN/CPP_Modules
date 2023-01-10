/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:53 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/10 10:31:43 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat:: Cat(void)
{
    type = "Cat";
    brain = new Brain();
    std::cout << GREEN << "Cat constructor is called." << RESET << std::endl;
}

Cat:: Cat(Cat const &obj) : brain(NULL)
{
    std::cout << YELLOW << "Cat copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Cat & Cat:: operator=(Cat const &obj)
{
    if (this != &obj)
    {
        std::cout << YELLOW << "Cat copy assignment operator is called." << RESET << std::endl;
        type = obj.type;
        if (brain)
            delete brain;
        brain = new Brain(*(obj.brain));
    }
    return *this;
}

Cat:: ~Cat(void)
{
    delete brain;
    std::cout << RED << "Cat destructor is called." << RESET << std::endl;
    return ;
}

void    Cat:: makeSound(void) const
{
    std::cout << BLUE << "Cat: Meow meow!" << RESET << std::endl;
}

void    Cat:: setCatIdea(int i, std::string idea)
{
    brain->setIdeas(i, idea);
}

void    Cat:: showCatIdea()
{
    brain->showIdeas();
}