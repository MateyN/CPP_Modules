/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:29 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/21 13:43:54 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filestream.hpp"

int main(int argc, char **argv)
{
    Filestream obj;
    
    if (argc != 4)
        std::cout << "Invalid number of args!" << std::endl;
    else
        obj.Filestream::replaceFile(argv[1], argv[2], argv[3]);
        return 0;
}