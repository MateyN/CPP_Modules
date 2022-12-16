/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:30:03 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/14 10:50:41 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie(void)
{
    std::cout << "default destructor is called" << std::endl;

    return ;
}

Zombie:: Zombie(std::string zombieName)
{
    this->name = zombieName;
    std::cout << "name constructor is called" << std::endl;
    return ;
}

Zombie:: ~Zombie(void)
{
    std::cout << "destructor is called with zombie name: ";
    std::cout << this->name << std::endl;

    return ;
}

void    Zombie::announce(void)
{
    std::cout << this->name << " : ";
    std::cout << "BraiiiiiiinnnzzzZ..." << std::endl;
}