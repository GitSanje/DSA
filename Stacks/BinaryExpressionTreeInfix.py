def precedence(char):
    if char == "^":
        return 3
    elif char == '*' or char == '/':
        return 2
    elif char == '+' or char == '-':
        return 1
    else:
        return -1
def associativity(char):
    if char == "^":
        return "R"
    else:
        return "L"
class Node:
    def __init__(self,value):
        self.left = None
        self.right = None
        self.value = value

class BinaryTree:
    def __init__(self):
        self.root = None

    def insert(self,value):

        if not self.root:
            self.root = Node(value)
        else:
            self._insert_recursive(value,self.root)

    def _insert_recursive(self, value, current_node):
        if  value < current_node.value:
            if current_node.left is None:
                current_node.left = Node(value)
            else:
                self._insert_recursive(value, current_node.left)
        elif value > current_node.value:
            if current_node.right is None:
                current_node.right = Node(value)
            else:
                self._insert_recursive(value, current_node.right)

    def inorder_traversal(self, root):
        if root:
            self.inorder_traversal(root.left)
            print(root.value, end=" ")
            self.inorder_traversal(root.right)


tree = BinaryTree()

# List of inputs
input_list = [5, 3, 8, 2, 4, 7, 9]

# Inserting elements into the tree
for element in input_list:
    tree.insert(element)

# Performing an inorder traversal
print("Inorder Traversal:")
tree.inorder_traversal(tree.root)



exps = "a*b+c/d"
