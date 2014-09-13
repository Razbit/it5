def ins_sort(arr):
    for i in range(len(arr)):
        j = i
        while (j > 0) and (arr[j] < arr[j-1]):
            temp = arr[j]
            arr[j] = arr[j-1]
            arr[j-1] = temp
            j -= 1
    return arr


instr = raw_input("Give me the names of your 10 best friends, separated by spaces:\n")

arr = ins_sort(instr.split())

for name in arr:
    print name 
