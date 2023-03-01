/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 11:24:10 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/20 11:11:23 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    // Define a new type 'iter' that is an iterator for the underlying container type of the stack
    // The typedef declaration of the iterator type is moved outside of the class declaration 
    // to avoid C++11 compatibility issues.
    typedef typename std::stack<T>::container_type::iterator iter;

    // Default constructor
    MutantStack(void)
    {
        //std::cout << "Default MutantStack constructor is called." << std::endl;
    }

    // Copy constructor
    MutantStack(MutantStack const &obj)
    {
        // Use the assignment operator to copy the contents of the other object
        *this = obj;
    }

    // Assignment operator
    MutantStack &operator=(MutantStack const &obj)
    {
        // Assign the underlying container of the other object to this object's container
        this->c = obj.c;
        return *this;
    }

    // Destructor
    ~MutantStack(void)
    {
        //std::cout << "MutantStack destructor is called." << std::endl;
    }

    // Return an iterator to the beginning of the container
    iter begin(void)
    {
        return this->c.begin();
    }

    // Return an iterator to the end of the container
    iter end(void)
    {
        return this->c.end();
    }
};

#endif