/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:22 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/19 09:52:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm:: PresidentialPardonForm(void) : _target("Unknown"), _signed(false), _gradeToSign(25), _gradeToExec(5)
{
    std::cout << GREEN << "PresidentialPardonForm constructor called without any target" << RESET << std::endl;
    throw std::string ("Error: PresidentialPardonForm cannot be instantiated without a target!");
}

PresidentialPardonForm:: PresidentialPardonForm(std::string target) : _target(target), _signed(false), _gradeToSign(25), _gradeToExec(5)
{
    std::cout << BLUE << "PresidentialPardonForm constructor called" << RESET << std::endl; 
}

PresidentialPardonForm:: PresidentialPardonForm(PresidentialPardonForm const &obj) : _target(obj._target), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    std::cout << YELLOW << "PresidentialPardonForm copy constructor is called." << RESET << std::endl;
    *this = obj;
}

PresidentialPardonForm & PresidentialPardonForm:: operator=(PresidentialPardonForm const &obj)
{
    std::cout << YELLOW << "PresidentialPardonForm copy assignment operator is called." << RESET << std::endl;
    if (this != &obj)
        _signed = obj._signed;
    return *this;
}

PresidentialPardonForm:: ~PresidentialPardonForm(void)
{
    std::cout << RED << "PresidentialPardonForm destructor is called." << RESET << std::endl;
}

std::string PresidentialPardonForm:: getName(void)
{
    return _target;
}

int PresidentialPardonForm:: getGradeSign(void)
{
    return _gradeToSign;
}

int PresidentialPardonForm:: getGradeExec(void)
{
    return _gradeToExec;
}

bool PresidentialPardonForm:: getSignStatus(void)
{
    return _signed;
}

void    PresidentialPardonForm:: beSigned(Bureaucrat & instance)
{
    std::cout << COLOR << instance.getName() << " attempting to sign PresidentialPardonForm: "<< RESET << std::endl;
    if (instance.getGrade() <= _gradeToSign)
    {
        _signed = true;
        instance.signForm("PresidentialPardonForm", _signed);
    }
    else
    {
        instance.signForm("PresidentialPardonForm", _signed);
        throw PresidentialPardonForm:: GradeTooLowException();
    }
}

void    PresidentialPardonForm:: execute(Bureaucrat const & executor) const
{
    std::cout << COLOR << executor.getName() << " attempting to execute PresidentialPardonForm: " << RESET << std::endl;
    if (_signed == 1 && executor.getGrade() <= _gradeToExec)
    {
        std::cout << COLOR << _target << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;

        std::cout << COLOR << executor.getName() << " executed PresidentialPardonForm with target: " << _target << RESET << std::endl;
    }
    else if (_signed == 0)
    {
        throw PresidentialPardonForm:: FormNotSignedException();
    }
    else
        throw PresidentialPardonForm:: GradeTooLowException();
}

std::ostream & operator<<(std::ostream & os, PresidentialPardonForm & obj)
{
    os << "Target: [" << obj.getName() << "]. Signature: [" << obj.getSignStatus()
    << "]. Signing grade: [" << obj.getGradeSign() << "]. Exec grade: [" << obj.getGradeExec() << "]." << std::endl;
    return os;
}