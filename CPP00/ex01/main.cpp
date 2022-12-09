/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:10 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/09 13:48:23 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

int userInput(Contact *newMember)
{
    std::string buff;
    std::string entries[5] = {"Enter FirstName: ",
        "Enter LastName: ",
        "Enter NickName: ",
        "Enter PhoneNumber: ",
        "Enter DarkestSecret: "};
    int i;

    i = 0;
    while (i < 5)
    {
        std::cout << BOLDYELLOW << entries[i] << RESET << std::endl;
        if (std::getline(std::cin, buff))
        {
            if (buff.size())
            {
                newMember->update(buff, i);
                i++;
            }
            else
                std::cout << BOLDRED << "Entry is empty" << RESET << std::endl;
        }
        else
            return -1;
    }
    return 0;
}

int main()
{
    std::string buff;
    Phonebook   book;
    Contact     newMember;

    std::cout << BOLDGREEN << "Please enter one of the following: ADD, SEARCH or EXIT" << RESET << std::endl;
    while (std::getline(std::cin, buff))
    {
        if (!buff.compare("ADD"))
        {
            if (userInput(&newMember) < 0)
                return 0;
            book.addContact(newMember);
        }
        else if (!buff.compare("SEARCH"))
        {
            book.displayAll();
            std::cout << BOLDCYAN << "Enter index" << RESET << std::endl;
            std::getline(std::cin, buff);
            book.searchContact(buff);
        }
        else if (!buff.compare("EXIT"))
            return 0;
        else
            std::cout << BOLDRED << "Invalid entry, please try again" << RESET <<std::endl;
        std::cout << BOLDGREEN << "Please enter one of the following: ADD, SEARCH or EXIT" << RESET << std::endl;
    }
    return 0;
}
