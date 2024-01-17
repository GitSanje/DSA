
def PostfixToInfix(exp):

    stack =[]
    for char in reversed(exp):
        if char.isalnum():
            stack.append(char)
        else:
            x = stack.pop()
            y= stack.pop()
            z = x+char+y
            stack.append(z)
    return "".join(stack)

exp1 = "*–a/bc-/akl"
exp2="abcd^e-fgh*+^*+i-"
print(PostfixToInfix(exp1))