'''Q:3 Write a function to add, mul, divide two numbers x and y. Implement exception handling
technique(try..except clause) for handling possible exceptions in the scenario.'''
def add(*x):
    result = 0;
    for i in x:
        result = result + i
    return result

def mult(*x):
    result = 1;
    for i in x:
        result = result * i
    return result

def divide(x,y):
    "x/y"
    try:
        return x/y
    except ZeroDivisionError as e:
        print(e)


print(add(2,3,1,2,2,2))
print(mult(2,3))
print(divide(2,0))
