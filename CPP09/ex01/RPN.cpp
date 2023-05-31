/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:07:30 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/30 12:41:21 by mnikolov         ###   ########.fr       */
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

std::stack<int, std::deque<int> > ReversePolishNotation(char *av)
{
    std::stack<int, std::deque<int> > stack;
    int i = 0;
    int tmp;
    while (av[i])
    {
        if (strchr("0123456789", av[i]) && av[i + 1] == ' ') // checks if it's a digit and if there is a space after that
        stack.push(av[i] - '0'); //  convert the character representation of a digit to its corresponding numerical value
        else if (strchr("+-*/", av[i]) && (av[i + 1] == ' ' \
            || av[i + 1] == 0) && stack.size() > 1) // checks if it's a arithmetic operator, space or if there are at least 2 elements
        {
            tmp = stack.top(); // assign the top element to tmp
            stack.pop(); // pop out the second element
            stack.top() = operations(stack.top(), tmp, av[i]); // do the math and replace the result in the top element
        } // so now we have just the result after the calculation of the first two elements
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