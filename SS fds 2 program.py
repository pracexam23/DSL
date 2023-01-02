mrk=[25,22,18,4,14,15,"ab",28,12,25,17,19,20,"ab","ab","ab",30,29,21,2,8,9]
def F1():
     suma=0
     for i in mrk:
         if i !="ab":
             suma=suma+i
     print("\nAverage score is ",suma/len(mrk))

def F2():
     maxa=0
     for p in mrk:
         if p!="ab":
             if p>maxa:
                maxa=p
     print("\nHeighest score is=",maxa)                  
     mina=30
     for q in mrk:
         if q!="ab":
             if p<mina:
                mina=q
     print("\nLowest score is=",mina)
     
def F3():
     cnt=0
     for i in mrk:
         if i=="ab":
            cnt=cnt+1
     print("\nNumber of absent student is=",cnt)
     
def F4():
     for i in mrk:
         mf=0
         if counta(i)>mf:
              mf=counta(i)
              mfn=i
     print("Highest frequency Marks is=",mfn)
     
def counta(z):
     cnta=0
     for i in mrk:
         if i==z:
            cnta=cnta+1
     return cnta
     
while True:
      print("\t1:The average score of class=")
      print("\t2:The heighest score and lowest score =")
      print("\t3:Count of student who were absent for exam=")
      print("\t4:Marks with heighest frequency=")
      print("\t5:Exit")
      ch=input("Enter your choice=")
      if(ch=='1'):
        F1()
      elif(ch=='2'):
        F2()
      elif(ch=='3'):
        F3()
      elif(ch=='4'):
        F4()
      elif(ch=='5'):
        print("\nEnd of program.")
        break
      else:
        print("You have entered invalid choice")  

      
