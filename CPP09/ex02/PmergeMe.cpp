/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikolov <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:37:10 by mnikolov          #+#    #+#             */
/*   Updated: 2023/05/31 10:25:50 by mnikolov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
    return ;
}

PmergeMe::~PmergeMe()
{
    return ;
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
    *this = obj;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
    this->l = obj.l;
    this->v = obj.v;
    return *this;
}

void PmergeMe::printList()
{
    int i = 0;
    std::list<int>::const_iterator it = l.begin();
    std::list<int>::const_iterator end = l.end();
    for (; it != end; ++it)
    {
        if (++i > 8)
        {
            std::cout << " [...]";
            break;
        }
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

void PmergeMe::printVector()
{
    int i = 0;
    std::vector<int>::const_iterator it = v.begin();
    std::vector<int>::const_iterator end = v.end();
    for (; it != end; ++it)
    {
        if (++i > 8)
        {
            std::cout << " [...]";
            break;
        }
        std::cout << " " << *it;
    }
    std::cout << std::endl;
}

void checkNumber(const std::string& str)
{
    if (str[0] == '-')
        throw std::invalid_argument("Error: number not positive");
    if (str.length() > 10 || (str.length() == 10 && str > "2147483647"))
        throw std::out_of_range("Error: number too large");
    if (!std::all_of(str.begin(), str.end(), ::isdigit))
        throw std::invalid_argument("Error: not a valid number");
}

void mergeLists(std::list<int> &list, int left, int mid, int right)
{
    std::list<int> tmp; // store the merged elements before copy them back to the original list
    std::list<int>::iterator it1 = list.begin(); // iterate over the first sublist
    std::advance(it1, left); // increment the iterator within the first sublist
    std::list<int>::iterator it2 = list.begin(); // iterate over the second sublist
    std::advance(it2, mid + 1); // increment the iterator within the second sublist

    // checking if both iterators have reached the end of the sublist
    while (it1 != std::next(list.begin(), mid + 1) && it2 != std::next(list.begin(), right + 1))
    {
        if (*it1 <= *it2) // compare both elements
        {
            tmp.push_back(*it1); // if true merge the first element
            ++it1;
        }
        else
        {
            tmp.push_back(*it2); // if not merge the second one
            ++it2;
        }
    }
    while (it1 != std::next(list.begin(), mid + 1)) // checks if there are any elements left behind in the first sublist
    {
        tmp.push_back(*it1);
        ++it1;
    }

    while (it2 != std::next(list.begin(), right + 1)) // checks if there are any elements left behind in the second sublist
    {
        tmp.push_back(*it2);
        ++it2;
    }

    std::list<int>::iterator it = list.begin();
    std::advance(it, left);
    std::list<int>::iterator tmpIt = tmp.begin();

    while (tmpIt != tmp.end())
    {
        *it = *tmpIt; // assign the value from the temp list to the original one and replace it
        ++it;
        ++tmpIt;
    }
}

void mergeVector(std::vector<int> &vector, int left, int mid, int right)
// merge two subarrays within a vector,
// using a temporary vector to store the sorted elements
// before copy them back to the original vector
{
    std::vector<int> tmp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= right) 
    {
        if (vector[i] <= vector[j]) // compare 2 elements in the original vector, if i <= j
        {
            tmp[k++] = vector[i++]; // the element from the left subarray is placed in tmp
        }
        else
        {
            tmp[k++] = vector[j++]; // if not the right subarray is placed in tmp
        }
    }
    // checks if there are any elements left behind
    while (i <= mid)
    {
        tmp[k++] = vector[i++];
    }
    while (j <= right)
    {
        tmp[k++] = vector[j++];
    }
    // copy back the sorted elements into the original vector
    for (int p = 0; p < k; p++)
    {
        vector[left + p] = tmp[p];
    }
}

void mergeSort(std::list<int> &list, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2; // take the mid range
        mergeSort(list, begin, mid); // sorts the elements in the first/left subarray
        mergeSort(list, mid + 1, end); // sorts the elements in the second/right subarray
        mergeLists(list, begin, mid, end); // merge the two sorted subarrays, the left and right halves, into a single sorted subarray within the original list
    }
}

void mergeSort(std::vector<int> &vector, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(vector, begin, mid);
        mergeSort(vector, mid + 1, end);
        mergeVector(vector, begin, mid, end);
    }
}

#include <chrono>

void PmergeMe::sortElements(char **tab)
{
    std::chrono::steady_clock::time_point start;
    std::chrono::steady_clock::time_point end;
    double Ltime;
    double Vtime;

    int i = 1;
    int nb = 0;

    // Extract numbers from tab and store them in list(l) and vector(v)
    while (tab[i])
    {
        checkNumber(tab[i]);
        std::istringstream(tab[i]) >> nb;
        l.push_back(nb);
        v.push_back(nb);
        i++;
    }

    std::cout << "Before: ";
    printList();

    // Perform merge sort on list
    start = std::chrono::steady_clock::now(); // records the start of the timeclock
    mergeSort(l, 0, l.size() - 1);
    end = std::chrono::steady_clock::now(); // records the end of the timeclock
    Ltime = std::chrono::duration<double, std::milli>(end - start).count(); // take the duration between start and end timeclocks

    std::cout << "After: ";
    printList();

    std::cout << std::fixed << std::setprecision(5);
    std::cout << "Time to process a range of " << l.size() << " elements with std::list : " << Ltime << " ms\n";

    std::cout << "Before: ";
    printVector();

    // Perform merge sort on vector
    start = std::chrono::steady_clock::now();
    mergeSort(v, 0, v.size() - 1);
    end = std::chrono::steady_clock::now();
    Vtime = std::chrono::duration<double, std::milli>(end - start).count();

    std::cout << "After: ";
    printVector();

    std::cout << "Time to process a range of " << v.size() << " elements with std::vector : " << Vtime << " ms\n";
}
