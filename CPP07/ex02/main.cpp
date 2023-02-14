/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:21:27 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/13 13:02:01 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	try
	{
		Array<char> empty;

		std::cout << std::endl;
		std::cout << "Default empty array constructor is called.";
		for (unsigned int i = 0; i < empty.size(); i++)
			std::cout << empty[i] << ", ";
		std::cout << "" << std::endl;

		Array<char> instanceChar(3);
		instanceChar[0] = 'A';
		instanceChar[1] = 'B';
		instanceChar[2] = 'C';
		// CHAR
		std::cout << GREEN << "Char array: " << RESET << "[ ";
		for (unsigned int i = 0; i < instanceChar.size(); i++)
			std::cout << instanceChar[i] << ", ";
		std::cout << "]" << std::endl;

		Array<int> instance(4);
		instance[0] = 1;
		instance[1] = 2;
		instance[2] = 3;
		instance[3] = 4;
		// INT 1
		std::cout << GREEN << "Int array 1: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance.size(); i++)
			std::cout << instance[i] << ", ";
		std::cout << "]" << std::endl;

		//INT 2
		Array<int> instance2(instance);
		std::cout << GREEN << "Int array 2: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance2.size(); i++)
			std::cout << instance2[i] << ", ";
		std::cout << "]" << std::endl;

		// INT 3
		Array<int> instance3;
		instance3 = instance;
		std::cout << GREEN << "Int array 3: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance3.size(); i++)
			std::cout << instance3[i] << ", ";
		std::cout << "]" << std::endl;

		// TEST -> Change of array
		std::cout << YELLOW << "Original array modified: " << RESET;

		instance[0] = 10;
		instance[1] = 20;
		instance[2] = 30;
		instance[3] = 40;

		for (unsigned int i = 0; i < instance.size(); i++)
			std::cout << BLUE << instance[i] << ", ";
		std::cout << "" << RESET << std::endl;

		std::cout << GREEN << "Int array 2: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance2.size(); i++)
			std::cout << instance2[i] << ", ";
		std::cout << "]" << std::endl;

		std::cout << GREEN << "Int array 3: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance3.size(); i++)
			std::cout << instance3[i] << ", ";
		std::cout << "]" << std::endl;

		// TEST -> Change of array
		std::cout << YELLOW << "The second array modified: " << RESET;
		instance2[0] = 100;
		instance2[1] = 200;
		instance2[2] = 300;
		instance2[3] = 400;
		for (unsigned int i = 0; i < instance2.size(); i++)
			std::cout << BLUE << instance2[i] << ", ";
		std::cout << "" << RESET << std::endl;

		// TEST -> Change of array
		std::cout << YELLOW << "The third array modified: " << RESET;
		instance3[0] = 1000;
		instance3[1] = 2000;
		instance3[2] = 3000;
		instance3[3] = 4000;
		for (unsigned int i = 0; i < instance3.size(); i++)
			std::cout << BLUE << instance3[i] << ", ";
		std::cout << "" << RESET << std::endl;

		// TEST -> Array 1 (should display the first change of the array)
		std::cout << GREEN << "Int array 1: " << RESET << "[ ";
		for (unsigned int i = 0; i < instance.size(); i++)
			std::cout << instance[i] << ", ";
		std::cout << "]" << RESET << std::endl;

		// TEST -> Exception when index out of bounds
		std::cout << "Int array 1 with index 8: ";
		std::cout << instance[8] << ", ";
	}

	catch(std::exception & e)
   	{
       	std::cout << RED << "Index is out of bounds!" << RESET << std::endl;
   	}
}