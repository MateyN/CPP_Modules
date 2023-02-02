/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:14:18 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/31 12:53:27 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data data2;
	data2.name = "Matt";
	data2.age = 42;
	data2.next = NULL;

	Data data;
	data.name = "Nikolov";
	data.age = 21;
	data.next = &data2;

    // Default struct

	std::cout << MAGENTA << "\nOriginal structs:" << RESET <<
				COLOR << "\nAddress: " << RESET << YELLOW << &data << RESET << 
				COLOR << "\nName: " << RESET << YELLOW << data.name << RESET <<
				COLOR << "\nAge: " << RESET << YELLOW << data.age << RESET <<
				COLOR << "\nNext address: " << RESET << YELLOW << data.next << RESET << std::endl;
                
	std::cout << COLOR << "\nAddress ptr2: " << RESET << YELLOW << &data2 << RESET <<
				COLOR << "\nName: " << RESET << YELLOW << data2.name << RESET <<
				COLOR << "\nAge: " << RESET << YELLOW << data2.age << RESET <<
				COLOR << "\nNext address: " << RESET << YELLOW <<  data2.next << RESET << std::endl;

    // Serialized class

	Serialization obj;

	Data *deserialize = obj.deserialize(obj.serialize(&data));

	std::cout << MAGENTA << "\nDeserialized structs:" << RESET <<
				COLOR << "\nAddress: " << RESET << YELLOW << deserialize << RESET << 
				COLOR << "\nName: " << RESET << YELLOW << deserialize->name << RESET <<
				COLOR << "\nAge: " << RESET << YELLOW << deserialize->age << RESET <<
				COLOR << "\nNext address: " << RESET << YELLOW << deserialize->next << RESET << std::endl;

	std::cout << COLOR << "\nAddress ptr2: " << RESET << YELLOW << &data2 << RESET <<
				COLOR << "\nName: " << RESET << YELLOW << data2.name << RESET <<
				COLOR << "\nAge: " << RESET << YELLOW << data2.age << RESET <<
				COLOR << "\nNext address: " << RESET << YELLOW <<  data2.next << RESET << std::endl;

	return (0);
}