/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:51 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/16 12:34:01 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanB.hpp"

HumanB:: HumanB(std::string _name)
{
    std::cout << RED << "HumanB constructor is called" << RESET << std::endl;
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