/* Selection sort algorith (currently for int key + std::string data) in C/C++
 *
 * Eetu Pesonen 2014
 */

#include <stdlib.h>
#include <string>
#include <iostream>

#include "rsort.h"

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

void init_array(pair_t<int, std::string> array[]);
void print(pair_t<int, std::string> array[]);

int main()
{
	pair_t<int, std::string> array[20];

	init_array(array);
	std::cout << "Bubble sort\n";
	print(array);
	std::cout << std::endl;
	bubble_sort(array, 20);
	print(array);

	init_array(array);
	std::cout << "Selection sort\n";
	print(array);
	std::cout << std::endl;
	selection_sort(array, 20);
	print(array);

	init_array(array);
	std::cout << "Insertion sort\n";
	print(array);
	std::cout << std::endl;
	insertion_sort(array, 20);
	print(array);

	return 0;
}

void init_array(pair_t<int, std::string> array[])
{
	// initialize to random content
	for (int i = 0; i < 20; i++)
	{
		array[i].val = names[rand()%50];
		array[i].key = rand()%50; //yeah, i know.. there are gonna be keys with the same value..
	}
}

void print(pair_t<int, std::string> array[])
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << "[ " << array[i].key << ", " << array[i].val << " ]";
		
		if ((i+1) % 5 == 0)
			std::cout << std::endl;
		else
			std::cout << ", ";
	}

	std::cout << std::endl;
}
