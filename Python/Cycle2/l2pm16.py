s = input("Enter integers seperated by space:")
lst=s.split()
for i in range(len(lst)):
	lst[i]=int(lst[i])
positive_numbers = [num for num in lst if num > 0]
print(positive_numbers)
n =int(input("Enter limit:"))
squares = [x**2 for x in range(1, n+1)]
print(squares)
word = input("Enetr a string:")
vowels = [char for char in word if char in 'aeiouAEIOU']
print(vowels)
ordinal_values = [ord(char) for char in word]
print(ordinal_values)
