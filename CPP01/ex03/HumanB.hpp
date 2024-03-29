/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:54 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/24 10:55:33 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

/*
Pointer to Weapon object is used,
which is NULL to indicate that the HumanB object does not have a Weapon
*/
class   HumanB
{
    public:
            HumanB(std::string _name, Weapon *weapon = NULL);
            ~HumanB(void);

            void    attack(void);
            void    setWeapon(Weapon &name);

    private:
            Weapon              *weapon;
            std::string   name;
};

#endif