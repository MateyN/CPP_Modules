/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:48:56 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 10:51:39 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConvertion.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Only one argument is required!" << std::endl;
		return (1);
	}
	std::string arg = av[1];
	ScalarConvertion::convert(arg);
}