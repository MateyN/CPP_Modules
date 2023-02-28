/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 09:32:04 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 12:52:10 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "FragTrap.hpp"
# include "ScavTrap.hpp"
# include <iostream>
# include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
public:
	    DiamondTrap(void);
    	DiamondTrap(const DiamondTrap &obj);
    	DiamondTrap(std::string name);

	    DiamondTrap	&operator=(const DiamondTrap &obj);

	    virtual ~DiamondTrap();

	    void	attack(const std::string &target);
	    void	whoAmI(void);

private:
        std::string Name;
};

#endif
