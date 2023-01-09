/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:03 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 11:18:22 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    public:
            Dog(void);
            Dog & operator=(Dog const &obj);
            Dog(Dog const &obj);
            ~Dog(void);
            void    setDogIdea(int i, std::string idea);
            void    showDogIdea(void);
            void    makeSound(void) const;
            
    private:
            Brain*  brain;
};

#endif