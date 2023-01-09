/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:30:08 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 09:59:17 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Animal.hpp"

void displayMessage(Animal obj)
{
    std::cout << "Type: " << obj.getType() << std::endl;
    obj.makeSound();
}

int main()
{
	{
        Animal  obj1;
		displayMessage(obj1);
		Dog obj2;
		displayMessage(obj2);
		Cat obj3;
		displayMessage(obj3);
	}
    std::cout << std::endl;
    {
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		std::cout << "Type: " << meta->getType() << std::endl;
		std::cout << "Type: " << j->getType() << std::endl;
		std::cout << "Type: " << i->getType() << std::endl;
		meta->makeSound();
		i->makeSound(); //will output the cat sound!
		j->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* meta = new WrongAnimal();
		const WrongAnimal* i = new WrongCat();
		const WrongCat* j = new WrongCat();
		std::cout << "Type: " << meta->getType() << std::endl;
		std::cout << "Type: " << j->getType() << std::endl;
		std::cout << "Type: " << i->getType() << std::endl;
		meta->makeSound();
		i->makeSound();
		j->makeSound();
		delete meta;
		delete i;
		delete j;
	}
	return 0;
}