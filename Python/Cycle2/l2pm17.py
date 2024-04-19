n=int(input("Enter number of items:  "))
fruits = {}
for i in range(n):
    name = input("Enter name: ")
    number = input("Enter number: ")

    fruits[name] = number

print(fruits)



sorted_dict_keys_asc = dict(sorted(fruits.items()))
print("Ascending order by keys:", sorted_dict_keys_asc)

sorted_dict_keys_desc = dict(sorted(fruits.items(), reverse=True))
print("Descending order by keys:", sorted_dict_keys_desc)

sorted_dict_values_asc = dict(sorted(fruits.items(), key=lambda item: item[1]))
print("Ascending order by values:", sorted_dict_values_asc)

sorted_dict_values_desc = dict(sorted(fruits.items(), key=lambda item: item[1], reverse=True))
print("Descending order by values:", sorted_dict_values_desc)
