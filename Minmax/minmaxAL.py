
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
     valueai = float("-inf")
     valuesai = []
     indexsai = []

     if playerTurn == "ai":
         for i in range(len(state)):
             for j in range(len(state)):
                   if state[i][j] == " ":
                         state[i][j] = 'X'
                         #print(state,'ai')
                         v_ai= Minmax(state, 'human')
                         #print(v_ai,'ai')
                         valuesai.append(v_ai)
                         indexsai.append((i,j))
                         state[i][j] = ' '
                         valueai = max(valueai,v_ai)

         indx = valuesai.index(max(valuesai))

         return valueai,indexsai[indx]


     if playerTurn == "human":
         valueh = float("inf")
         valuesh=[]
         for i in range(len(state)):
             for j in range(len(state)):
                   if state[i][j] == " ":
                         state[i][j] = 'O'
                         #print(state,'human')
                         v_h = Minmax(state, 'ai')
                         if isinstance(v_h,int):
                              v_h = v_h
                         else:
                             v_h = v_h[0]
                         # print(v_h)
                         # print(v_h,'human')

                         valuesh.append(v_h)
                         state[i][j] = ' '
                         valueh = min(valueh,v_h)
         return valueh


ai = 'X'
player = 'O'
tic_tac_toe = [['O', 'X',' '],
               ['X', 'X', 'O'],
               [' ', 'O', ' '],]
# index =Minmax(tic_tac_toe,'ai')
# print(index)
pos = {}
c=1
for i in range(3):
    for j in range(3):
        pos[c] = (i,j)
        c+=1

pos2 = {c: (i, j) for c, (i, j) in enumerate(((i, j) for i in range(3) for j in range(3)), start=1)}


print("Welcome to minmax game!")
print("You are human, and your symbol is O")
print("You are playing against AI, let's see how well you will play")
print("Enter a number to place the symbol,")
print("for example, 1 refers to 1st position and so on, only allowed 1 to 9")

while True:

    if(checkWin(tic_tac_toe)):
         for i in tic_tac_toe:
            print(i)
         if checkWin(tic_tac_toe)== 'd':
             print('The game is draw')
         elif checkWin(tic_tac_toe)== 'O':

            print('Congratulation! You have won the game')
         elif checkWin(tic_tac_toe)== 'X':
             print('ohh! AI have won the game')
         exit(0)
    else:
        for i in tic_tac_toe:
            print(i)
        print("No one has won the game")
        h = int(input("Your turn: "))
        if h>=1 and h <=9 :
            x,y = pos.get(h)
            if tic_tac_toe[x][y] == ' ':
                tic_tac_toe[x][y] = 'O'
            else:
                print("it is not empty")
                h = int(input("Your turn: "))


            res = Minmax(tic_tac_toe,'ai')
            if isinstance(res,int):
                continue
            else:
                found_key = next((k for k, v in pos.items() if v == res[1]), None)
                m,n = res[1]
                tic_tac_toe[m][n] = 'X'
                print('AI has put X on ', found_key)







# [['O', 'X', ' '],
#  ['X', 'X', 'O'],
#  [' ', 'O', ' '], ]