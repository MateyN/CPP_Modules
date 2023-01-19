/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:37 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/17 11:30:41 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm:: ShrubberyCreationForm(void) : _target("Unknown"), _signed(false), _gradeToSign(145), _gradeToExec(137)
{
    std::cout << GREEN << "ShrubberyCreationForm constructor called without any target" << RESET << std::endl;
    throw std::string ("Error: ShrubberyCreationForm cannot be instantiated without a target!");
}

ShrubberyCreationForm:: ShrubberyCreationForm(std::string target) : _target(target), _signed(false), _gradeToSign(145), _gradeToExec(137)
{
    std::cout << BLUE << "ShrubberyCreationForm constructor called" << RESET << std::endl; 
}

ShrubberyCreationForm:: ShrubberyCreationForm(ShrubberyCreationForm const &obj) : _target(obj._target), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    std::cout << YELLOW << "ShrubberyCreationForm copy constructor is called." << RESET << std::endl;
    *this = obj;
}

ShrubberyCreationForm & ShrubberyCreationForm:: operator=(ShrubberyCreationForm const &obj)
{
    std::cout << YELLOW << "ShrubberyCreationForm copy assignment operator is called." << RESET << std::endl;
    if (this != &obj)
        _signed = obj._signed;
    return *this;
}

ShrubberyCreationForm:: ~ShrubberyCreationForm(void)
{
    std::cout << RED << "ShrubberyCreationForm destructor is called." << RESET << std::endl;
}

std::string ShrubberyCreationForm:: getName(void)
{
    return _target;
}

int ShrubberyCreationForm:: getGradeSign(void)
{
    return _gradeToSign;
}

int ShrubberyCreationForm:: getGradeExec(void)
{
    return _gradeToExec;
}

bool ShrubberyCreationForm:: getSignStatus(void)
{
    return _signed;
}

void    ShrubberyCreationForm:: beSigned(Bureaucrat & instance)
{
    std::cout << COLOR << instance.getName() << " attempting to sign ShrubberyCreationForm: "<< RESET << std::endl;
    if (instance.getGrade() <= _gradeToSign)
    {
        _signed = true;
        instance.signForm("ShrubberyCreationForm", _signed);
    }
    else
    {
        instance.signForm("ShrubberyCreationForm", _signed);
        throw ShrubberyCreationForm:: GradeTooLowException();
    }
}

void    ShrubberyCreationForm:: execute(Bureaucrat const & executor) const
{   
    std::cout << COLOR << executor.getName() << " attempting to execute ShrubberyCreationForm: " << RESET << std::endl;
    if (_signed == 1 && executor.getGrade() <= _gradeToExec)
    {
        std::string filename(_target + "_shrubbery");
        std::ofstream file(filename.c_str());
        file << "ASCII Trees" << std::endl;
        std::cout << COLOR << executor.getName() << " executed RobotomyRequestForm with target: " << _target << RESET << std::endl;
    }
    else if (_signed == 0)
    {
        throw ShrubberyCreationForm:: FormNotSignedException();
    }
    else
        throw ShrubberyCreationForm:: GradeTooLowException();
}

std::ostream & operator<<(std::ostream & os, ShrubberyCreationForm & obj)
{
    os << "Target: [" << obj.getName() << "]. Signature: [" << obj.getSignStatus()
    << "]. Signing grade: [" << obj.getGradeSign() << "]. Exec grade: [" << obj.getGradeExec() << "]." << std::endl;
    return os;
}