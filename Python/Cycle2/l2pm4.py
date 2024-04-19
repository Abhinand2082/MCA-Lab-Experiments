list=[]
n=int(input("Enter the limit:"))
for i in range(n):
	value=int(input("Enter the value:"))
	if  value>=100:
		list.append("over")
	else:list.append(value)
print("List:",list)
