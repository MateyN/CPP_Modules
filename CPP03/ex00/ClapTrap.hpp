/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:46:13 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/03 10:37:01 by mnikolov         ###   ########.fr       */
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

    private:
            std::string Name;
            int         Hit;
            int         Energy;
            int         attackDamage;
};
        std::ostream & operator<<(std::ostream& os, ClapTrap const &obj);
#endif