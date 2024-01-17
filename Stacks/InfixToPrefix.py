

import operator

def reverseString(strings):

     length = len(strings)
     strings = list(strings)
     for i in range(length//2):
         temp = strings[i]
         strings[i] = strings[length - i -1]
         strings[length - i - 1] = temp

     return "".join(strings)

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
        return  "R"
    else:
        return "L"

def InfixToPrefix(string):

    stack = []
    preFixItems =[]
    string = reverseString(string)

    for char in string:

        if char.isalnum():
            preFixItems.append(char)
        elif len(stack) == 0 or char == ")" or stack[-1] == ")":
            stack.append(char)

        elif char == "(":
            while stack and stack[-1] != ")":
                preFixItems.append(stack.pop())
            stack.pop()

        else:
            while stack and (precedence(char) < precedence(stack[-1]) or (
                       precedence(char) == precedence(stack[-1]) and associativity(char) == "R")):
                popItem = stack.pop()
                preFixItems.append(popItem)
            stack.append(char)

    while stack:
        preFixItems.append(stack.pop())

    return reverseString("".join(preFixItems))


def putValues(string, values):
    res = ''
    for i, v in enumerate(string):
        if v.isalpha():
            res += ' '+str(values.get(v))
        else:
            res += v
    return res

def compute(x,y,op):
    operators = {'+': operator.add, '-': operator.sub, '*': operator.mul,
                 '^': operator.pow, '/': operator.floordiv}
    if op in operators:
        result = operators[op](x, y)
        return  result
    else:
        print("Invalid operator")
def ComputeExpression( expression,values):

    result = InfixToPrefix(expression)
    stack = []
    for char in reversed(result):
         if char.isalnum():
             stack.append(char)

         else:
             if isinstance(stack[-1],int) and isinstance(stack[-1],int) :
                 x = stack.pop()
                 y = stack.pop()
             else:
                 x = values.get(stack.pop())
                 y = values.get(stack.pop())

             res = compute(x,y,char)
             stack.append(res)
    return stack



if __name__ == "__main__":


    exps1= "k+l-m*n+(o^p)*w/u/v*t+q"
    exps2 = "(a–b/c)*(a/k-l)"
    exp3 = "a*b+c/d"
    values = {'a': 14, 'b': 19, 'c': 16, 'd': 2}
    print(ComputeExpression(exp3,values))
    print("infixToPrefix",InfixToPrefix(exps2))






