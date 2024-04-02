'''Write a Python class named Circle constructed by a radius and two methods
which will compute the area and the perimeter of a circle.'''

class circle():
    def __init__(self,r):
        self.radius = r
    def area(self):
        return(3.142*self.radius**2)
    def perimeter(self):
        return(2*3.142*self.radius)

c = circle(1)
print(c.area())
print(c.perimeter())
