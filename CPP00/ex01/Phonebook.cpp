/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:16 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 12:44:22 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook:: Phonebook(void)
{
    this->pos = 0;
    this->i = -1; // indicates an empty phone book.
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
    std::string str; // hold the values of various fields of the contact.

    str = this->list[i].getFirstName(); // get the first name of the contact and assigns the value to the str variable.
    std::cout << std::setw(10) << this->replace(str) << "|";
    //prints the first name in a field of width 10
    //and replaces any non-printable characters with a dot using replace
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
    //print the header of the phonebook display.
    //This header lists the columns that will be printed for each contact (i.e., first name, last name etc..)
    while (i < 8)
    {
        std::cout << MAGENTA << std::setw(10) << i << RESET << "|";
        this->displayMember(i);
        // print the details of the contact at the current index
        i++;
    }
}

int Phonebook::isDigit(std::string str)
{
    unsigned long int i = 0;

    while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return 1;
        i++;
    }
    return 0;
}

void Phonebook::searchContact(std::string index)
{
    int idx;
    // Declare an integer variable `idx` to store the numeric value of `index`.

    idx = atoi(index.c_str());
    // Convert the `index` string into an integer using the `atoi` function.

    if (index == "")
        std::cout << BOLDRED << "Empty field" << RESET << std::endl;
    // Check if the `index` string is empty, and print an error message if it is.

    else if (this->isDigit(index))
        std::cout << BOLDRED << "Not a valid digit" << RESET << std::endl;
    // Check if the `index` string contains non-numeric characters, and print an error message if it does.

    else if (idx > this->i)
        std::cout << BOLDRED << "Member doesn't exist" << RESET << std::endl;
    // Check if the `idx` value is greater than the number of contacts in the phone book, and print an error message if it does.

    else
    {
        this->displayStart();
        // Call the `displayStart` method to display the column headers.

        std::cout << std::setw(10) << idx << "|";
        // Print the index of the contact in the first column using the `idx` value.

        this->displayMember(idx);
        // Call the `displayMember` method to display the details of the contact with the given index.
    }
    return;
}
/*
The Phonebook::addContact method adds a new contact to the phone book array,
increments the count of the number of contacts in the phone book,
and updates the current position in the array to the next available slot.
If the end of the array is reached,
the current position is reset to the beginning of the array to overwrite the oldest contact.
*/
void Phonebook::addContact(Contact &newMember)
{
    if (this->i < 8)
        this->i++;
    // Check if the number of contacts in the phone book is less than 8, and increment the count if it is.
    if (this->pos > 7)
        this->pos = 0;
    // Check if the current position in the phone book array is greater than 7 (which means it has reached the end of the array), and reset it to 0 if it is.
    this->list[this->pos] = newMember;
    // Add the new contact to the current position in the phone book array.
    this->pos++;
    // Move the current position to the next available slot in the phone book array.
    return;
}
