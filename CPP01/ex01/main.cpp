/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 11:26:52 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/21 09:29:23 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main(void)
{
    Zombie  *tab = zombieHorde(10, "Zombie");

    for (int i = 0; i < 10; i++)
        tab->announce();
        delete [] tab;
}