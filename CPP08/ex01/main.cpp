/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 10:31:17 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/17 11:10:30 by mnikolov         ###   ########.fr       */
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
		Span	sp(10000);
    std::vector<int> v;
    
		for(int i = 1; i <= 10000; i++)
			v.push_back(i);
		sp.addMoreNumbers(v.begin(), v.end());
		std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest span: " << sp.longestSpan() << std::endl;
	}
	catch(const std::exception & e)
  {
    	std::cerr << e.what() << '\n';
  }
  return 0;
}