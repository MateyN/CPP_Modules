/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:14:50 by mnikolov          #+#    #+#             */
/*   Updated: 2022/12/09 13:14:52 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact:: Contact(void)
{
    this->firstname = "";
    this->lastname = "";
    this->nickname = "";
    this->phonenumber = "";
    this->darkestsecret = "";
}

Contact:: ~Contact(void)
{
    return ;
}

std::string Contact::getFirstName()
{
    return (this->firstname);
}

std::string Contact::getLastName()
{
    return (this->lastname);
}

std::string Contact::getNickName()
{
    return (this->nickname);
}

std::string Contact::getPhoneNumber()
{
    return (this->phonenumber);
}

std::string Contact::getDarkestSecret()
{
    return (this->darkestsecret);
}

void    Contact::update(std::string name, int idx)
{
    if (idx == 0)
        this->firstname = name;
    else if (idx == 1)
        this->lastname = name;
    else if (idx == 2)
        this->nickname = name;
    else if (idx == 3)
        this->phonenumber = name;
    else if (idx == 4)
        this->darkestsecret = name;
}

Contact &Contact::operator = (Contact info)
{
    this->firstname = info.getFirstName();
    this->lastname = info.getLastName();
    this->nickname = info.getNickName();
    this->phonenumber = info.getPhoneNumber();
    this->darkestsecret = info.getDarkestSecret();
    return (*this);
}
