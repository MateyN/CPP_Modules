/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:47:29 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 10:38:41 by mnikolov         ###   ########.fr       */
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

void ClapTrap::attack(const std::string& target)
{
    // Check if the ClapTrap has enough Energy and Hit points to attack
    if (this->Energy > 0 && this->Hit > 0)
    {
        // Create a new ClapTrap instance to attack the target
        ClapTrap instance(target);
        std::cout << GREEN << this->Name << " attacks " << target <<
        ", causing " << this->attackDamage << " points of damage!" << RESET << std::endl;
        instance.takeDamage(attackDamage); // Call the 'takeDamage' method of the new ClapTrap instance to deduct the damage caused
        this->Energy--; // Deduct 1 point of Energy from the attacking ClapTrap instance
        std::cout << GREEN << this->Name << " used 1 NRG pt and now has " << this->Energy << " NRG points left." << RESET << std::endl;
    }
    // If the ClapTrap doesn't have enough Energy or Hit points to attack, print a message indicating so
    else
        std::cout << this->Name << " doesn't have enough hit pts to attack" << std::endl;
    return ;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    // If the amount of damage received is less than or equal to the current hit points,
    // subtract the damage from the current hit points. Otherwise, set hit points to 0.
    if (this->Hit > static_cast<int>(amount)) // to fix compile error for different signs
        this->Hit -= amount;
    else
        this->Hit = 0;
    std::cout << GREEN << this->Name << " has taken damage of " << amount <<
        " points and now has: " << this->Hit << " hit points left" << RESET << std::endl;
    return;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    // Check if the ClapTrap has enough energy and hit points to be repaired
    if (this->Energy != 0 && this->Hit != 0)
    {
        this->Hit += amount; // Increase the ClapTrap's hit points by the given amount
        std::cout << GREEN << this->Name << " has been repaired with " << amount << " points and now has " <<
            this->Hit << " hit points left." << std::endl;
        if (this->Energy > 0)
        {
            --this->Energy;
        std::cout << this->Name << " used 1 NRG point and now has " << this->Energy << " NRG points left." << RESET << std::endl;
        }
        else
        {
            std::cout << this->Name << " doesn't have any energy left." << RESET << std::endl;
        }
    }
    else
    {
        std::cout << "Sorry, " << this->Name << " doesn't have enough hit points or energy to be repaired." << std::endl;
    }
    return;
}

// This operator<< overload function for the ClapTrap class enables an object of ClapTrap to be printed to an output stream.
// When called, it will write the string "ClapTrap: " followed by the name of the ClapTrap object to the output stream.
std::ostream &operator<<(std::ostream& os, ClapTrap const &obj) // It takes two arguments: a reference to an output stream and a constant reference to a ClapTrap object.
{
    os << "ClapTrap: " << obj.getName();
    return os;
}