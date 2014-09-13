/*
 * Different sorting algorithms for the pair_t type with the field key
 * defining the less than and greater than operators
 * 
 * Eetu Pesonen 2014
 */

#ifndef H_RSORT
#define H_RSORT

template<typename key_t, typename val_t>
struct pair_t
{
	key_t key;
	val_t val;
};

// stupid c++ rules force me to put the implementation into the header so here we go..
template<typename key_t, typename val_t>
void bubble_sort(pair_t<key_t, val_t> array[], unsigned long size)
{
	bool swapped = false;
	
	while (true)
	{
		swapped = false;
		for (int i = 1; i < size; i++)
		{
			if (array[i-1].key > array[i].key)
			{ // if previous item has larger key, swap current and previus
				pair_t<key_t, val_t> temp = array[i-1];
				array[i-1] = array[i];
				array[i] = temp;
				swapped = true;
			}
		}

		size--;
		if (!swapped) //exit when no swaps happened -> sorted
			break;
	}
}

template<typename key_t, typename val_t>
void insertion_sort(pair_t<key_t, val_t> array[], unsigned long size)
{
	int j;
	pair_t<key_t, val_t> temp;

	// go through the array and move the current item to its correct index
	for (int i = 1; i < size; i++)
	{
		j = i;
		while (j > 0 && array[j].key < array[j-1].key)
		{
			// swap
			temp = array[j];
			array[j] = array[j-1];
			array[j-1] = temp;

			j--;
		}
	}
}

template<typename key_t, typename val_t>
void selection_sort(pair_t<key_t, val_t> array[], unsigned long size)
{
	int smallest_key_index;
	pair_t<key_t, val_t> temp;
	
	for (int i = 0; i < size; i++)
	{
		// Let's find the smallest key
		smallest_key_index = i;
		
		for (int j = i; j < size; j++)
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


#endif //H_RSORT
