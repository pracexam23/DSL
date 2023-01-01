mrk=[25,22,18,6,"ab",8,24,11,18,17,15,17,7,23,25,28,"ab","ab",29,27]
def F1():
    suma=0
    for i in mrk:
        if i !="ab":
            suma=suma+i
    print("Average Score is ",suma/len(mrk))

def F2():
    maxa=0
    for p in mrk:            
        if p!="ab":
            if p >maxa:
                maxa=p
    print("Highest Score is ",maxa)
    mina=30
    for q in mrk:
        if q !="ab":
            if q<mina:
                mina=q
    print("Lowest Score is ",mina)
    
def F3():
    cnt=0
    for i in mrk:
        if i=="ab":
            cnt=cnt+1
    print("No. Absent Students is ",cnt)

def F4():
    for i in mrk:
        mf=0
        
        if counta(i)>mf:
            mf=counta(i)
            mfn=i
    print("Highest Frequency Marks is ",mfn)

def counta(z):
    cnta=0
    for i in mrk:
        if i==z:
            cnta=cnta+1
    return cnta            

while True:
    print("""\n1) The average score of class.
             \n2) Highest score and lowest score of class.
             \n3) Count of students who were absent for the test.
             \n4) Display mark with highest frequency.
             \n5) Exit
             \nEnter Choice : """)
    ch=input()
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
        print("Invalid Input!!!!")
