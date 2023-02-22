/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:15:10 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/22 12:49:27 by mnikolov         ###   ########.fr       */
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
    // Declare three variables: buff -> which is used to store user input.
    // entries -> an array of five strings which contains prompts for user input,
    // i -> an integer that is used as a counter for the while loop.
    i = 0;
    while (i < 5)
    {
        std::cout << BOLDYELLOW << entries[i] << RESET << std::endl;
        if (std::getline(std::cin, buff))
        // Getting the user's input and stores it in the buff variable.
        // Checks if the input was successful and if so, proceeds with the next step.
        {
            if (buff.size())
            // Checks if the user input is not empty. 
            // If it's not empty, we update the corresponding attribute with the user input.
            // The i counter is then incremented. If the user input is empty, an error message is printed.
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
    std::string buff;      // declare a string variable "buff" to hold user input
    Phonebook book;        // create a Phonebook object "book"
    Contact newMember;     // create a Contact object "newMember"

    // Print a message to the user asking for input
    std::cout << BOLDGREEN << "Please enter one of the following: ADD, SEARCH or EXIT" << RESET << std::endl;
    
    // Keep looping until user enters "EXIT" or program is terminated
    while (std::getline(std::cin, buff))
    {
        // If user enters "ADD", prompt for new contact information and add it to the phonebook
        if (!buff.compare("ADD"))
        {
            // Call a function "userInput" to prompt user for contact information and store it in "newMember"
            if (userInput(&newMember) < 0)  // If "userInput" returns negative value, return 0 and terminate the program
                return 0;
            book.addContact(newMember);     // Add "newMember" to the "book" Phonebook object
        }
        // If user enters "SEARCH", display all contacts and prompt for an index to display
        else if (!buff.compare("SEARCH"))
        {
            book.displayAll();                                      // Display all contacts in the phonebook
            std::cout << BOLDCYAN << "Enter index" << RESET << std::endl; // Prompt user to enter an index
            std::getline(std::cin, buff);                            // Store user input in "buff" variable
            book.searchContact(buff);                               // Call function to search and display the contact at the index specified by the user
        }
        // If user enters "EXIT", return 0 and terminate the program
        else if (!buff.compare("EXIT"))
            return 0;
        // If user enters anything else, display an error message and prompt for input again
        else
            std::cout << BOLDRED << "Invalid entry, please try again" << RESET <<std::endl;

        // Print a message to the user asking for input again
        std::cout << BOLDGREEN << "Please enter one of the following: ADD, SEARCH or EXIT" << RESET << std::endl;
    }
    return 0;
}