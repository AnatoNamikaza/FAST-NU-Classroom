'''Form a queue such that it works in FIFO order (10 marks)'''
class queue:
    def __init__(self):
        self._list = []
    def enqueue(self,x):
        self._list.append(x)
    def dequeue(self):
        if(len(self._list) > 0):
            athead = self._list[0]
            self._list.remove(self._list[0])
            return(athead)
        else:
            print("empty queue")
    def show(self):
        print(self._list)
    def get_size(self):
        return(len(self._list))
myqueue = queue()
myqueue.dequeue()
myqueue.enqueue(1)
myqueue.enqueue(2)
myqueue.enqueue(3)
myqueue.enqueue(4)
myqueue.show()

print("removing from head")
queue_size = myqueue.get_size()
for i in range(queue_size):
    print(myqueue.dequeue())
print("after all element removed")
myqueue.show()
