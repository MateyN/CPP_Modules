/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:37:21 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:42 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_H
#define PMERGEME_H

#include <list>
#include <vector>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <chrono>

class PmergeMe
{
private:
    std::list<int> l;
    std::vector<int> v;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &obj);
    PmergeMe& operator=(const PmergeMe &obj);
    ~PmergeMe();

    void sortElements(char **tab);
    void printList();
    void printVector();
    void mergeLists(std::list<int> &list, int left, int mid, int right);
    void mergeVector(std::vector<int> &list, int left, int mid, int right);
};

#endif
