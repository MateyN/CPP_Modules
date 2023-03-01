/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:25:00 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/20 12:11:48 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp" // Include the MutantStack class header
#include <list> // Include the std::list class header

int main()
{
    std::cout << "Test example from subject." << std::endl;
    MutantStack<int> mstack; // Create an instance of MutantStack<int>
    
    // Push two elements onto the stack
    mstack.push(5);
    mstack.push(17);
    
    std::cout << mstack.top() << std::endl; // Print the top value of the stack
    
    mstack.pop(); // Pop the top value off the stack
    
    std::cout << mstack.size() << std::endl;
    
    // Push several more elements onto the stack
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iter it = mstack.begin(); // Create an iterator pointing to the first element of the stack
    MutantStack<int>::iter ite = mstack.end(); // Create an iterator pointing to the end of the stack
    ++it; // Increment the iterator by 1 (now points to the second element of the stack)
    --it; // Decrement the iterator by 1 (now points to the first element of the stack)

    while (it != ite) // Loop while the iterator is not at the end of the stack
    {
        std::cout << *it << std::endl; // Print the value that the iterator is pointing to
        ++it; // Increment the iterator by 1
    }

    std::stack<int> s(mstack); // Create a standard stack object of type int, initialized with the MutantStack object
    
    std::cout << std::endl;
    std::cout << "Change the MutantStack with std::list" << std::endl;

    std::list<int> mlist; // Create a std::list object of type int
    
    // Push two elements onto the list
    mlist.push_back(5);
    mlist.push_back(17);

    std::cout << mlist.back() << std::endl; // Print the last value in the list

    mlist.pop_back(); // Remove the last value in the list

    std::cout << mlist.size() << std::endl;

    // Push several more elements onto the list
    mlist.push_back(3);
    mlist.push_back(5);
    mlist.push_back(737);
    //[...]
    mlist.push_back(0);

    std::list<int>::iterator itList = mlist.begin(); // Create an iterator pointing to the first element of the list
    std::list<int>::iterator iteList = mlist.end(); // Create an iterator pointing to the end of the list
    ++itList; // Increment the iterator by 1 (now points to the second element)
    --itList; // Decrement the iterator by 1 (now points back to the first element)

    while (itList != iteList)
    {
        std::cout << *itList << std::endl; // Print the value pointed to by the iterator
        ++itList; 
    }
    return 0;
}