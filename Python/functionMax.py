def max(a,b,c):
    if(a>b and a>c):
        print("A is Maximum")
    elif(b>a and b>c):
        print("B Is Maximum")
    elif(c>a and c>b):
        print("C Is Maximum")
    elif(a==b and b==c and c==a):
        print("All are Equal")


a=eval(input("Enter the value of a: "))
b=eval(input("Enter the value of b: "))
c=eval(input("Enter the value of c: "))
max(a,b,c)
