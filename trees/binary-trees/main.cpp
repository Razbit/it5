#include "tree.h"

#include <string>
#include <stdlib.h>
#include <iostream>

std::string names[] = {
	"Parker", "Camden", "Carlos", "Preston",
	"James", "Stephen", "Harrison", "Robert",
	"Jack", "Lane", "Aden", "Mateo",
	"Gabriel", "Jakob", "David", "Everett",
	"Cade", "Landon", "Antonio", "Jesse",
	"Jared", "Tanner", "Emiliano", "Andy",
	"Zackary", "Steven", "Jordan", "Louis",
	"Steven", "Isaiah", "Giovanni", "Micah",
	"Braden", "Jameson", "Esteban", "Shawn",
	"Vincent", "Braxton", "Carlos", "Grant",
	"Bryson", "Cohen", "Jose", "Chance",
	"Dalton", "Allen", "Andre", "Christopher",
	"Roman", "Caleb"
};

int main()
{
	BinaryTree<int, std::string>* tree = new BinaryTree<int, std::string>;

	// initialize to random content
	for (int i = 0; i < 20; i++)
		tree->add(rand()%50, names[rand()%50]);
	
	tree->print();
	std::cout << std::endl;

	try
	{
		std::cout << "15: " << tree->find(15) << std::endl;
	}
	catch (...)
	{
		std::cout << "No item with key 15 was found\n";
	}

	try
	{
		std::cout << "25: " << tree->find(25) << std::endl;
	}
	catch (...)
	{
		std::cout << "No item with key 25 was found\n";
	}

	try
	{
		std::cout << "5: " << tree->find(5) << std::endl;
	}
	catch (...)
	{
		std::cout << "No item with key 5 was found\n";
	}
	
	tree->remove(25);
	tree->remove(15);
	tree->remove(5);

	tree->print();
	std::cout << std::endl;

	delete tree;
	
	return 0;
}

