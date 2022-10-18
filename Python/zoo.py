# the zoo problem
import re

string = input("Enter the string:: ")

if len(string)>20:
    print("The string is greater than 20!")

x = re.findall(r"^zz*o*$",string)

if x:
    print("Yes")
else:
    print("Noo")
