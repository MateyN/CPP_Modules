/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 12:29:57 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 07:58:32 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
/*
This function creates a new Zombie object with the specified name by calling the constructor that takes a std::string argument. 
The pointer to the newly created Zombie object is stored in a variable called res, and res is returned by the function.
The new operator is used to allocate memory for the new Zombie object on the heap.
The Zombie constructor is then called to initialize the object with the specified name. 
This dynamically allocated object will need to be explicitly deallocated later to avoid memory leaks.
*/
Zombie* newZombie(std::string name)
{
    Zombie *res = new Zombie(name);

    return (res);
}