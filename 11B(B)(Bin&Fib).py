#Write a Python program to store roll numbers of student array who attended training
#program in sorted order. Write function for searching whether particular student
#attended training program or not, using Binary search and Fibonacci search


rnos=[]

def accept(n):
    for i in range(n):
        rnos.append(int(input()))
    sorted(rnos)

def binarySearch(x):
    l=0
    r=len(rnos)-1
    while l <= r:
        mid = l + (r - l) // 2
        if rnos[mid] == x:
            return mid
        elif rnos[mid] < x:
            l = mid + 1
        else:
            r = mid - 1
    return -1

    

def fibMonaccianSearch(x):
    n=len(rnos)
    fibMMm2 = 0 
    fibMMm1 = 1  
    fibM = fibMMm2 + fibMMm1
    while (fibM < n):
        fibMMm2 = fibMMm1
        fibMMm1 = fibM
        fibM = fibMMm2 + fibMMm1
    offset = -1
    while (fibM > 1):
        i = min(offset+fibMMm2, n-1)
        if (rnos[i] < x):
            fibM = fibMMm1
            fibMMm1 = fibMMm2
            fibMMm2 = fibM - fibMMm1
            offset = i 
        elif (rnos[i] > x):
            fibM = fibMMm2
            fibMMm1 = fibMMm1 - fibMMm2
            fibMMm2 = fibM - fibMMm1
        else:
            return i
    if(fibMMm1 and rnos[n-1] == x):
        return n-1
    return -1

while True:
    print("""\n1)Enter Roll no.
             \n2)Binary Search.
             \n3)Fibonacci Search.
             \n4)Exit.
             \nEnter Choice = """)
    ch=input()
    if(ch=='1'):
        p=int(input("Enter No. of Students : "))
        accept(p)
    elif(ch=='2'):
        q=int(input("Enter Value to be searched : "))
        result=binarySearch(q)
        if result != -1:
            print("Element is present at index " , result)
        else:
            print("Element is not present in array")
    elif(ch=='3'):
        r=int(input("Enter Value to be searched : "))
        ind = fibMonaccianSearch(r)
        if ind>=0:
            print("Found at index:",ind)
        else:
            print(r,"isn't present in the array")
    elif(ch=='4'):
        break
    else:
        print("Enter Valid Input!!!!!")
