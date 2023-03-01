/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 10:18:51 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 03:04:07 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form:: Form(void) : _name("Unknown"), _gradeToSign(0), _gradeToExec(0), _signed(false)
{
    std::cout << GREEN << "Form constructor called without name or grade" << RESET << std::endl;
}

Form:: Form(std::string name, int gradeSign, int gradeExec) : _name(name), _gradeToSign(gradeSign), _gradeToExec(gradeExec), _signed(false)
{
    std::cout << BLUE << "Constructor with name: " << name << " is called with grade: " << gradeSign << " and exec grade: " << gradeExec << RESET << std::endl;
    if (gradeSign < 1 || gradeExec < 1)
        throw Form:: GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw Form:: GradeTooLowException(); 
}

Form:: Form(Form const &obj) : _name(obj._name), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    std::cout << YELLOW << "Form copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Form & Form:: operator=(Form const &obj)
{
    std::cout << YELLOW << "Form copy assignment operator is called." << RESET << std::endl;
    if (this != &obj)
        _signed = obj._signed;
    return *this;
}

Form:: ~Form(void)
{
    std::cout << RED << "Form destructor is called." << RESET << std::endl;
}

std::string Form:: getName(void) const
{
    return _name;
}

int Form:: getGradeSign(void)
{
    return _gradeToSign;
}

int Form:: getGradeExec(void)
{
    return _gradeToExec;
}

bool Form:: getSignStatus(void)
{
    return _signed;
}

void    Form:: beSigned(Bureaucrat & instance)
{
    std::cout << COLOR << _name << " to be signed from: " << instance.getName() << RESET << std::endl;
    if (instance.getGrade() <= _gradeToSign)
    {
        _signed = true;
        instance.signForm(_name, _signed);
    }
    else
    {
        instance.signForm(_name, _signed);
        throw Form:: GradeTooLowException();
    }
}

void    Form:: execute(Bureaucrat const & executor) const
{
    std::cout << COLOR << executor.getName() << " attempting to execute form " << _name << RESET << std::endl;
}

std::ostream & operator<<(std::ostream & os, Form & obj)
{
    os << "Name: [" << obj.getName() << "]. Signature: [" << obj.getSignStatus()
    << "]. Signing grade: [" << obj.getGradeSign() << "]. Exec grade: [" << obj.getGradeExec() << "]." << std::endl;
    return os;
}