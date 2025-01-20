line=input("enter the string:")
s= line.split(" ")
l=0
b=""
for i in s:
        if(len(i)>=l):
                l=len(i)
                b=i
print(f"biggest word in line is {b}")
print(f"Lenght of word is {l}")


line=input("enter the string:")
s= line.split(" ")
bword=""
bwordlist=[]
for i in s:
        if(len(i)>len(bword)):
                bword=i
                bwordlist=[bword]
        elif(len(i)==len(bword)):
                bword=i
                bwordlist+=[bword]     
print(f"biggest words in line are {bwordlist}")
print(f"Lenght of word is {len(bword)}")

