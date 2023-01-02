def accept_Array(A):
   n=int(input("Enter the total number of student:"))
   for i in range(n):
       x=int(input("\nEnter the roll no of student %d:"%(i+1)))
       A.append(x)
   print("\nStudent array accepted successfully")
   return n
   
def display_Array(A,n):
   if(n==0):
       print("\nNo records in the database")
   else:
       print("\nStudents array:",end=' ')
       for i in range(n):
           print("%d"%A[i],end=' ')
       print("\n");
       
def linear_search(A,n,x):
    for i in range(n):
        if(A[i]==x):
            return i
    return -1
    
def sentinal_search(A,n,x):
    last=A[n-1]
    i=0
    A[n-1]=x
    while(A[i]!=x):
        i=i+1
    A[n-1]=last
    if((i<n-1) or (x==A[n-1])):
        return i
    else:
        return -1
        
def Main():
    A=[]
    while True:
        print("\t1:Accept and display student info")
        print("\t2:Linear search")
        print("\t3:Sentinal search")
        print("\t4:Exit")
        ch=int(input("\nEnter your choice="))
        if(ch==4):
            print("End of program")
            quit()
        elif(ch==1):
            A=[]
            n=accept_Array(A)
            display_Array(A,n)
        elif(ch==2):
            x=int(input("Enter the roll no to be searched="))
            flag=linear_search(A,n,x)
            if(flag==-1):
                print("\nRoll no to be searched not found")
            else:
                print("\nRoll no is at location %d"%(flag+1))
        elif(ch==3):
            x=int(input("\nEnter the roll no to be searched="))
            flag=sentinal_search(A,n,x)
            if(flag==-1):
                print("\nRoll no to be searched not found")
            else:
                print("\nRoll no is at location %d"%(flag+1))
        else:
            print("Wrong choice entered!!Try again")
            
Main()
        
        
        
        
