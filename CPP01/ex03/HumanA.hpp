/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:19:44 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:12:44 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>
#include <string>

class   HumanA
{
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);

        void    attack(void);

    private:
            std::string name;
            Weapon      *weapon;
};

#endif