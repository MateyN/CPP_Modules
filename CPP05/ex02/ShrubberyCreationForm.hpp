/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:40 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/16 11:39:59 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBERRYCREATIONFORM_HPP
# define SHRUBERRYCREATIONFORM_HPP
#include "Form.hpp"

class   ShrubberyCreationForm : public Form
{
    public:
            ShrubberyCreationForm(void);
            ShrubberyCreationForm(std::string target);
            ShrubberyCreationForm(ShrubberyCreationForm const & obj);
            ShrubberyCreationForm & operator=(ShrubberyCreationForm const & obj);
            ~ShrubberyCreationForm(void);
            class GradeTooHighException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade too high");
     			}
		};
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, grade too low");
     			}
		};
		class FormNotSignedException: public std::exception
		{
			public:
				virtual const char* what() const throw()
     			{
					return ("Error, form not signed");
     			}
		};
        std::string getName(void);
        bool        getSignStatus(void);
        int         getGradeSign(void);
        int         getGradeExec(void);
        void        beSigned(Bureaucrat & instance);
        void        execute(Bureaucrat const & executor) const;

        private:
                std::string _target;
                int const   _gradeToSign;
                int const   _gradeToExec;
                bool        _signed;
};

std::ostream & operator<<(std::ostream & os, ShrubberyCreationForm & obj);

#endif