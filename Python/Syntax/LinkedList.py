#Singly Linked Lists

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