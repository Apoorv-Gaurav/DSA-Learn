class Stack:
    def __init__(objr):
        objr.item1=[]
        objr.item2="Heloo"
        
    def push(objr,elmnt):
        objr.item1.append(elmnt)
    
    def pop(objr):
        return objr.item1.pop()
        
    def isEmpty(objr):
        return not bool(objr.item1)
    
    def peek(objr):
        if objr.isEmpty():
            return "Stack is Empty"
        return objr.item1[-1]
    
    def size(objr):
        return len(objr.item1)
        
    
obj1=Stack()

obj1.push('A')
obj1.push('B')
obj1.push('C')

print("Stack: ", obj1.item1)
print("Pop: ", obj1.pop())
print("Stack after Pop: ", obj1.item1)
print("Peek: ", obj1.peek())
print("isEmpty: ", obj1.isEmpty())
print("Size: ", obj1.size())
    
