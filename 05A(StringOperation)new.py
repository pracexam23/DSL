def one():
    str=input("Enter the string")
    s=str.split()
    max=0
    for ele in s:
        if len(ele)>max:
            max=len(ele)
            max_word=ele
    print("word with maximum length string is:",max_word)
    print("maximum length is:",len(max_word))

def two():
    str1=input("Enter the string:")
    char=input("Enter the character:")
    print(str1)
    counter=0
    for i in range(len(str1)):
        if char==str1[i]:
            counter+=1
    print("character %s is present %i times in string %s" %(char,counter,str1))

def three():
    str1=input("Enter the string")
    lenstr1=len(str1)
    j=lenstr1-1
    flag=0
    for i in range(int(lenstr1/2+1)):
        if (str1[i]==str1[j]):
            flag=1
        else:
            break
        j=-1
    if (flag==1):
        print("It is palindrome")
    else:
        print("It is not palindrome")

def four():
    str1=input("Enter string:")
    sub1=input("Enter the substring:")
    sublen=len(sub1)
    index=0
    j=0
    for i in range (len(str1)):
        if(sub1[j]==str1[i]):
            j=j+1
            if(j==sublen):
                index1=i-(sublen-1)
                break
        else:
            j=0
    print("Substring index:",index1)

def five():
    str1=input("Enter string:")
    list1=str1.split()
    list2=set(list1)
    list3=list(list2)
    print(list1)
    print(list3)
    list4=[]
    list5=[]
    counter=0
    for i in range(len(list3)):
        counter=0
        for j in range (len(list1)):
            if(list3[i]==list1[j]):
                counter+=1
        list4=list3[i],counter
        list5.append(list4)
    print(list5)
while True:
        ch=int(input("Enter your choice"))
        if(ch==1):
            one()
        elif(ch==2):
            two()
        elif(ch==3):
            three()
        elif(ch==4):
            four()
        elif(ch==5):
            five()
        elif(ch==6):
            print("End of program")
            break
