/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:34 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/16 11:39:11 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP
#include "Form.hpp"

class   RobotomyRequestForm : public Form
{
    public:
            RobotomyRequestForm(void);
            RobotomyRequestForm(std::string target);
            RobotomyRequestForm(RobotomyRequestForm const & obj);
            RobotomyRequestForm & operator=(RobotomyRequestForm const & obj);
            ~RobotomyRequestForm(void);
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

std::ostream & operator<<(std::ostream & os, RobotomyRequestForm & obj);

#endif