/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:18:22 by mnikolov          #+#    #+#             */
/*   Updated: 2023/02/02 10:38:14 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base *generate(void)
{
    switch (rand() % 3)
    {
        case 0:
                return (new A());
                break ;
        case 1:
                return (new B());
                break ;
        case 2:
                return (new C());
                break ;
        default:
                perror("The random generator failed.");
                return (NULL);
    }
}

void    identify(Base *p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "No type" << std::endl;
}

void    identify(Base &p)
{
    try
    {
        A instance = dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return ;
    }
    //catch (std::bad_cast& bc)
    //{
    //    std::cerr << "bad_cast caught: " << bc.what() << std::endl;
    //}
    catch(const std::exception& e)
    {
        //std::cout << e.what() << std::endl;
    }
    try
    {
        B instance = dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return ;
    }
    //catch (std::bad_cast& bc)
    //{
     //   std::cerr << "bad_cast caught: " << bc.what() << std::endl;
    //}
    catch(const std::exception& e)
    {
        //std::cout << e.what() << std::endl;
    }
    try
    {
        C instance = dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
        //std::cout << e.what() << std::endl;
    }
    //catch (std::bad_cast& bc)
    //{
     //   std::cerr << "bad_cast caught: " << bc.what() << std::endl;
    //}
    std::cout << "Unknown reference" << std::endl;
}

int main()
{
    std::cout << std::endl;
    std::cout << MAGENTA << "Randomly generating 'A', 'B' or 'C' pointer..." << RESET << std::endl;
	srand(time(NULL));
	for (int i = 0; i < 3; i++)
	{
		Base *base = generate();
		if (base == NULL)
			return (1);
		else
		{
            std::cout << GREEN << "Pointer : " << RESET;
			identify(base);
            std::cout << YELLOW << "Reference : " << RESET;
			identify(*base);
			delete (base);
			std::cout << std::endl;
		}
	}
	return (0);
}