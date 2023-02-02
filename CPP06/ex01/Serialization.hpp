/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:14:35 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/31 10:27:36 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"
#define COLOR   "\033[1m\033[38m"
#define MAGENTA "\033[1m\033[35m"

typedef struct  Data
{
    std::string name;
    size_t      age;
    Data        *next;
}   Data;

class   Serialization
{
    public:
            Serialization(void);
            ~Serialization(void);
            Serialization(Serialization const &obj);
            Serialization & operator=(Serialization const &obj);

            uintptr_t   serialize(Data* ptr);
            Data*       deserialize(uintptr_t raw);
    private:
};

#endif