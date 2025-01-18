str=input("enter the string:")
char=input("Enter the string:")
count=0
for i in range(0,len(str)):
        if(str[i]==char):
                count+=1
                print("occured at index", i)
print("count=",count)
