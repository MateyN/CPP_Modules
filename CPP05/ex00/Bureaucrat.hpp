/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:45 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/11 12:52:46 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat
{
    public:
            Bureaucrat(void);
            Bureaucrat(std::string name, int grade);
            Bureaucrat & operator=(Bureaucrat const &obj);
            Bureaucrat(Bureaucrat const &obj);
            ~Bureaucrat(void);
            
            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char* what() const throw()
                        {
                            return ("Error, the grade cannot be below 1");
                        }
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char* what() const throw()
                        {
                            return ("Error, the grade cannot be above 150");
                        }
            };
            
            std::string getName(void);
            int         getGrade(void);
            void        increment(void);
            void        decrement(void);
            
    private:
            std::string const   _name;
            int                 _grade;
};
    std::ostream & operator<<(std::ostream& os, Bureaucrat &obj);
#endif