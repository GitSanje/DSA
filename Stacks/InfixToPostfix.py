import  operator
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




def compute(x,y,op):
    operators = {'+': operator.add, '-': operator.sub, '*': operator.mul,
                 '^': operator.pow, '/': operator.floordiv}
    if op in operators:
        result = operators[op](x, y)
        return  result
    else:
        print("Invalid operator")
def ComputeExpression( expression,values):

    result = InfixToPosfix(expression)
    stack = []
    for char in result:
         if char.isalnum():
             stack.append(char)

         else:
             if isinstance(stack[-1],int) and isinstance(stack[-1],int) :
                 x = stack.pop()
                 y = stack.pop()
             else:
                 x = values.get(stack.pop())
                 y = values.get(stack.pop())

             res = compute(y,x,char)
             stack.append(res)
    return stack


if __name__ == '__main__':
    s = "x+y*z/w+u"
    test = "a+b*(c^d-e)^(f+g*h)-i"
    exps1 = "k+l-m*n+(o^p)*w/u/v*t+q"
    exp3 = "a*b+c/d"
    values = {'a': 14, 'b': 19, 'c': 16, 'd': 2}
    print(ComputeExpression(exp3, values))
    print(InfixToPosfix(exps1))