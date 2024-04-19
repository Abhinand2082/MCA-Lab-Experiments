input_string=input("Enter a line of text:")
words=input_string.split()
c={}
for i in words:
	if i in  c:
		c[i]+=1
	else:
		c[i]=1
print(c)
