/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:18:55 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/16 11:45:06 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[1m\033[36m"

#include <iostream>
#include <string>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
            virtual ~Form(void); 
            class GradeTooHighException : public std::exception
            {
                public:
                        virtual const char* what() const throw()
                        {
                            return ("Error, grade too high");
                        }
            };
            class GradeTooLowException : public std::exception
            {
                public:
                        virtual const char* what() const throw()
                        {
                            return ("Error, grade too low");
                        }
            };
            
            std::string getName(void) const;
            bool        getSignStatus(void);
            int         getGradeSign(void);
            int         getGradeExec(void);
            void        beSigned(Bureaucrat & instance);
            virtual void execute(Bureaucrat const & executor) const = 0;
            
    private:
            std::string const   _name;
            int const           _gradeToSign;
            int const           _gradeToExec;
            bool                _signed;

    protected:
            Form(void);
            Form(std::string name, int gradeSign, int gradeExec);
            Form & operator=(Form const &obj);
            Form(Form const &obj);
};
    std::ostream & operator<<(std::ostream& os, Form &obj);
#endif