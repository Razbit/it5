# Quicksort implemented in python
# Eetu Pesonen 2014

def quicksort (arr):
    do_quicksort(arr, 0, len(arr)-1)

def do_quicksort (arr, start, end):

    if (end - start) == 0:
        return

    # select the pivot value
    pivot = 0

    if arr[start] > arr[start+1]:
        pivot = arr[start]
    else:
        pivot = arr[start+1]
    
    i = start
    j = end

    while True:
        if i == j:
            break

        if i == end:
            break

        if arr[i] < pivot:
            i += 1
        
        else:
            if arr[j] < pivot:
                temp = arr[j]
                arr[j] = arr[i]
                arr[i] = temp
                i += 1
                j = end
            else:
                j -= 1
    
    # Find the index to split the array
    i = 0
    while (arr[i] < pivot):
        i += 1

    do_quicksort(arr, start, i-1)
    do_quicksort(arr, i, end)

lst = [2,5,76, 4, 1, 3, 7]
print lst

quicksort(lst)
print lst
