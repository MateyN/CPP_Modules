/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 10:06:26 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/09 10:53:10 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>

class Brain
{
    public:
            Brain(void);
            void operator=(Brain const &obj);
            Brain(Brain const &obj);
            ~Brain(void);
            

    private:
            std::string ideas[100];
};

#endif