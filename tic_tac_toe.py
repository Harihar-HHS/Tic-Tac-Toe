'''
This program simulates the working model of the Tic Tac Toe game.
Author : Hariharasubramanian.V
'''

a=[[-1 for i in range(3)] for j in range(3)]

def iswin():
    f=0
    value="-1"
    if(a[0][0]==a[0][1] and a[0][2]==a[0][0]  and a[0][0]!=-1):          # row 1
        return 1,a[0][0]
    elif(a[1][0]==a[1][1] and a[1][2]==a[1][0] and a[1][0]!=-1):        # row 2
        return 1,a[1][0]
    elif(a[2][0]==a[2][1] and a[2][2]==a[2][0] and a[2][0]!=-1):        # row 3
        return 1,a[2][0]
    elif(a[0][0]==a[1][0] and a[0][0]==a[2][0] and a[0][0]!=-1):        # col 1
        return 1,a[0][0]
    elif(a[0][1]==a[1][1] and a[0][1]==a[2][1] and a[0][1]!=-1):        # col 2
        return 1,a[0][1]
    elif(a[0][2]==a[1][2] and a[0][2]==a[2][2] and a[0][2]!=-1):        # col 3
        return 1,a[0][2]
    elif(a[0][0]==a[1][1] and a[0][0]==a[2][2] and a[0][0]!=-1):        # diag 1
        return 1,a[0][0]
    elif(a[0][2]==a[1][1] and a[0][2]==a[2][0] and a[0][2]!=-1):        # diag 2
        return 1,a[0][2]
    
    return f,value                          # just to try returning multiple values

def plot():
    for i in range(3):
        print("-"*19)
        print("|",end="  ")
        for j in range(3):
            if(a[i][j]==1):
                 print("X  |  ",end="")
            elif(a[i][j]==0):
                 print("O  |  ",end="")
            else:
                 print("   |  ",end="")
        print()
    print("-"*19)


def update(r,c,i):
    if(a[r-1][c-1]==-1):
        if(i%2==0):
            a[r-1][c-1]=1
        else:
            a[r-1][c-1]=0
        return 0
    else :
        return 1
        

def tic_tac_toe():
    print("Board =>")
    plot()
    i=0
    print("Input row no. and col no.\n")
    while(i<9):
        print()
        if(i%2==0):
            print("X's turn")
        else:
            print("O's turn")
        r=(int)(input("row no. : "))
        c=(int)(input("col no. : "))
        if(update(r,c,i)):
            print("Already filled!!!!!!!!!!!!!!!!!!!\n\nTry again")
            i=i-1
        plot()
        i=i+1
        f,val=iswin()
        if(f==1):
            print("\n\nGame over\n\n",end="")
            if(val==1):
                print("X",end="")
            else :
                print("O",end="")
            print(" wins!!!!!!")
            break
    if(f==0):
        print("\n\nDraw!!!!!")

tic_tac_toe()
