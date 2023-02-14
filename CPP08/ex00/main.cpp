/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:21:27 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/14 19:35:28 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	try
	{
		std::cout << GREEN << "Using list" << RESET << std::endl;
		std::list<int>	lst(3);

		lst.push_back(1);
		lst.push_back(2);
		lst.push_back(3);

		std::cout << *easyfind(lst, 1) << std::endl;
		std::cout << *easyfind(lst, 2) << std::endl;
		std::cout << *easyfind(lst, 3) << std::endl;
		//std::cout << *easyfind(lst, 4) << std::endl;

		std::cout << GREEN << "Using vector" << RESET << std::endl;
		std::vector<int>	vec(3);
		vec.push_back(10);
		vec.push_back(20);
		vec.push_back(30);

		std::cout << *easyfind(vec, 10) << std::endl;
		std::cout << *easyfind(vec, 20) << std::endl;
		std::cout << *easyfind(vec, 30) << std::endl;
		//std::cout << *easyfind(vec, 40) << std::endl;
	}
	catch(std::exception & e)
	{
		std::cout << RED << "Not found!" << RESET << std::endl;
	}
}