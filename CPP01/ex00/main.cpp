/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:29:55 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/24 10:08:43 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void    randomChump(std::string name);

int main(void)
{
    std::cout << RED << "class TEST" << RESET << std::endl;
    Zombie test("Foo"); // stack allocation
    test.announce();

    std::cout << RED << "newZombie TEST" << RESET << std::endl;
    Zombie *testNewZombie = newZombie("testNewZombie"); // heap allocation
    testNewZombie->announce();
    delete testNewZombie; // deallocated

    std::cout << RED << "randomChump TEST" << RESET << std::endl;
    randomChump("testRandomChump"); // stack allocation 

    return 0; // obj automatically destroyed by the compiler
}