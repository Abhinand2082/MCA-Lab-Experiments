n=int(input("Enter number of items:  "))
fruits = {}
for i in range(n):
    name = input("Enter name: ")
    number = input("Enter number: ")
    fruits[name] = number
m=int(input("Enter number of items:  "))
vegetables = {}
for i in range(m):
    name = input("Enter name: ")
    number = input("Enter number: ")
    vegetables[name] = number
print("Dictionaries before merging:")
print(fruits)
print(vegetables)

fruits.update(vegetables)
print("Merged dictionary:",fruits )
