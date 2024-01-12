
from sys import maxsize
class Stack:
  def __init__(self,data=None):
      if data is not None:
        self.stack = [i for i in data]
      else:
        self.stack =[]
      self.size = len(self.stack)

  def pop(self):
      if len(self.stack) == 0:
          return str(-maxsize -1)
      else:
         val= self.stack[self.size-1]
         del self.stack[self.size-1]
         self.size = self.size-1
         print(f"popItem:{val}")
         return  self.stack, val

  def peek(self):
      if len(self.stack) == 0:
          return str(-maxsize -1)
      else:
          print(self.stack[-1])
          return self.stack[-1]

  def push(self,val):
      self.stack.append(val)
      return self.stack

  def __str__(self):
      return " | ".join(str(i) for i in self.stack)

objStack = Stack()
objStack.push(23)
objStack.push("Hi")
objStack.push("bob Marley")


print(f"before pop: {objStack}")
objStack.pop()
print(f"After pop: {objStack}\n")

print(f"before peek: {objStack}")
objStack.peek()
print(f"After peek: {objStack}")


objStack2 = Stack([34,435,244,"sanjay"])
print(objStack2)
