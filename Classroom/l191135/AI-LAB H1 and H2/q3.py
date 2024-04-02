'''Create a class for rectangle shape that calculates its area based upon the length and width'''

class rectangle():
    def __init__(self,l,w):
        self.length = l
        self.width = w
    def get_area(self):
        return(self.length * self.width)

r = rectangle(2,3)
print(r.get_area())
