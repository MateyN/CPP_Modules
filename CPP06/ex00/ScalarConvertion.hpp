/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConvertion.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:49:08 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/30 12:12:49 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERSION_HPP
# define SCALARCONVERSION_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"
#define COLOR   "\033[1m\033[38m"
#define MAGENTA "\033[1m\033[35m"

#define NAN_INF 1
#define CHAR 2
#define INT 3
#define FLOAT 4
#define DOUBLE 5
#define ERROR 6

#include <string>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <cctype>
class Convert
{
    public:
            Convert(void);
            Convert(const std::string input);
            Convert & operator=(Convert const &obj);
            Convert(Convert const &obj);
            ~Convert(void);
            class ErrorException : public std::exception
            {
                public:
                        virtual const char *what() const throw()
                        {
                            return ("Error: Impossible to print not convertable input!");
                        }
            };
    private:
            std::string getInput(void) const;
            int         getType(void) const;
            char        getChar(void) const;
            int         getInt(void) const;
            float       getFloat(void) const;
            double      getDouble(void) const;

            void        fromChar(void);
            void        fromInt(void);
            void        fromFloat(void);
            void        fromDouble(void);

            void        displayOutput(void) const;
            int	        checkInput();
            void        convertInput();

            const std::string   _input;
            int                 _type;
            char                _char;
            int                 _int;
            float               _float;
            double              _double;
};

#endif