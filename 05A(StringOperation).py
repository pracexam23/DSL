#Write a Python program to compute following operations on String:
#a) To display word with the longest length
#b) To determines the frequency of occurrence of particular character in the string
#c) To check whether given string is palindrome or not
#d) To display index of first appearance of the substring
#e) To count the occurrences of each word in a given string



def lstri():
	stl=0
	for i in st:
		if len(i)>stl:
			lstr=i
			stl=len(i)
	print("Longest string is : ",lstr)

def fpstr():
	fpc=0
	fp=input("Enter string : " )
	if fp in st:
		for i in st:
			if i== fp:
				fpc=fpc+1
		print(fp,"is present ",fpc,"times in string")
	else:
		print("Entered String is not present!!!")
		
def pcstr():
	a=[]
	for i in st:
		if i not in a:
			a.append(i)
			if i==i[::-1]:
				print(i," is palindrome")
			else :
				print(i," is not palindrome")
				
def ocstr():
	a=[]
	for i in st:
		
		if i not in a:
			a.append(i)
			print("Occurance of ",i," is ",st.count(i))
			
			
			
			
st=[]
stro=input("Enter String : ")
st=stro.split(" ")

while(True):
	print("""\n1) To display word with the longest length
\n2) To determines the frequency of occurrence of particular character in the string
\n3) To check whether given string is palindrome or not
\n4) To display index of first appearance of the substring
\n5) To count the occurrences of each word in a given string
\n6) Exit
\nEnter Choice : """)
	ch=int(input())
	if ch==1:
		lstri()
	elif ch==2:
		fpstr()
	elif ch==3:
		pcstr()
	elif ch==4:
		substr=input("Enter Substring : ")
		print("Index no. is:",stro.find(substr))
	elif ch==5:
		ocstr()
	elif ch==6:
		print("Exiting.............")
		break
	else :
		print("\nEnter Vaild Input!!!!")
