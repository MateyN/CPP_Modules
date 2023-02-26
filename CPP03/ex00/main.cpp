/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:47:37 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 10:40:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap claptrap1("Claptrap 1");
    ClapTrap claptrap2("Claptrap 2");

    claptrap1.attack("target 1");
    claptrap1.beRepaired(3);
    claptrap1.attack("target 1");
    claptrap2.takeDamage(5);
    claptrap2.attack("target 2");
    claptrap2.attack("target 2");
    claptrap1.takeDamage(12);
    claptrap1.beRepaired(10);
    claptrap1.attack("target 1");
    claptrap2.attack("target 2");

    return 0;
}