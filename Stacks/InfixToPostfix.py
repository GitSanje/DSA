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
    for chr in string:

        if chr.isalnum():
            postfixItems.append(chr)

        elif len(stack) == 0 or stack[-1] == "(":
               stack.append(chr)
        elif precedence(chr) > precedence(stack[-1]) or (
                       precedence(chr) == precedence(stack[-1]) and associativity(chr) == "R"):

             stack.append(chr)
        else:
            while stack and  stack[-1] != "(" and precedence(chr) <= precedence(stack[-1]):
                popItem = stack.pop()
                postfixItems.append(popItem)
            stack.append(chr)

        if chr == ")":
            while stack and stack[-1] != "(":
                popItem = stack.pop()
                postfixItems.append(popItem)
            stack.pop()


    while stack:
        postfixItems.append(stack.pop())


    print("".join(postfixItems))


test = "a+b*(c^d-e)^(f+g*h)-i"
InfixToPosfix(test)