''' Write a Python program to convert a tuple to a dictionary. '''
mytuple = (1, 2, 3)
keys = ("one","two","three")
mydic = {keys[x]:mytuple[x] for x in range(len(mytuple))}
print(mytuple)
print(mydic)
