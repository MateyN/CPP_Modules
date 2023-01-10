/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:08 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 11:29:40 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"
#include "Brain.hpp"

#define BOLDMAGENTA "\033[1m\033[35m"
#define RESET   "\033[0m"

int main()
{
	{
		std::cout << BOLDMAGENTA << "TABS ASKED IN SUBJECT" << RESET << std::endl;
		Animal* tab[6];
		for (int i = 0; i < 3; i++)
			tab[i] = new Dog();
		for (int i = 3; i < 6; i++)
			tab[i] = new Cat();

		std::cout << std::endl;
		for (int i = 0; i < 6; i++)
			delete tab[i];
	}
	std::cout << std::endl;
	{
		std::cout << BOLDMAGENTA << "DEEP COPY CHECK" << RESET << std::endl;
		{
			Cat	instance;
			Cat	instance2(instance);
		}
		std::cout << std::endl;
		{
			Dog	retriever;
			{
				Dog labrador = retriever;
			}
		}
		std::cout << std::endl;
		{
			Dog retriever;
			Dog labrador;
			retriever = labrador;
		}
	}
	std::cout << std::endl;
	{
		std::cout << BOLDMAGENTA << "MAIN GIVEN IN SUBJECT" << RESET << std::endl;
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		delete j;//should not create a leak
		delete i;
	}
	std::cout << std::endl;
	{
		std::cout << BOLDMAGENTA << "MORE TESTS: BRAIN IDEAS" << RESET << std::endl;
		Dog retriever;
		retriever.setDogIdea(0, "Walk = ");
		retriever.setDogIdea(1, "Drink = ");
		retriever.showDogIdea();
		{
			Dog labrador;
			for (int i = 0; i < 100; i++)
				labrador.setDogIdea(i, "Eat = ");
			retriever = labrador;
		}
		retriever.showDogIdea();
	}
	return 0;
}