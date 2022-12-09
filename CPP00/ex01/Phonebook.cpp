/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:16 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/09 13:51:19 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook:: Phonebook(void)
{
    this->pos = 0;
    this->i = -1;
    return ;
}

Phonebook:: ~Phonebook(void)
{
    return ;
}

void    Phonebook::displayStart(void)
{
    std::cout << CYAN << std::setw(10) << "index" << RESET << "|";
    std::cout << CYAN << std::setw(10) << "firstname" << RESET << "|";
    std::cout << CYAN << std::setw(10) << "lastname" << RESET << "|";
    std::cout << CYAN << std::setw(10) << "nickname" << RESET << "|";
    std::cout << CYAN << std::setw(10) << "phone" << RESET << "|";
    std::cout << CYAN << std::setw(10) << "secret" << RESET << "|" << std::endl;
}

std::string Phonebook::replace(std::string str)
{
    if (str.size() > 10)
    {
        str.resize(9);
        str = str + '.';
    }
    return (str);
}

void    Phonebook::displayMember(int i)
{
    std::string str;

    str = this->list[i].getFirstName();
    std::cout << std::setw(10) << this->replace(str) << "|";

    str = this->list[i].getLastName();
    std::cout << std::setw(10) << this->replace(str) << "|";

    str = this->list[i].getNickName();
    std::cout << std::setw(10) << this->replace(str) << "|";

    str = this->list[i].getPhoneNumber();
    std::cout << std::setw(10) << this->replace(str) << "|";

    str = this->list[i].getDarkestSecret();
    std::cout << std::setw(10) << this->replace(str) << "|" << std::endl;
}

void    Phonebook::displayAll(void)
{
    int i;

    i = 0;
    this->displayStart();
    while (i < 8)
    {
        std::cout << MAGENTA << std::setw(10) << i << RESET << "|";
        this->displayMember(i);
        i++;
    }
}

int Phonebook::isDigit(std::string str)
{
    int i;

    while (i < str.size())
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

void    Phonebook::searchContact(std::string index)
{
    int idx;

    idx = atoi(index.c_str());
    if (index == "")
        std::cout << BOLDRED << "Empty field" << RESET << std::endl;
    else if (this->isDigit(index))
        std::cout << BOLDRED << "Not a valid digit" << RESET << std::endl;
    else if (idx > this->i)
        std::cout << BOLDRED << "Member doesn't exist" << RESET << std::endl;
    else
    {
        this->displayStart();
        std::cout << std::setw(10) << idx << "|";
        this->displayMember(idx);
    }
    return ;
}

void    Phonebook::addContact(Contact &newMember)
{
    if (this->i < 8)
            this->i++;
    if (this->pos > 7)
            this->pos = 0;
    this->list[this->pos] = newMember;
        this->pos++;
            return ;
}
