rnos=[]

def accept(n):
    for i in range(n):
        rnos.append(int(input()))

def linsch(x):
    a=0
    for i in range(len(rnos)):
        if rnos[i] == x:
            print("Match Found at index no. : ",i)
            a=1
    if a==0:
        print("Element not found!")
    

def sensch(x):
    n=len(rnos)
    last = rnos[n - 1]
    rnos[n - 1] = x;
    i = 0
 
    while (rnos[i] != x):
        i=i+1

    rnos[n - 1] = last

    if ((i < n - 1) or (rnos[n - 1] == x)):
        print("Element present at index",i)
    else:
        print("Element not present")


while True:
    print("""\n1).Enter Roll no.
             \n2)Linear Search.
             \n3)Sentinal Search.
             \n4)Exit.
             \nEnter Choice = """)
    ch=input()
    if(ch=='1'):
        p=int(input("Enter No. of Students : "))
        accept(p)
    elif(ch=='2'):
        q=int(input("Enter Value to be searched : "))
        linsch(q)
    elif(ch=='3'):
        r=int(input("Enter Value to be searched : "))
        sensch(r)
    elif(ch=='4'):
        break
    else:
        print("Enter Valid Input!!!!!")
