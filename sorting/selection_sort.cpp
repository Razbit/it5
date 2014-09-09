/* Selection sort algorith (currently for int key + std::string data) in C/C++
 *
 * Eetu Pesonen 2014
 */

#include <stdlib.h>
#include <string>
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

template<typename key_t, typename val_t>
struct node_t
{
	key_t key;
	val_t val;
};

void init_array(node_t<int, std::string> array[]);
void print(node_t<int, std::string> array[]);

template<typename key_t, typename val_t>
void sel_sort_str(node_t<key_t, val_t> array[]);

int main()
{
	node_t<int, std::string> array[20];

	init_array(array);
	print(array);
	std::cout << std::endl;
	sel_sort_str(array);
	print(array);

	return 0;
}

template<typename key_t, typename val_t>
void sel_sort_str(node_t<key_t, val_t> array[])
{
	int smallest_key_index;
	node_t<key_t, val_t> temp;
	
	for (int i = 0; i < 20; i++)
	{
		// Let's find the smallest key
		smallest_key_index = i;
		
		for (int j = i; j < 20; j++)
		{
			if (array[j].key < array[smallest_key_index].key)
				smallest_key_index = j;
		}

		// Now we swap the items at indices i and j IF i and j are not the index of the same item
		if (i != smallest_key_index)
		{
			temp = array[i];
			array[i] = array[smallest_key_index];
			array[smallest_key_index] = temp;
		}				
	}
}

void init_array(node_t<int, std::string> array[])
{
	// initialize to random content
	for (int i = 0; i < 20; i++)
	{
		array[i].val = names[rand()%50];
		array[i].key = rand()%50; //yeah, i know.. there are gonna be keys with the same value..
	}
}

void print(node_t<int, std::string> array[])
{
	for (int i = 0; i < 20; i++)
	{
		std::cout << array[i].key << ", " << array[i].val << std::endl;
	}
}
