/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Filestream.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:01:22 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 08:30:20 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Filestream.hpp"
/*
ifstream is used to read data from a file,
and ofstream is used to write data to a new file that will contain the modified content of the original file.
* ifstream stands for "input file stream" and is used for reading data from a file,
while ofstream stands for "output file stream" and is used for writing data to a file.
*/
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
    std::ifstream   ifs(fileName); // creates an ifstream object called ifs and opens the file with the name specified in the fileName parameter.
    std::string     newFile(fileName); // creates a new string called newFile and initializes it to be the same as the fileName parameter
    std::string     buff; // Used to store the contents of each line in the input file

    newFile += ".replace";
    std::ofstream   ofs(newFile); // creates an ofstream object called ofs and opens the new file
    while (getline(ifs, buff)) // iterate through each line of the input file and perform a string comparison and replacement operation on each line.
    {
        if (buff.compare(s1) == 0) // checks if the line contains the string specified in the s1 parameter.
            ofs << s2 << std::endl; // writes the replacement string specified in the s2 parameter to the output file
        else
            ofs << buff << std::endl; // writes the original line to the output file if the line does not contain the string specified in s1
    }
    // closes both the input and output files
    ifs.close();
    ofs.close();
    return 0;
}