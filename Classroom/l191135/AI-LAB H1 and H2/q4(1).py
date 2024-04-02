'''Sort a tuple of tuples by 2nd item.
Given: tuple1 = (('a', 23),('b', 37),('c', 11), ('d',29))
Expected: (('c', 11), ('a', 23), ('d', 29), ('b', 37))'''
tuple1 = (('a', 23),('b', 37),('c', 11), ('d',29))

list_of_tuple = (list)(tuple1)
l = len(list_of_tuple)
for i in range(0, l):
    for j in range(0, l-i-1):
	if (list_of_tuple[j][1] > list_of_tuple[j + 1][1]):
	    to_be_swaped = list_of_tuple[j]
	    list_of_tuple[j]= list_of_tuple[j + 1]
	    list_of_tuple[j + 1]= to_be_swaped

print(list_of_tuple)

