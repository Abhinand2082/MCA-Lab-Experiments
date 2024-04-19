input_str = input("Enter a string: ")

if len(input_str) < 2:
    print("String is too short")
else:
    first_char = input_str[0]
    modified_str = first_char + ''.join('$' if char == first_char else char for char in input_str[1:])
    print("Modified string:", modified_str)
