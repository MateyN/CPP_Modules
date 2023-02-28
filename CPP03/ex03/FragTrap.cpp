/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:45:30 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 13:45:48 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap:: FragTrap(void) : ClapTrap()
{
    std::cout << YELLOW << this->Name << " FragTrap constructor is called." << RESET << std::endl;
    this->Name = "";
    this->Hit = 100;
    this->Energy = 100;
    this->attackDamage = 30;
    return ;
}

FragTrap:: FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << YELLOW << this->Name << " FragTrap constructor is called." << RESET << std::endl;
    this->Name = name;
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
    this->Name = obj.Name;
    this->Hit = obj.Hit;
    this->Energy = obj.Energy;
    this->attackDamage = obj.attackDamage;
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