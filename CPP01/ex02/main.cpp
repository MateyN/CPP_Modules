/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:00:47 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/21 09:42:34 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string *strPTR = &string;
    std::string &strREF = string;

    std::cout << "the address of the string: " << &string << std::endl;
    std::cout << "the address of the strPTR: " << strPTR << std::endl;
    std::cout << "the address of the strREF: " << &strREF << std::endl;

    std::cout << std::endl;

    std::cout << "the value of the string: " << string << std::endl;
    std::cout << "the value of the strPTR: " << *strPTR << std::endl;
    std::cout << "the value of the strREF: " << strREF << std::endl;
}