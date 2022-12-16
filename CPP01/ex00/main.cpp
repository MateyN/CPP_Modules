/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:29:55 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/14 11:02:55 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    std::cout << RED << "class TEST" << RESET << std::endl;
    Zombie test("Foo");
    test.announce();

    std::cout << RED << "newZombie TEST" << RESET << std::endl;
    Zombie *testNewZombie = newZombie("testNewZombie");
    testNewZombie->announce();
    delete testNewZombie;

    std::cout << RED << "randomChump TEST" << RESET << std::endl;
    randomChump("testRandomChump");

    return 0;
}