/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:30 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/24 13:28:33 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int operations(int n1, int n2, char sign)
{
    switch(sign)
    {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
    }
    return 0;
}

std::stack<int, std::vector<int> > ReversePolishNotation(char *av)
{
    std::stack<int, std::vector<int> > stack;
    int i = 0;
    int tmp;
    while (av[i])
    {
        if (strchr("0123456789", av[i]) && av[i + 1] == ' ')
        stack.push(av[i] - '0');
        else if (strchr("+-*/", av[i]) && (av[i + 1] == ' ' \
            || av[i + 1] == 0) && stack.size() > 1)
        {
            tmp = stack.top();
            stack.pop();
            stack.top() = operations(tmp, stack.top(), av[i]);
        }
        else if (av[i] != ' ')
        {
            std::cout << RED << "Error" << RESET << std::endl;
            while (stack.size() != 0)
            stack.pop();
            return stack;
        }
        i++;
    }
    if (stack.size() > 1)
    {
        std::cout << RED << "Error: invalid number of operations" << RESET << std::endl;
        while (stack.size() != 0)
        stack.pop();
    }
    return stack;
}