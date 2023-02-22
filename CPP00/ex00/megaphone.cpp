/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:13:35 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 12:16:54 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac <= 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return 0;
    }
    while (i < ac)
    {
        j = 0;
        while (av[i][j] != '\0')
            std::cout << (char)toupper(av[i][j++]);
        i++;
    }
    std::cout << std::endl;
    return 0;
}
