/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 11:38:40 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/30 12:30:09 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char** av)
{
    try
    {
        if (ac < 2)
            throw "Error: Invalid number of arguments";
        PmergeMe sort;
        sort.sortElements(av);
    }
    catch (const char* str)
    {
        std::cerr << str << '\n';
    }
}
