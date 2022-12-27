/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:01:22 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/22 10:41:40 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filestream.hpp"

Filestream:: Filestream(void)
{
    return ;
}

Filestream:: ~Filestream(void)
{
    return ;
}

int Filestream:: replaceFile(std::string fileName, std::string s1, std::string s2)
{
    std::ifstream   ifs(fileName);
    std::string     newFile(fileName);
    std::string     buff;

    newFile += ".replace";
    std::ofstream   ofs(newFile);
    while (getline(ifs, buff))
    {
        if (buff.compare(s1) == 0)
            ofs << s2 << std::endl;
        else
            ofs << buff << std::endl;
    }
    ifs.close();
    ofs.close();
    return 0;
}