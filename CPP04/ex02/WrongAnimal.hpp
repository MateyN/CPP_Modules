/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:33 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:01:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>

class   WrongAnimal
{
    public:
            WrongAnimal(void);
            void operator=(WrongAnimal const &obj);
            WrongAnimal(WrongAnimal const &obj);
            ~WrongAnimal(void);

            void        makeSound(void) const;
            std::string getType(void) const;

    protected:
            std::string type;
};

#endif