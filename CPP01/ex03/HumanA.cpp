/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:15:17 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
/*
Using a reference in this case ensures that the Weapon object is always valid
and ready to be used by the HumanA object.
*/
HumanA:: HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
    // a reference is used to pass the Weapon object into the HumanA constructor,
    // but a pointer is used to store it as a member variable
    std::cout << GREEN << "HumanA constructor is called" << RESET << std::endl;
    return ;
}

HumanA:: ~HumanA(void)
{
    std::cout << RED << "HumanA destructor is called" << RESET << std::endl;
    return ;
}

void    HumanA:: attack(void)
{
    std::cout << this->name;
    std::cout << " attack with ";
    std::cout << this->weapon->getType() << std::endl;
}