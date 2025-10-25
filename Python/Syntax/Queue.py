class Queue:
    
    def __init__(objr):
        objr.item1=[]
    
    def enqueue(objr,elmnt):
        objr.item1.append(elmnt)
        
    def dequeue(objr):
        return objr.item1.pop(0)
    
    def isEmpty(objr):
        return not bool(objr.item1)
    
    def peek(objr):
        if objr.isEmpty():
            return "Stack is Empty"
        return objr.item1[-1]
    
    def size(objr):
        return len(objr.item1)
    
    
obj2=Queue()
obj2.enqueue('A')
obj2.enqueue('B')
obj2.enqueue('C')

print("Queue: ", obj2.item1)
print("Peek: ", obj2.peek())
print("Dequeue: ", obj2.dequeue())
print("Queue after Dequeue: ", obj2.item1)
print("isEmpty: ", obj2.isEmpty())
print("Size: ", obj2.size())