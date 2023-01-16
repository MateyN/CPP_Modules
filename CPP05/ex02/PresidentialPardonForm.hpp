/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:26 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/16 11:37:24 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP
#include "Form.hpp"

class   PresidentialPardonForm : public Form
{
    public:
            PresidentialPardonForm(void);
            PresidentialPardonForm(std::string target);
            PresidentialPardonForm(PresidentialPardonForm const & obj);
            PresidentialPardonForm & operator=(PresidentialPardonForm const & obj);
            ~PresidentialPardonForm(void);
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

std::ostream & operator<<(std::ostream & os, PresidentialPardonForm & obj);

#endif