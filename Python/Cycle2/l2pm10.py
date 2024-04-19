color_list1 = input("Enter colors in color-list1 : ").split(',')
color_list2 = input("Enter colors in color-list2: ").split(',')

color_list1 = [color.strip().lower() for color in color_list1]
color_list2 = [color.strip().lower() for color in color_list2]

diffcolors = [color for color in color_list1 if color not in color_list2]

print("Colors in color-list1 not contained in color-list2:")
for color in diffcolors:
    print(color)
