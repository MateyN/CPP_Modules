/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:47:26 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 10:59:45 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[36m"

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class ScavTrap: public ClapTrap
{
    public:
            ScavTrap(void);
            ScavTrap(std::string str);
            ScavTrap & operator=(ScavTrap const &obj);
            ScavTrap(ScavTrap const &obj);
            ~ScavTrap(void);

            void attack(const std::string& target);
            void guardGate(void);

};
#endif
