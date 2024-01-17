
def PostfixToInfix(exp):

    stack =[]
    for char in exp:
        if char.isalnum():
            stack.append(char)
        else:
            x = stack.pop()
            y= stack.pop()
            z = y+char+x
            stack.append(z)
    return "".join(stack)

exp1 = "ab*cd/+"
exp2="abcd^e-fgh*+^*+i-"
exp3="kl+mn*-op^w*u/v/t*+q+"
print(PostfixToInfix(exp3))