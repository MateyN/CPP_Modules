/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:00:57 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 13:53:47 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap:: ClapTrap(void) : Name(""), Hit(10), Energy(10), attackDamage(0)
{
    std::cout << YELLOW "Default ClapTrap constructor is called." << RESET << std::endl;
}

ClapTrap:: ClapTrap(ClapTrap const &obj)
{
    std::cout << YELLOW << "ClapTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

ClapTrap:: ClapTrap(std::string name) : Name(name), Hit(10), Energy(10), attackDamage(0)
{
    std::cout << YELLOW << this->Name << " ClapTrap constructor is called." << RESET << std::endl;
}

ClapTrap:: ~ClapTrap(void)
{
    std::cout << RED << this->Name << " ClapTrap destructor is called" << RESET << std::endl;
    return ;
}

ClapTrap & ClapTrap:: operator=(ClapTrap const &obj)
{
    std::cout << YELLOW << "Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.Name;
    this->Hit = obj.Hit;
    this->Energy = obj.Energy;
    this->attackDamage = obj.attackDamage;
    return (*this);
}

void    ClapTrap:: attack(const std::string& target)
{
    if (this->Energy > 0 && this->Hit > 0)
    {
        std::cout << GREEN << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        this->Energy--;
        std::cout << GREEN << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    else
        std::cout << this->Name << " doesn't have enough hit pts to attack" << std::endl;
    return ;
}

void    ClapTrap:: takeDamage(unsigned int amount)
{
    if (this->Hit > static_cast<int>(amount)) // to fix compile error for different signs
        this->Hit -= amount;
    else
        this->Hit = 0;
    std::cout << GREEN << this->Name << " has taken damage of " << amount <<
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
/*
std::ostream &operator<<(std::ostream& os, ClapTrap const &obj)
{
    os << "ClapTrap: " << obj.getName();
    return os;
}
*/