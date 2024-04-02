#Task-1
nums = [1, 2, 3, 4, 5]
print(nums)
print("\nSquare and Cube of every number of the list:")
sqr_cube_nums = list(map(lambda x: (x ** 2, x ** 3), nums))
print(sqr_cube_nums)

#Task-2
from collections import deque as que_

from matplotlib.pyplot import table
Q = que_()
Q.append('a')
Q.append('b')
Q.append('c')
print(Q)
print("\n================\n")
print(Q.pop())

#Task-3
class rectangle:
    "This is a rectangle class."
    length  = 0
    width   = 0
    def __init__(self, len = 0, wid = 0):
        self.length = len
        self.width = wid

    def Area(self):
        return (self.length * self.width)    

rect_1 = rectangle(4,5)
print("\nArea of rectangle:")
print(rect_1.Area())