/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:01:20 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/04 12:12:03 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[36m"

#include <iostream>
#include <string>

class ClapTrap
{
    public:
            ClapTrap(void);
            ClapTrap(std::string str);
            ClapTrap & operator=(ClapTrap const &obj);
            ClapTrap(ClapTrap const &obj);
            ~ClapTrap(void);

            void attack(const std::string& target);
            void takeDamage(unsigned int amount);
            void beRepaired(unsigned int amount);

            std::string getName(void) const;
            int         getHit(void) const;
            int         getEnergy(void) const;
            int         getAttackDamage(void) const;

    protected:
            std::string Name;
            int         Hit;
            int         Energy;
            int         attackDamage;
};
        std::ostream & operator<<(std::ostream& os, ClapTrap const &obj);
#endif