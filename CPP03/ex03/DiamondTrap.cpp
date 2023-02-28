/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:31:51 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 13:05:12 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
//#include "ClapTrap.hpp"
//#include <iostream>

DiamondTrap:: DiamondTrap(void) : ClapTrap("test")
{
    this->Name = "test";
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << YELLOW << " Default DiamondTrap constructor is called." << RESET << std::endl;
}

DiamondTrap:: DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
    std::cout << YELLOW << "DiamondTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

DiamondTrap:: DiamondTrap(std::string name) : ClapTrap(name + "_clap_name")
{
    this->Name = name;
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->attackDamage = FragTrap::attackDamage;
    std::cout << YELLOW << this->Name << " DiamondTrap constructor " << RESET << std::endl;
}

DiamondTrap:: ~DiamondTrap(void)
{
    std::cout << RED << this->Name << " DiamondTrap destructor is called" << RESET << std::endl;
    return ;
}

DiamondTrap & DiamondTrap:: operator=(DiamondTrap const &obj)
{
    std::cout << YELLOW << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.Name + "_clap_name";
    this->Hit = obj.Hit;
    this->Energy = obj.Energy;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap : " << this->Name << " and my ClapTrap name is : " << ClapTrap::Name << " ! " << std::endl;
}