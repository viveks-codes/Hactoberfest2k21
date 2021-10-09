# A python program to print all possible combinations from the three digits.

x = int(input("ENTER THE FIRST NUMBER::>"))
y = int(input("ENTER THE SECOND NUMBER::>"))
z = int(input("ENTER THE THIRD NUMBER::>"))

v = []

v.append(x)
v.append(y)
v.append(z)

for i in range(3):
    for j in range(3):
        for k in range(3):
            if i!=k and k!=j and j!=i:
                print(v[i],v[j],v[k])

