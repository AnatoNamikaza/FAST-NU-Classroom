'''Write a program to add two lists index-wise. Create a new list that contains the 0th index item from both the list, then the 1st index item, and so on till the last element. any leftover items will get added at the end of the new list.'''

list1 = [1,2,3]
list2 = [1,2,3,4]
list3 = [];
min_size = min(len(list1),len(list2));
max_size = max(len(list1),len(list2));

for i in range(min_size):
    list3.append([list1[i],list2[i]])
    # added list of pairs into list
for i in range(min_size, max_size):
    if(len(list1) > len(list2)):
        # list1 is bigger
        # copy remaining number of list1 into list3
        list3.append(list1[i])
    else:
        # list2 is bigger
        # copy remaining number of list1 into list3
        list3.append(list2[i])
print(list3)
