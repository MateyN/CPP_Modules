/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:39 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:45:08 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl	_Harl; // creates an instance of the Harl class

	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return -1;
	}
	_Harl.complain(av[1]); // calling the complain method of the _Harl instance with the second command-line argument.
	return 0;
}