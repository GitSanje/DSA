

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
            res += ' '+str(values.get(v)) + ' '
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

    preFix = InfixToPrefix(expression)
    result = putValues(preFix, values)

    print(reverseString(result))
    stack = []
    for char in reversed(result):

         if char.isnumeric():
             stack.append(char)
         elif char == ' ':
             continue
         else:
             print("beforepop",stack)
             x = stack.pop()
             y = stack.pop()
             print("afterpop",stack)

             res = compute(int(x),int(y),char)
             print("aftercompute", res)
             stack.append(res)
    return stack

val2 = "a*b+c/d"
values2 = {'a':5,'b':4,'c':8,'d':2}
values = {'a':14,'b':19,'c':16,'d':2}

print(ComputeExpression(val2, values))





if __name__ == "__main__":

    val2 = "a*b+c/d"


    val3= "k+l-m*n+(o^p)*w/u/v*t+q"
    val4 = "(a–b/c)*(a/k-l)"
    s = "x+y*z/w+u"

    # print(InfixToPrefix(s))
    # print(InfixToPrefix(val4))
    # print(InfixToPrefix(val3))





