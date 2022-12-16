/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:20:04 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/16 12:23:34 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon:: Weapon(void)
{
    std::cout << RED << "default constructor is called" << RESET << std::endl;
    return ;
}

Weapon:: Weapon(std::string name)
{    
    std::cout << RED << "name constructor is called" << RESET << std::endl;
    return ;
}

Weapon:: ~Weapon(void)
{
    std::cout << RED << "default destructor is called" << RESET << std::endl;
    return ;
}

std::string &Weapon::getType(void)
{
    return (this->type);
}

void    Weapon::setType(const std::string &newType)
{
    std::cout << GREEN << "set type of weapon" << RESET << std::endl;
    this->type = newType;
    return ;
}