line=input("enter the string")
upper=lower=alpha=digit=symbol=space=0
for i in range(0,len(line)):
        if(line[i].isalpha()):
                alpha+=1
                if(line[i].isupper()):
                        upper+=1
                else:
                        lower+=1
        elif(line[i].isdigit()):
                digit+=1
        elif(line[i].isspace()):
                space+=1
        else:
                symbol+=1
print(upper,lower,alpha,digit,symbol,space)
