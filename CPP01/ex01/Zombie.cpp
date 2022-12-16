/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:26:57 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/14 12:31:02 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie:: Zombie(void)
{
	std::cout << "default constructor is called" << std::endl;
	return ;
}

Zombie:: Zombie(std::string name)
{
	std::cout << "name constructor is called" << std::endl;
	this->name = name;
}

Zombie:: ~Zombie(void)
{
	std::cout << "destructor is called with zombie name: ";
	std::cout << this->name << std::endl;
	return ;
}

void	Zombie:: putName(std::string zombieName)
{
	    this->name = zombieName;
}

void	Zombie::announce(void)
{
	std::cout << this->name << ":";
	std::cout << " BraiiiiiiinnnzzzZ..." <<std::endl;
}