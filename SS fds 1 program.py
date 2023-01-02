A=["A","B","C","D","E"]
B=["B","C","Z","F","G"]
C=["C","D","S","Q","R"]

def F1():
    D=[]
    for i in A:
        if i not in D:
            D.append(i)
    for i in B:
        if i not in D:
            D.append(i)
    print(D)

def F2():
    D=[]
    for i in A:
        if i not in B:
            D.append(i)
    for i in B:
        if i not in A:
            D.append(i)
    print(D)

def F3():
    D=[]
    for i in C:
        if i not in A and B:
            D.append(i)
    print(D,"\n Count = ",len(D))

def F4():
    D=[]
    for i in A :
        if i not in B:
            D.append(i)
    for i in C :
        if i not in B:
            D.append(i)
   
    print(D,"\n Count = ",len(D))

while True:
    print("""\n1) List of students who play both cricket and badminton.
             \n2) List of students who play either cricket or badminton but not both.
             \n3) Number of students who play neither cricket nor badminton.
             \n4) Number of students who play cricket and football but not badminton.
             \n5)Exit.""")
    ch=input("\nEnter choice : ")
    if(ch=='1'):
        F1()
    elif(ch=='2'):
        F2()
    elif(ch=='3'):
        F3()
    elif(ch=='4'):
        F4()
    elif(ch=='5'):
        break
    else:
        print("Invalid input!!!")
