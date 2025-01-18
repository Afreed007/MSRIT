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

