def precedence(operator):

    precedence_dict = {'+': 1, '-': 1, '*': 2, '/': 2,'^':3}
    return precedence_dict.get(operator, 0)
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


class BinaryTreeExp:
    def __init__(self):
        self.root = None

    def insert(self,exps,current_node =None,flag=None):

        stack = []
        for i, char in enumerate(exps):
            if not char.isalnum():
                stack.append((i, precedence(char)))

        stack = sorted(stack, key=lambda x: x[1], reverse=True)
        #print(flag,exps,stack)
        if not stack:
            if flag =="left":
                 current_node.left = exps
                 value = current_node.left
            else:
                current_node.right = exps
                value = current_node.right
            return value
        idx = stack[-1][0]
        node = exps[idx]
        left = exps[:idx]
        right = exps[idx + 1:]

        if current_node is None:
            self.root = Node(node)
            self.insert(left, self.root, "left")
            self.insert(right, self.root, "right")
        else:
            if flag == "left":
                current_node.left = Node(node)
                self.insert(left, current_node.left, "left")
                self.insert(right, current_node.left, "right")
            elif flag == "right":
                current_node.right = Node(node)
                self.insert(left, current_node.right, "left")
                self.insert(right, current_node.right, "right")

        return current_node



    def recurTree(self,node=None):
        stack = []
        if node is None:
            node = self.root
            stack.append(('root',node.value))

        if isinstance(node,str) :
            stack.append(('leaf',node))
        else:
            left_str = self.recurTree(node.left)

            stack.append(('L',node.value,left_str))
            right_str = self.recurTree(node.right)
            stack.append(('R', node.value,right_str))

        return stack


    def __str__(self):
        return f"Prefix:{self._preorder(self.root)}, \nPostfix:{self._postorder(self.root)}"

    def _preorder(self, node):
        if node is None:
            return ""
        if isinstance(node,str):
            return f"{node}"
        else:
            left_str = self._preorder(node.left)
            right_str = self._preorder(node.right)
            return f"{node.value}{left_str}{right_str}"
    def _postorder(self, node):
        if node is None:
            return ""
        if isinstance(node,str):
            return f"{node}"
        else:
            left_str = self._postorder(node.left)
            right_str = self._postorder(node.right)
            return f"{left_str}{right_str}{node.value}"


exps = "a*b+c/d*y+s*u^l" # prefix: ++*ab*/cdy*su, Postfix: ab*cd/y*+su*+

exptree = BinaryTreeExp()
exptree.insert(exps)
print(exptree)
stack = exptree.recurTree()
# for values in stack:
#     print(values)



# tree = BinaryTree()

# List of inputs
# input_list = [5, 3, 8, 2, 4, 7, 9]

# Inserting elements into the tree
# for element in input_list:
#     tree.insert(element)

# # Performing an inorder traversal
# print("Inorder Traversal:")
# tree.inorder_traversal(tree.root)





