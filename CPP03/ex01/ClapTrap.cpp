/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:00:57 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 12:38:59 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap:: ClapTrap(void)
{
    std::cout << YELLOW "Default ClapTrap constructor is called with 10 HIT pts and 10 NRG pts" << RESET << std::endl;
    this->Name = "";
    this->Hit = 10;
    this->Energy = 10;
    this->attackDamage = 0;
    return ;
}

ClapTrap:: ClapTrap(std::string str)
{
    std::cout << YELLOW << this->Name << " ClapTrap constructor is called with 10 HIT pts and 10 NRG pts" << RESET << std::endl;
    this->Name = str;
    this->Hit = 10;
    this->Energy = 10;
    this->attackDamage = 0;
    return ;
}

ClapTrap:: ClapTrap(ClapTrap const &obj)
{
    std::cout << YELLOW << "ClapTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

ClapTrap & ClapTrap:: operator=(ClapTrap const &obj)
{
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.getName();
    this->Hit = obj.getHit();
    this->Energy = obj.getEnergy();
    this->attackDamage = obj.getAttackDamage();
    return (*this);
}

ClapTrap:: ~ClapTrap(void)
{
    std::cout << RED << this->Name << " ClapTrap destructor is called" << RESET << std::endl;
    return ;
}

std::string ClapTrap:: getName(void) const
{
    return this->Name;
}

int ClapTrap:: getHit(void) const
{
    return this->Hit;
}

int ClapTrap:: getEnergy(void) const
{
    return this->Energy;
}

int ClapTrap:: getAttackDamage(void) const
{
    return this->attackDamage;
}

void    ClapTrap:: attack(const std::string& target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        ClapTrap instance(target);
        std::cout << GREEN << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        instance.takeDamage(attackDamage);
        this->Energy--;
        std::cout << GREEN << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    else
        std::cout << this->Name << " doesn't have enough hit pts to attack" << std::endl;
    return ;
}

void    ClapTrap:: takeDamage(unsigned int amount)
{
    if (this->Hit > amount)
        this->Hit -= amount;
    else
        this->Hit = 0;
    std::cout << GREEN << this->Name << " has taken damage of " << amount <<
    " points and now has: " << this->Hit << " hit points left" << RESET << std::endl;
    return ;
}

void    ClapTrap:: beRepaired(unsigned int amount)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        this->Hit += amount;
        this->Energy--;
    		std::cout << GREEN << this->Name << " has been repaired with " << amount << " points and now has " <<
            this->Hit << " hit points left." << std::endl <<
            this->Name << " used 1 NRG point to repair and now has " << this->Energy << " NRG points left." << RESET << std::endl;
	}
	else
		std::cout << "Sorry, " << this->Name << " doesn't have enough hit points or energy to be repaired." << std::endl;
    return ;
}

std::ostream &operator<<(std::ostream& os, ClapTrap const &obj)
{
    os << "ClapTrap: " << obj.getName();
    return os;
}