/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:30:53 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 03:49:45 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class   Span
{
    public:
            Span(void);
            Span(unsigned int N);
            Span & operator=(Span const &obj);
            Span(Span const &obj);
            ~Span(void);
            class   MaxElementsException : public std::exception
            {
                public:
                        virtual const char *what() const throw()
                        {
                            return ("Maximum size reached.");
                        }
            };
            class   EmptyContainerException : public std::exception
            {
                public:
                       virtual const char *what() const throw()
                        {
                            return ("No or only 1 element found.");
                        } 
            };

            void    addNumber(int nb);
            int     shortestSpan(void);
            int     longestSpan(void);
            void    addMoreNumbers(unsigned int range, time_t seed);

    public:
            unsigned int        _N;
            std::vector<int>    vec;
};

#endif