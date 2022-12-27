/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:39 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/27 11:52:44 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl	_Harl;

	if (ac != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return -1;
	}
	_Harl.complain(av[1]);
	return 0;
}