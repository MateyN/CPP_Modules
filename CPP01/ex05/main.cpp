/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 10:50:39 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/27 10:05:34 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(void)
{
    Harl	_Harl;

	_Harl.complain("DEBUG");
	_Harl.complain("INFO");
	_Harl.complain("WARNING");
	_Harl.complain("ERROR");
	_Harl.complain("SOMETHING");
	return 0;
}
