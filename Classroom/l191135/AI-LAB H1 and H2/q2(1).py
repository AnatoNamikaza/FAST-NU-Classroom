'''Q2:Python program to count the number of vowels using sets in a given string.'''
# create empty set first
def isvovel(x):
    vovels = {'a','e','i','o','u'}
    for i in vovels:
        if(x.lower() == i):
            return True
    return False
vovels = []
user_input = "hhhh"

for i in user_input:
    if(isvovel(i)):
        vovels.append(i)
print(len(vovels))
