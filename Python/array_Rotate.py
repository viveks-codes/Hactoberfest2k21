a = []
b = int(input("enter the size of array::")) 
num = int(input("num to rotate:;"))
for i in range(b):
	c = int(input("enter the element::"))
	a.append(c)
print(a)

def rightRotate(array, num):
    output_list = []

    for item in range(len(a) - num, len(a)):
        output_list.append(a[item])

    for item in range(0, len(a) - num):
        output_list.append(a[item])
 
    return output_list

print(rightRotate(a,num))
