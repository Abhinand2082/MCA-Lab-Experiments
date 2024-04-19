"""
str1=input("Enter first string");
str2=input("Enter Second string");
if len(str1) <2 or len(str2)<2:
	print("Both string should have atleast 2 Character")
else:
	str3=str1[0]+str2[0]+ " "+str2[0]+str[0]
print("Resulting string is :",str3)
"""


str1=input("Enter first string");
str2=input("Enter Second string");
x=str1[0:1]+str2[1:2]+str1[2:]
y=str2[0:1]+str1[1:2]+str2[2:]
str3=x+" "+y
print (str3)

