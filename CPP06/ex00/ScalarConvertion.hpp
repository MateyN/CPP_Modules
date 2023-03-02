/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:08 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/02 08:30:00 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTION_H
# define SCALARCONVERTION_H

# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>

class ScalarConvertion
{
	public:
		ScalarConvertion(void);
		ScalarConvertion(ScalarConvertion const & obj);
		ScalarConvertion operator=(ScalarConvertion const & obj);
        ~ScalarConvertion(void);

		static void convert(std::string str);
};

#endif