/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 11:21:19 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/30 12:41:09 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <cstring>
#include <stack>
#include <deque>

#define RED "\033[31m"
#define RESET "\033[0m"

int operations(int n1, int n2, char sign);
std::stack<int, std::deque<int> > ReversePolishNotation(char *av);

#endif