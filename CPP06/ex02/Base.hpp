/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:19:08 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/01 14:31:51 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <cstdio>

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[36m"
#define COLOR   "\033[1m\033[38m"
#define MAGENTA "\033[1m\033[35m"

class   Base
{
    public:
            virtual ~Base(void);
};

class   A : public Base
{
};

class   B : public Base
{
};

class   C : public Base
{
};

#endif