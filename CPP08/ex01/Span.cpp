/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:30:57 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 03:59:55 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span:: Span(void)
{
    std::cout << "Default Span constructor is called." << std::endl;
}

Span:: Span(unsigned int N)
{
    (void) N;
    //std::cout << "Span constructor is called." << std::endl;
}

Span:: Span(Span const &obj)
{
    *this = obj;
}

Span & Span:: operator=(Span const &obj)
{
    if (this != &obj)
    {
        _N = obj._N;
        vec = obj.vec;
    }
    return *this;
}

Span:: ~Span(void)
{
    //std::cout << "Span destructor is called." << std::endl;
    return ;
}

void Span:: addNumber(int nb)
{
    if (vec.size() < _N)
        vec.push_back(nb);
    else
    {
        throw MaxElementsException();
    }
}

void	Span::addMoreNumbers(unsigned int range, time_t seed)
{
	srand(seed);
	for (size_t i = 0; i < range; i++)
	{
		try
		{
			addNumber(rand());
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
}

int Span:: shortestSpan()
{
    if (vec.size() <= 1)
        throw (EmptyContainerException());
    std::vector<int> v;
    std::sort(vec.begin(), vec.end());
    unsigned int i = 0;
    while (i < vec.size() - 1)
    {
        v.push_back(vec[i + 1] - vec[i]);
        i++;
    }
    int ssp = *std::min_element(v.begin(), v.end());
    return ssp;
}

int Span:: longestSpan()
{
    if (vec.size() <= 1)
        throw (EmptyContainerException());
    int max = *std::max_element(vec.begin(), vec.end());
    int min = *std::min_element(vec.begin(), vec.end());
    return (max - min);
}