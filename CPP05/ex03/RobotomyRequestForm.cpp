/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 10:40:31 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/28 23:28:33 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm:: RobotomyRequestForm(void) : _target(NULL), _gradeToSign(72), _gradeToExec(45), _signed(false)
{
    std::cout << GREEN << "RobotomyRequestForm constructor called without any target" << RESET << std::endl;
    throw std::string ("Error: RobotomyRequestForm cannot be instantiated without a target!");
}

RobotomyRequestForm:: RobotomyRequestForm(std::string target) : _target(target), _gradeToSign(72), _gradeToExec(45), _signed(false)
{
    std::cout << BLUE << "RobotomyRequestForm constructor called with target " << _target << RESET << std::endl; 
}

RobotomyRequestForm:: RobotomyRequestForm(RobotomyRequestForm const &obj) : _target(obj._target), _gradeToSign(obj._gradeToSign), _gradeToExec(obj._gradeToExec)
{
    std::cout << YELLOW << "RobotomyRequestForm copy constructor is called." << RESET << std::endl;
    *this = obj;
}

RobotomyRequestForm & RobotomyRequestForm:: operator=(RobotomyRequestForm const &obj)
{
    std::cout << YELLOW << "RobotomyRequestForm copy assignment operator is called." << RESET << std::endl;
    if (this != &obj)
        _signed = obj._signed;
    return *this;
}

RobotomyRequestForm:: ~RobotomyRequestForm(void)
{
    std::cout << RED << "RobotomyRequestForm destructor is called." << RESET << std::endl;
}

std::string RobotomyRequestForm:: getName(void)
{
    return _target;
}

int RobotomyRequestForm:: getGradeSign(void)
{
    return _gradeToSign;
}

int RobotomyRequestForm:: getGradeExec(void)
{
    return _gradeToExec;
}

bool RobotomyRequestForm:: getSignStatus(void)
{
    return _signed;
}

void    RobotomyRequestForm:: beSigned(Bureaucrat & instance)
{
    std::cout << COLOR << instance.getName() << " attempting to sign RobotomyRequestForm: "<< RESET << std::endl;
    if (instance.getGrade() <= _gradeToSign)
    {
        _signed = true;
        instance.signForm("RobotomyRequestForm", _signed);
    }
    else
    {
        instance.signForm("RobotomyRequestForm", _signed);
        throw RobotomyRequestForm:: GradeTooLowException();
    }
}

void    RobotomyRequestForm:: execute(Bureaucrat const & executor) const
{
    std::cout << COLOR << executor.getName() << " attempting to execute RobotomyRequestForm: " << RESET << std::endl;
    if (_signed == 1 && executor.getGrade() <= _gradeToExec)
    {
        std::cout << COLOR << "BzZzZzZzZzZz... " << RESET << std::endl;
        srand(time(NULL)); /* initialize random seed: */
        if (rand() % 2)
            std::cout << COLOR << _target << " was robotomized successfully" << RESET << std::endl;
        else
            std::cout << COLOR << _target << " robotomization failed" << RESET << std::endl;
        std::cout << COLOR << executor.getName() << " executed RobotomyRequestForm with target: " << _target << RESET << std::endl;
    }
    else if (_signed == 0)
    {
        throw RobotomyRequestForm:: FormNotSignedException();
    }
    else
        throw RobotomyRequestForm:: GradeTooLowException();
}

std::ostream & operator<<(std::ostream & os, RobotomyRequestForm & obj)
{
    os << "Target: [" << obj.getName() << "]. Signature: [" << obj.getSignStatus()
    << "]. Signing grade: [" << obj.getGradeSign() << "]. Exec grade: [" << obj.getGradeExec() << "]." << std::endl;
    return os;
}