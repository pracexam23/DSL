'''Write a Python program to store second year percentage of students in array. Write
function for sorting array of floating point numbers in ascending order using
a) Insertion sort
b) Shell Sort and display top five scores'''

per=[]

def accept(n):
    print("Enter Percentages : ")
    for i in range(n):
        per.append(int(input()))
    

def InsertionSort():
    inper=per
    for i in range(1, len(inper)):
        key = inper[i]
        j = i-1
        while j >= 0 and key < inper[j] :
                inper[j + 1] = inper[j]
                j -= 1
        inper[j + 1] = key
    print(inper)

def shellSort():
    shellper=per
    gap=len(shellper)//2
    while gap>0:
        j=gap
        while j<len(shellper):
            i=j-gap
            while i>=0:
                if shellper[i+gap]>shellper[i]:
                    break
                else:
                    shellper[i+gap],shellper[i]=shellper[i],shellper[i+gap]
                i=i-gap 
            j+=1
        gap=gap//2
    print(shellper)

while True:
    print("""\n1)Store Percentage of Student.
             \n2)Insertion sort.
             \n3)Shell Sort.
             \n4)Exit.
             \nEnter Choice = """)
    ch=input()
    if(ch=='1'):
        p=int(input("Enter No. of Students : "))
        accept(p)
    elif(ch=='2'):
        InsertionSort()
        
    elif(ch=='3'):
        shellSort()
    elif(ch=='4'):
        break
    else:
        print("Enter Valid Input!!!!!")

