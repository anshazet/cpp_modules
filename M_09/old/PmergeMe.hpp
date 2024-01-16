/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 07:22:58 by ashalagi          #+#    #+#             */
/*   Updated: 2024/01/11 07:35:57 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <string>

class PmergeMe
{
public:
	PmergeMe();
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe();

	std::string sortWithVector(const std::vector<int> &numbers) const;
	std::string sortWithList(const std::list<int> &numbers) const;

private:
	// Helper methods for the Ford-Johnson algorithm could be declared here.
};

#endif // PMERGEME_HPP
