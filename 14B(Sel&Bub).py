'''Write a Python program to store first year percentage of students in per. Write
function for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.'''

per=[]

def accept(n):
    for i in range(n):
        per.append(int(input()))
    

def selectionSort():
    selper=per
    for i in range(len(selper)-1):
        for j in range(i + 1, len(selper)):
            if selper[j] < selper[i]:
                temp=selper[i]
                selper[i]=selper[j]
                selper[j]=temp
    print(selper)
    

def BubbleSort():
    buper=per
    n = len(buper)
    for i in range(n):
        for j in range(0, n-i-1):
            if buper[j] > buper[j+1]:
                buper[j], buper[j+1] = buper[j+1], buper[j]
    print(buper)

while True:
    print("""\n1)Store Percentage of Student.
             \n2)Selection Sort.
             \n3)Bubble sort.
             \n4)Exit.
             \nEnter Choice = """)
    ch=input()
    if(ch=='1'):
        p=int(input("Enter No. of Students : "))
        accept(p)
    elif(ch=='2'):
        selectionSort()
        
    elif(ch=='3'):
        BubbleSort()
    elif(ch=='4'):
        break
    else:
        print("Enter Valid Input!!!!!")
        
