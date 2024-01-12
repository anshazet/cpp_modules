/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:45:03 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/11 14:07:16 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    std::cout << std::endl;

    // Copy contents of MutantStack to a std::list
    std::list<int> listFromStack(mstack.begin(), mstack.end());
    std::cout << "Contents of std::list copied from MutantStack: ";
    for (std::list<int>::iterator it = listFromStack.begin(); it != listFromStack.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Additional test - replacing MutantStack with std::list
    std::list<int> testList;
    testList.push_back(5); 
    testList.push_back(17);
    testList.pop_back();
    testList.push_back(3);
    testList.push_back(5);
    testList.push_back(737);
    testList.push_back(0);

    std::cout << "Contents of std::list for comparison: ";
    for (std::list<int>::iterator it = testList.begin(); it != testList.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*
Push 5 and 17 onto the stack:

Stack after operations: [5, 17]
Print the top element and pop it:

Output: 17
Stack after pop: [5]
Print the size of the stack:

Output: 1 (as there's only one element, 5)
Push 3, 5, 737, and 0 onto the stack:

Stack after these pushes: [5, 3, 5, 737, 0]

The stack initially contains 5 and 17 (with 17 at the top). After popping
the top element (17), 5 remains.
then push 3, 5, 737, and 0 onto the stack.
When iterating from the beginning (begin()) to the end (end()),
the elements are printed in the order 5 (bottom), 3, 5, 737, and 0 (top).
*/