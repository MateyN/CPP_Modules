/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:39 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/21 10:45:22 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA:: HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon)
{
    std::cout << RED << "HumanA constructor is called" << RESET << std::endl;
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