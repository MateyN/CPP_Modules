/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:57:29 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/23 10:32:57 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filestream.hpp"

int main(int argc, char **argv)
{
    Filestream obj;
    
    if (argc != 4)
        std::cout << "Invalid number of args: file, string 1 and string 2 needed." << std::endl;
    else
        obj.Filestream::replaceFile(argv[1], argv[2], argv[3]);
        return 0;
}