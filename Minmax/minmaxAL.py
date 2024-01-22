
ai = 'X'
player = 'O'
tic_tac_toe = [['O', 'X',' '],
               ['X', 'X', 'O'],
               [' ', 'O', ' '],]



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
def checkEmptyStr(state):
    L= len(state)
    for i in range(L):
        if tic_tac_toe[0][i] == ' ' or tic_tac_toe[1][i] == ' ' or tic_tac_toe[2][i] == ' ':
                return True
    return False
def checkWin(state):
   if checkDiagonal(state):
       return checkDiagonal(state)
   elif checkRow(state):
       return checkRow(state)
   elif checkCol(state):
       return checkCol(state)
   elif checkEmptyStr(state) ==False:
       return 'd'
   else:
       return False



winners = {'X':1,'O':-1,'d':0}

def Minmax(state,playerTurn):
     if checkWin(state):
         return winners.get(checkWin(state))

     if playerTurn == "ai":
         value = float("-inf")
         valuesai=[]
         indexs = []
         for i in range(len(state)):
             for j in range(len(state)):
                   if state[i][j] == " ":
                         state[i][j] = 'X'
                         print(state,'ai')
                         v = Minmax(state, 'human')
                         print(v)
                         valuesai.append(v)
                         indexs.append((i,j))
                         state[i][j] = ' '
         # value = max(value,v)
         return valuesai

     if playerTurn == "human":
         value = float("inf")
         valuesh=[]
         for i in range(len(state)):
             for j in range(len(state)):
                   if state[i][j] == " ":
                         state[i][j] = 'O'
                         print(state,'human')
                         v = Minmax(state, 'ai')
                         valuesh.append(v)
                         state[i][j] = ' '
         # value = min(value,v)
         return valuesh


print(Minmax(tic_tac_toe,'ai'))

# [['O', 'X', ' '],
#  ['X', 'X', 'O'],
#  [' ', 'O', ' '], ]