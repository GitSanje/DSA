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


def InfixToPosfix(string):

    stack = []

    postfixItems = []
    for char in string:

        if char.isalnum():
            postfixItems.append(char)

        elif len(stack) == 0 or stack[-1] == "(" or char == "(":
               stack.append(char)

        elif char == ")":
            while stack and stack[-1] != "(":
                popItem = stack.pop()
                postfixItems.append(popItem)
            stack.pop()
        else:
            while stack and (precedence(char) < precedence(stack[-1]) or (
                       precedence(char) == precedence(stack[-1]) and associativity(char) == "L")):
                popItem = stack.pop()
                postfixItems.append(popItem)
            stack.append(char)




    while stack:
        postfixItems.append(stack.pop())


    return "".join(postfixItems)





if __name__ == '__main__':
    s = "x+y*z/w+u"
    test = "a+b*(c^d-e)^(f+g*h)-i"
    test1 = "A*B+C/D"


    print(InfixToPosfix(test))