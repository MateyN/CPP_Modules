/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:20:04 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:17:46 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
/*
the weapon member variable will be initialized with the address of a Weapon object passed in as a reference,
but it can be reassigned to point to a different Weapon object if necessary.
*/
Weapon:: Weapon(void)
{
    std::cout << GREEN << "default constructor is called" << RESET << std::endl;
    return ;
}

Weapon:: Weapon(std::string name) : type(name)
{    
    std::cout << GREEN << "name constructor is called" << RESET << std::endl;
    return ;
}

Weapon:: ~Weapon(void)
{
    std::cout << RED << "default destructor is called" << RESET << std::endl;
    return ;
}

std::string &Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(const std::string &newType)
{
    std::cout << GREEN << "set type of weapon" << RESET << std::endl;
    this->type = newType;
    return ;
}