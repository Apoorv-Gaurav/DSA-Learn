# Singly Linked Lists
class SinglyNode:
    def __init__(self,val,next=None):
        self.val=val
        self.next=next
'''
    def __str__(self):
        return str(self.val)
'''
head=SinglyNode(1)
A=SinglyNode(3)
B=SinglyNode(4)
C=SinglyNode(7)

head.next = A
A.next = B
B.next = C

#Traverse the list - 0(n)
curr=head
while curr:  #head → A → B → C → None
    print(curr.val)    #print(curr.__str__())
    curr = curr.next
#Output: 1 3 4 7

#Display the linked list -0(n)
def display(head):
    curr= head
    elements=[]
    while curr:
        elements.append(str(curr.val))
        curr = curr.next
    print(' --> '.join(elements))

display(head) # 1 --> 3 --> 4 --> 7

#Search for node value - 0(n)
def search(head, val):
    curr=head
    while curr:
        if val == curr.val:
            return True
        curr = curr.next
    return False

print(search(head,2))
print(search(head,3))

#-------------------------------------------------------------
#Doubly Linked List
# 
class DoublyNode:
    def __init__(self,val,next=None, prev=None):
        self.val = val
        self.next = next
        self.prev = prev

    def __str__(self):
        return str(self.val)
    
head = tail = DoublyNode(1)
print(tail)

    #Display - 0(n)
def display(head):
    curr=head
    elements=[]
    while curr:
        elements.append(str(curr.val))
        curr= curr.next
    print(' <-> '.join(elements))
display(head)

# Insert at beginning - 0(1)
def insert_at_beginning(head,tail,val):
    new_node = DoublyNode(val, next=head)
    head.prev = new_node
    return new_node, tail
head, tail = insert_at_beginning(head, tail, 3)
display(head)

# Insert at end - 0(1)
def insert_at_beginning(head,tail,val):
    new_node = DoublyNode(val, prev=tail)
    tail.next = new_node
    return head, new_node
head, tail = insert_at_beginning(head, tail, 3)
display(head)