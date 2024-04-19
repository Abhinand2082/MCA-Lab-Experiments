file = open("File1.txt","r")
file2 = open("File2.txt","w+")
line = file.readlines()
print(line)
for i in range(len(line)):
        if(i%2!=0):
                file2.write(line[i])
line = file.readlines()
print(line)            
file.close()
file2.close()
