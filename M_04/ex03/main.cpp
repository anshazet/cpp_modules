/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalagi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 07:26:23 by ashalagi          #+#    #+#             */
/*   Updated: 2023/12/20 13:35:35 by ashalagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Character.hpp"
#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;


	std::cout << "--------------" << std::endl;
	
	Character bob2("Bob");
    ICharacter* jim = new Character("Jim");
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());

    AMateria* ice = src2->createMateria("ice");
    AMateria* ice2 = new Ice();
    AMateria* ice3 = ice->clone();
    AMateria* cure = new Cure();
    AMateria* cure2 = src2->createMateria("cure");

    bob2.equip(ice);
    bob2.use(0, *jim);

    bob2.equip(cure);
    bob2.use(1, *jim);

    bob2.equip(ice2);
    bob2.equip(ice3);

    bob2.unequip(1); // cure
    bob2.unequip(0); // ice

    bob2.equip(ice);
    bob2.equip(ice2);
    bob2.equip(ice3);
    bob2.equip(cure);
    bob2.equip(cure2);

    bob2.use(0, bob2);
    bob2.use(1, bob2);
    bob2.use(2, bob2);
    bob2.use(3, bob2);
    bob2.use(4, bob2);

    bob2.unequip(0);
    bob2.unequip(0);
    bob2.unequip(0);
    bob2.unequip(0);
    bob2.unequip(0);

    delete ice;
    delete ice2;
    delete ice3;
    delete cure;
    delete cure2;
    delete jim;
    delete src2;

	return 0;
}

