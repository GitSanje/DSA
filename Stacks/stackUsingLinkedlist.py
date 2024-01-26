

class Node:
    def __init__(self,data):
        self.data = data
        self.next = None

class Stack:
    def __init__(self):
        self.head = None

    def push(self,data):
        newNode = Node(data)
        newNode.next = self.head
        self.head = newNode
        print(f"pushItem:{data}")

    def isEmpty(self):
        return True if self.head is None else False
    def pop(self):
        if self.isEmpty():
            return float("-inf")
        tempNode = self.head
        self.head = self.head.next
        print(f"popedItem:{tempNode.data}")
        return tempNode

    def peek(self):
        if self.isEmpty():
            return float("-inf")
        return self.head.data

    def __str__(self):
        current = self.head
        items =[]
        while current:
            items.append(str(current.data))
            current= current.next
        return  "|->".join(items)






stck = Stack()
stck.push(43)
stck.push("myStack")
stck.push("This is me")
stck.push("California")
stck.push(22)
stck.pop()

print(stck)