/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:21:22 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/13 12:49:07 by mnikolov         ###   ########.fr       */
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

template<typename T>
class Array
{
    public:
            Array(void) : _size(0), array(new T[0])
            {
                //std::cout << "Default Array constructor is called with size 0." << std::endl;
                this->array = new T[this->_size];
            }
            Array(unsigned int n) : _size(n), array(new T[n])
            {
                //std::cout << "Array constructor called with size" << _size << std::endl;
                this->array = new T[this->_size];
            }
            Array & operator=(Array const &obj)
            {
                if (this->array != NULL)
                    delete [] this->array;
                if (obj.size() != 0)
                {
                    this->_size = obj.size();
                    this->array = new T[this->_size];
                    for (unsigned int i = 0; i < this->size(); i++)
                        this->array[i] = obj.array[i];
                }
                return *this;
            }
            Array(Array const &obj) : _size(obj.size())
            {
                //std::cout << "Copy Array constructor called." << std::endl;
                this->array = NULL;
                *this = obj;
            }
            ~Array(void)
            {
                //std::cout << "Array destructor is called" << std::endl;
                delete [] this->array;
            }

            T & operator[](unsigned int i)
            {
                if (i >= this->_size || this->array == NULL)
                {
                    std::cout << "Index: " << i << std::endl;
                    throw std::exception();
                }
                return this->array[i];
            }
            
            unsigned int    size() const
            {
                return this->_size;
            }
    
    private:
            T               *array;
            unsigned int    _size;
};

#endif