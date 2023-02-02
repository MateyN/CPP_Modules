/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:14:26 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/31 12:22:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization:: Serialization(void)
{
    std::cout << GREEN << "Default Serialization constructor is called." << RESET << std::endl;
}

Serialization:: ~Serialization(void)
{
    std::cout << RED << "Default Serialization destructor is called." << RESET << std::endl;
    return ;
}

Serialization:: Serialization(Serialization const &obj)
{
    std::cout << YELLOW << "Serialization copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Serialization & Serialization:: operator=(Serialization const &obj)
{
    std::cout << YELLOW << "Serialization copy assignment operator is called." << RESET << std::endl;
    if (this == &obj)
        return *this;
    return *this;
}

uintptr_t   Serialization:: serialize(Data* ptr)
{
    return reinterpret_cast<std::uintptr_t>(ptr);
}

Data*   Serialization:: deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}