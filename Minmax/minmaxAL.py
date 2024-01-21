
ai = 'X'
player = 'O'
tic_tac_toe = [['O', 'O','X'],
               ['O', 'X', ' '],
               ['X', 'O', 'X'],]
def checkDiagonal(state):
    L = len(state)
    c = L - 1
    x=L-2
    for i in range(L):
           if (state[i][i] != state[(i+1)%L][(i+1)%L]
                   and state[i][c] != state[(i+1)%L][x]):
                return False
           c -= 1
           x -= 1
    return state[x][x]
def checkRow(state):
     for s in state:
         s = "".join(s)
         if (s == (len(s) * s[0])):
             return s[0]
     return False


def checkCol(state):
    L=len(state)
    for i in range(L):
        x = state[0][i]
        y = state[1][i]
        z = state[2][i]
        if x == y == z:
            return x
    return False

def checkWin(state):
   if checkDiagonal(state):
       return "diag "+checkDiagonal(state)
   elif checkRow(state):
       return "Row "+checkRow(state)
   elif checkCol(state):
       return "Col "+checkCol(state)
   else:
       return False

print(checkWin(tic_tac_toe))
