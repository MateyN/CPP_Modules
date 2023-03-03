/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:21:22 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/03 10:15:47 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[1m\033[32m"
#define RED     "\033[1m\033[31m"
#define YELLOW  "\033[1m\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>

/*
To avoid preventive allocation,
we allocate memory for the exact number of elements we need at the time of creation of the array, 
this is achieved by using the new[] operator to allocate memory for an array of size _size,
where _size is the exact number of elements needed.
*/
template<typename T>
class Array
{
    public:
            Array(void) : array(new T[0]), _size(0) // default constructor, initializes an empty array with size 0
            {
                this->array = new T[this->_size]; // dynamically allocates an array of size 0
            }
            Array(unsigned int n) : array(new T[n]), _size(n) // constructor that initializes an array with a given size n
            {
                this->array = new T[this->_size]; // dynamically allocates an array of size n
            }
            Array & operator=(Array const &obj) // copy assignment operator, copies the elements of the argument array into this array
            {
                if (this->array != NULL) // check if memory has already been allocated
                    delete [] this->array; // deletes the previously allocated memory for this array
                if (obj.size() != 0) // if the argument array is not empty
                {
                    this->_size = obj.size(); // update the size of this array to match the argument array
                    this->array = new T[this->_size]; // allocate memory for this array
                    for (unsigned int i = 0; i < this->size(); i++) // loop through the elements of the argument array
                        this->array[i] = obj.array[i]; // copy each element into this array
                }
                return *this;
            }
            Array(Array const &obj) : _size(obj.size()) // copy constructor, creates a new array that is a copy of the argument array
            {
                this->array = NULL; // initialize the array pointer to NULL
                *this = obj; // call the copy assignment operator to copy the elements of the argument array into this array
            }
            ~Array(void)
            {
                delete [] this->array; // frees the dynamically allocated memory for the array
            }

            T & operator[](unsigned int i) // subscript operator, returns a reference to the i-th element of the array
            {
                if (i >= this->_size || this->array == NULL) // if the index is out of range or the array is empty
                {
                    std::cout << "Index: " << i << std::endl;
                    throw std::out_of_range("Index out of range"); // throw an out of range exception
                }
                return this->array[i]; // return a reference to the i-th element of the array
            }

            unsigned int    size() const // method that returns the size of the array
            {
                return this->_size;
            }

    private:
            T               *array; // pointer to the dynamically allocated memory for the array
            unsigned int    _size; // size of the array
};

#endif