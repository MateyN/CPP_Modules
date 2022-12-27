/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filestream.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 10:58:02 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/22 10:36:47 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILESTREAM_HPP
# define FILESTREAM_HPP

#include <iostream>
#include <fstream>

class Filestream
{
    public:
            Filestream(void);
            ~Filestream(void);

            int replaceFile(std::string fileName, std::string find, std::string _replace);
    private:
};
#endif