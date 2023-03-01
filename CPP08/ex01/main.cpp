/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:31:17 by mnikolov          #+#    #+#             */
/*   Updated: 2023/03/01 03:58:44 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
  std::cout << "Given tests: " << std::endl;
  Span sp = Span(5);
  
  sp.addNumber(6);
  sp.addNumber(3);
  sp.addNumber(17);
  sp.addNumber(9);
  sp.addNumber(11);
  
  std::cout << sp.shortestSpan() << std::endl;
  std::cout << sp.longestSpan() << std::endl;
  
  // Test with more numbers
  std::cout << "Tests with more numbers: " << std::endl;
  try
	{
    Span a = Span(10000);
		a.addMoreNumbers(10000, time(NULL));
		std::cout << "shortest span is " << a.shortestSpan() << std::endl;
		std::cout << "longest span is " << a.longestSpan() << std::endl << std::endl;
	}
  catch(const std::exception & e)
  {
    	std::cerr << e.what() << '\n';
  }
  return 0;
}