/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:30:57 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/03 16:09:35 by mnikolov         ###   ########.fr       */
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

void Span::addNumber(int nb)
{
    if (vec.size() == 0) // Handle the case where vec has no elements
    {
        vec.push_back(nb);
    }
    else if (vec.size() < _N) // Check if there's room to add another element
    {
        vec.push_back(nb);
    }
    else // Throw an exception if the maximum size has been reached
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

int Span::shortestSpan()
{
    if (vec.size() <= 1) // Check if there are enough elements in the vector
        throw (EmptyContainerException());

    std::vector<int> v; // Create a new vector to store the difference between elements
    std::sort(vec.begin(), vec.end()); // Sort the elements in the vector in ascending order

    unsigned int i = 0;

    while (i < vec.size() - 1)
    {
        v.push_back(vec[i + 1] - vec[i]); // Calculate the difference between the current and next element
        i++;
    }

    int ssp = *std::min_element(v.begin(), v.end()); // Find the minimum element in the new vector
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