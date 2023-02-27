/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:47:29 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/27 10:18:59 by mnikolov         ###   ########.fr       */
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
    std::cout << YELLOW << "ClapTrap constructor is called with 10 HIT pts and 10 NRG pts" << RESET << std::endl;
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
    std::cout << RED << "Default destructor is called" << RESET << std::endl;
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
        std::cout << GREEN << "ClapTrap " << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        this->Energy--;
        std::cout << GREEN  << "ClapTrap " << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    else
        std::cout << GREEN << "ClapTrap " << this->Name << " doesn't have enough hit pts to attack" << RESET << std::endl;
    return ;
}

void    ClapTrap:: takeDamage(unsigned int amount)
{
    if (this->Hit > static_cast<int>(amount)) // to fix compile error for different signs
        this->Hit -= amount;
   else
        this->Hit = 0;
        std::cout << GREEN  << "ClapTrap " << this->Name << " has taken damage of " << amount <<
        " points and now has: " << this->Hit << " hit points left" << RESET << std::endl;
        
        return ;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    // Check if the ClapTrap has enough energy and hit points to be repaired
        if (this->Energy > 0 && this->Hit > 0 && this->Hit + static_cast<int>(amount) <= 10)
	{
		this->Hit += amount;
		std::cout << "ClapTrap " << this->Name << " repaired itself and gained " << amount << " of hit points, he now has " << this->Hit << "hit points." << std::endl;
		this->Energy--;
	}
	else if (this->Energy == 0)
		std::cout << "ClapTrap " << this->Name << " is not able to repair itself, because he doesn't have enough energy points." << std::endl;
	else if (this->Hit == 0)
		std::cout << "ClapTrap " << this->Name << " is not able to repair itself, because he doesn't have enough hit points." << std::endl;
	else
		std::cout << "ClapTrap " << this->Name << " can't be repaired to have more than 10 hit points." << std::endl;
}

// This operator<< overload function for the ClapTrap class enables an object of ClapTrap to be printed to an output stream.
// When called, it will write the string "ClapTrap: " followed by the name of the ClapTrap object to the output stream.
std::ostream &operator<<(std::ostream& os, ClapTrap const &obj) // It takes two arguments: a reference to an output stream and a constant reference to a ClapTrap object.
{
    os << "ClapTrap: " << obj.getName();
    return os;
}