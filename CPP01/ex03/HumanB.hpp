/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:54 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/21 10:45:01 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class   HumanB
{
    public:
            HumanB(std::string _name);
            ~HumanB(void);

            void    attack(void);
            void    setWeapon(Weapon &name);

    private:
            Weapon              *weapon;
            std::string   name;
};

#endif