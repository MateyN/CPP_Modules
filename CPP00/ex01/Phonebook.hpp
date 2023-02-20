/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:21 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/20 13:26:03 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <string>
#include <iostream>
#include "Contact.hpp"
#include <iomanip>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

class Phonebook
{
    public:
            Phonebook(void);
            ~Phonebook(void);

            void        addContact(Contact &newMember); // takes a Contact object by reference and adds it to the phonebook.
            void        displayAll(void); // displays all contacts in the phonebook.
            void        searchContact(std::string idx); // takes an index and searches the phonebook for a matching contact.
            void        displayMember(int i); // displays the details of a single contact.
            void        displayStart(void); // displays the column headers for the contact list.
            std::string replace(std::string str); // replaces any non-printable characters in a string with a dot
            int         isDigit(std::string str);

    private:
            Contact list[8];
            int     pos; // keeps track of the current position in the phonebook.
            int     i; // keeps track of the number of contacts in the phonebook.
};

#endif
