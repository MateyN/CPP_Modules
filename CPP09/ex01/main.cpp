/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:21 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/22 13:53:38 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << RED << "Error: Invalid number of arguments" << RESET << std::endl;
        return 0;
    }
    std::stack<int, std::vector<int> > stack = doRPN(av[1]);
    if (!stack.empty())
        std::cout << stack.top() << std::endl;
    return 0;
}