/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:51 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:06:42 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>

class Animal
{
    public:
            Animal(void);
            void operator=(Animal const &obj);
            Animal(Animal const &obj);
            virtual ~Animal(void);
            virtual void makeSound(void) const;
            std::string getType(void) const;

    protected:
            std::string type;
};
#endif