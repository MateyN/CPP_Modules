/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:56 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/23 13:39:39 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << RED << "Only one argument is required!" << RESET << std::endl;
		return (1);
	}
	try
	{
		Convert convert(av[1]);
	}
	catch(const Convert::ErrorException & e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}