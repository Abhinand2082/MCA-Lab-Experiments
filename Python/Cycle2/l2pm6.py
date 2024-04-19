list1=input("Enter the 1st list:")
list2=input("Enter the 2nd list:")


if len(list1)==len(list2):
	print("Both list have same length")
else:
	print("list differ in length")
Sum1=sum(list1)
Sum2=sum(list2)
if  Sum1==Sum2:
	print("Both list have same sum")
flag =0
for i in list1:
	for j in list2:
		if i==j:
			print("Common element:",j)
			flag=1
if flag==0:
	print("No common element found")
