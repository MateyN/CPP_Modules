/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 10:38:41 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/06 13:12:37 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void    display(T &t)
{
    std::cout << "Value: " << t << std::endl;
}

int main()
{   
    char        c[4] = {'A', 'B', 'C', 'D'};
    int         i[4] = {1, 2, 3, 4};
    float       f[4] = {3.14f, 65.315f, 24.423f, 28.937f};
    double      d[4] = {12.5, 42.2, 85.4, 36.8};
    std::string str[4] = {"Hello", "World!", "C Plus Plus", "It is fun!"};

    std::cout << GREEN << "CHAR" << RESET << std::endl;
        iter(c, 4, &display);
    std::cout << std::endl;

    std::cout << GREEN << "INT" << RESET << std::endl;
        iter(i, 4, &display);
    std::cout << std::endl;

    std::cout << GREEN << "FLOAT" << RESET << std::endl;
        iter(f, 4, &display);
    std::cout << std::endl;

    std::cout << GREEN << "DOUBLE" << RESET << std::endl;
        iter(d, 4, &display);
    std::cout << std::endl;

    std::cout << GREEN << "STRING" << RESET << std::endl;
        iter(str, 4, &display);
    std::cout << std::endl;

    return 0;
}