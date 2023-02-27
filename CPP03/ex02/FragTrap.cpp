/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:45:30 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/27 10:05:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap:: FragTrap(void) : ClapTrap()
{
    std::cout << YELLOW << this->Name << " FragTrap constructor is called with 100 HIT points and 50 NRG points" << RESET << std::endl;
    this->Name = "";
    this->Hit = 100;
    this->Energy = 100;
    this->attackDamage = 30;
    return ;
}

FragTrap:: FragTrap(std::string str) : ClapTrap(str)
{
    std::cout << YELLOW << this->Name << " FragTrap constructor is called with 100 HIT points and 50 NRG points" << RESET << std::endl;
    this->Name = str;
    this->Hit = 100;
    this->Energy = 100;
    this->attackDamage = 30;
    return ;
}

FragTrap:: FragTrap(FragTrap const &obj) : ClapTrap(obj)
{
    std::cout << YELLOW << "FragTrap copy constructor is called" << RESET << std::endl;
    *this = obj;
}

FragTrap & FragTrap:: operator=(FragTrap const &obj)
{
    std::cout << YELLOW << "FragTrap Copy assignment operator called" << RESET << std::endl;
    this->Name = obj.getName();
    this->Hit = obj.getHit();
    this->Energy = obj.getEnergy();
    this->attackDamage = obj.getAttackDamage();
    return (*this);
}

FragTrap:: ~FragTrap(void)
{
    std::cout << RED << this->Name << " FragTrap destructor is called" << RESET << std::endl;
    return ;
}

void    FragTrap:: highFivesGuys(void)
{
    std::cout << BLUE << this->Name << " FragTrap requests for a high fives!" << RESET << std::endl;
    return ;
}