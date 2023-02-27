/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:47:33 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/27 10:08:36 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap:: ScavTrap(void) : ClapTrap()
{
    std::cout << YELLOW << this->Name << " ScavTrap constructor is called with 100 HIT points and 50 NRG points" << RESET << std::endl;
    this->Name = "";
    this->Hit = 100;
    this->Energy = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap:: ScavTrap(std::string str) : ClapTrap(str)
{
    std::cout << YELLOW << this->Name << " ScavTrap constructor is called with 100 HIT points and 50 NRG points" << RESET << std::endl;
    this->Name = str;
    this->Hit = 100;
    this->Energy = 50;
    this->attackDamage = 20;
    return ;
}

ScavTrap:: ScavTrap(ScavTrap const &obj) : ClapTrap(obj)
{
    std::cout << YELLOW << " ScavTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

ScavTrap & ScavTrap:: operator=(ScavTrap const &obj)
{
    std::cout << YELLOW << " ScavTrap Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.getName();
    this->Hit = obj.getHit();
    this->Energy = obj.getEnergy();
    this->attackDamage = obj.getAttackDamage();
    return (*this);
}

ScavTrap:: ~ScavTrap(void)
{
    std::cout << RED << this->Name << " ScavTrap destructor is called" << RESET << std::endl;
    return ;
}

void    ScavTrap:: attack(const std::string& target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        //ScavTrap instance(target);
        std::cout << GREEN << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        //instance.takeDamage(attackDamage);
        this->Energy--;
        std::cout << GREEN << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    else
        std::cout << GREEN << this->Name << " doesn't have enough hit pts to attack" << RESET << std::endl;
    return ;
}

void    ScavTrap:: guardGate(void)
{
    std::cout << BLUE << this->Name << " is now in Gate keeper mode." << RESET << std::endl;
    return ;
}