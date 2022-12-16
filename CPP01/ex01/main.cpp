/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:26:52 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/15 10:22:20 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie  *tab = zombieHorde(1, "Zombie");

    for (int i = 0; i < 1; i++)
        tab->announce();
        delete [] tab;
}