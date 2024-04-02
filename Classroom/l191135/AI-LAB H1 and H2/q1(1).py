'''Write a Python program to find the length of a set, apply all sets
operations(union,intersection) and print the results,find maximum and the minimum value in a
set,create a shallow copy of sets,check if a set is a subset of another set, remove all elements
from a given set,check if two given sets have no elements in common.check if a given set is
superset of itself and superset of another given set.
set1 = {1,2,3,4,5}
set2 = {4,5,6,7,8}'''

import copy
def exists(set1,value):
    "does value exists in set1"
    for i in set1:
        if(i==value):
            return True
    return False

def take_union(set1, set2):
    "takes union of two sets"
    # create an empty for union
    union_result = set()
    for i in set1:
        # if any element of set1 does not exists in union_result
        # then add this number to union_list
        if(exists(union_result,i) == False):
            union_result.add(i)
    for i in set2:
        # if any element of set2 does not exists in union_result
        # then add this number to union_list
        if(exists(union_result,i) == False):
            union_result.add(i)
    return union_result
def take_intersection(set1,set2):
    "takes intersection of two sets"
    # create an empty for union
    intersection_result = set()
    for i in set1:
        # if any element of set1 does exists in set2
        # then add this number to intersection_list
        if(exists(set2,i) == True):
            intersection_result.add(i)
    for i in set2:
        # if any element of set2 does not exists in intersection_result
        # then add this number to intersection_list
        if(exists(set1,i) == True):
            intersection_result.add(i)
    return intersection_result
def minimum(set1):
    set_list = list(set1)
    min = set_list[0]
    for i in set_list:
        if(i < min):
            min = i
    return min
def maximum(set1):
    set_list = list(set1)
    max = set_list[0]
    for i in set_list:
        if(i > max):
            max = i
    return max

def create_shallow_copy(set1):
    return copy.copy(set1)
def is_subset(set1,set2):
    "is set1 subset of set2"
    # if all element of set1 exists in set2
    for i in set1:
        if(exists(set2,i) == False):
            return False
    return True
def remove_all(set1):
    "removes all element from set1"
    for i in set1:
        set1.remove(i)
def is_super_set(set1,set2):
    "is set1 superset of set2"
    return is_subset(set2,set1)
#set1 = {1,1,1,1}
set1 = {1,2,3,4,5}
set2 = {4,5,6,7,8}
print(take_union(set1,set2))
print(take_intersection(set1,set2))
print(minimum(set1))
print(maximum(set1))
print(create_shallow_copy(set1))
print(is_subset(set1,set2))
print(is_super_set(set2,set2))
