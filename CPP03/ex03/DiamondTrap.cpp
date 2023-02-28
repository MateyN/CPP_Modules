/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:31:51 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 14:13:15 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
//#include "ClapTrap.hpp"
//#include <iostream>

DiamondTrap:: DiamondTrap(void) : ClapTrap()
{
    std::cout << YELLOW << " Default DiamondTrap constructor is called." << RESET << std::endl;
    this->Name = "";
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap:: DiamondTrap(std::string name) : ClapTrap(name)
{
    std::cout << YELLOW << this->Name << " DiamondTrap constructor called." << RESET << std::endl;
    this->Name = name;
    ClapTrap::Name = name + "_clap_name";
    this->Hit = FragTrap::Hit;
    this->Energy = ScavTrap::Energy;
    this->attackDamage = FragTrap::attackDamage;
}

DiamondTrap:: DiamondTrap(DiamondTrap const &obj) : ClapTrap(obj)
{
    std::cout << YELLOW << "DiamondTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

DiamondTrap & DiamondTrap:: operator=(DiamondTrap const &obj)
{
    std::cout << YELLOW << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.Name;
    this->Hit = obj.Hit;
    this->Energy = obj.Energy;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

DiamondTrap:: ~DiamondTrap(void)
{
    std::cout << RED << this->Name << " DiamondTrap destructor is called" << RESET << std::endl;
    return ;
}

void    DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void    DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap : " << this->Name << " and my ClapTrap name is : " << ClapTrap::Name << " ! " << std::endl;
}