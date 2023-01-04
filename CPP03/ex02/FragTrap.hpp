/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:45:34 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 13:16:22 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[36m"

#include <iostream>
#include <string>
#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
    public:
            FragTrap(void);
            FragTrap(std::string str);
            FragTrap & operator=(FragTrap const &obj);
            FragTrap(FragTrap const &obj);
            ~FragTrap(void);
            void highFivesGuys(void);
};
#endif