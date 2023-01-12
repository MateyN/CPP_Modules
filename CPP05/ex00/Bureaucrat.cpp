/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:39:41 by mnikolov          #+#    #+#             */
/*   Updated: 2023/01/11 12:35:43 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat:: Bureaucrat(void)
{
    std::cout << GREEN << "Constructor called without name or grade" << RESET << std::endl;
    throw std::string ("Error: Bureaucrat cannot be instantiated without a grade!");
}

Bureaucrat:: Bureaucrat(std::string name, int grade)
{
    std::cout << BLUE << "Constructor with name: " << name << " is called with grade " << grade << RESET << std::endl;
    if (1 <= grade && grade <= 150)
        _grade = grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

Bureaucrat:: Bureaucrat(Bureaucrat const &obj)
{
    std::cout << YELLOW << "Bureaucrat copy constructor is called." << RESET << std::endl;
    *this = obj;
}

Bureaucrat & Bureaucrat:: operator=(Bureaucrat const &obj)
{
    std::cout << YELLOW << "Bureaucrat copy assignment operator is called." << RESET << std::endl;
    if (this != &obj)
        _grade = obj._grade;
    return *this;
}

Bureaucrat:: ~Bureaucrat(void)
{
    std::cout << RED << "Bureaucrat destructor is called." << RESET << std::endl;
    return ;
}

std::string Bureaucrat:: getName(void)
{
    return _name;
}

int Bureaucrat:: getGrade(void)
{
    return _grade;
}

void Bureaucrat:: increment(void)
{
    std::cout << "Increment: " << std::endl;
    if (_grade >= 2)
    {
        _grade -= 1;
        std::cout << BLUE << "Grade incremented to: " << _grade << RESET << std::endl;
    }
    else
        throw GradeTooHighException();
}

void Bureaucrat:: decrement(void)
{
    std::cout << "Decrement: " << std::endl;
    if (_grade <= 149)
    {
        _grade += 1;
        std::cout << BLUE << "Grade decremented to: " << _grade << RESET << std::endl;
    }
    else
        throw GradeTooLowException();
}

std::ostream & operator<<(std::ostream &os, Bureaucrat &obj)
{
    os << "Bureaucrat " << obj.getName() << "graded with: " << obj.getGrade();
    return os;
}