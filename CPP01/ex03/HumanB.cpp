/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:51 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/24 11:04:05 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"
/*
Pointer to Weapon object is used,
which is NULL to indicate that the HumanB object does not have a Weapon
*/
HumanB:: HumanB(std::string _name, Weapon *weapon) : weapon(weapon), name(_name)
{
    std::cout << GREEN << "HumanB constructor is called" << RESET << std::endl;
    return ;
}

HumanB:: ~HumanB(void)
{
    std::cout << RED << "HumanB destructor is called" << RESET << std::endl;
    return ;
}

void    HumanB:: attack(void)
{
    if (this->weapon)
    {
        std::cout << this->name;
        std::cout << " attack with ";
        std::cout << this->weapon->getType() << std::endl;
    }
    else
    {
        std::cout << this->name;
        std::cout << YELLOW << " don't have a weapon!" << RESET << std::endl;
    }
}

void    HumanB:: setWeapon(Weapon &name)
{
    std::cout << "HumanB setting up a weapon" << std::endl;
    this->weapon = &name;
    return ;
}