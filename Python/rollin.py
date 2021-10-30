import cmath
x=[1928,1932,1936,1948,1952,1956,1960,1964,1968,1972,1976,1980,1984,1988,1992,1996,2000,2004,2008,2012,2016,]
y=[12.20,11.90,11.15,11.90,11.50,11.50,11.00,11.40,11.00,11.07,11.08,11.06,10.97,10.54,10.82,10.94,11.12,10.93,10.78,10.75,10.71]

Sum1 = 0
for i in range(len(x)):
    Sum1=Sum1+ x[i]
print(Sum1)

Sum2 = 0
for i in range(len(y)):
    Sum2=Sum2+ y[i]
print(Sum2)
meanx = Sum1/len(x)
meany = Sum2/len(y)
print("Mean of x is:",meanx)
print("Mean of y is:",meany)
lst = []
lst2 = []
for i in range(len(x)):
    lst.append((x[i]-meanx)*(y[i]-meany))
    lst2.append((x[i]-meanx)**2)
a = sum(lst)
a=abs(a)
print("The Sum Of (x-meanx)and(y-meany):",a)
b = sum(lst2)
print("The Sum Of (x-meanx)**2:",b)
Beta1 = a/b
Beta1 = abs(Beta1)
print("The Value Of Beta1 is:",Beta1)
Beta0 = abs(meany-Beta1*meanx)
print("The Value Of Beta0 is:",Beta0)
lst3 = []
for I in range(len(y)):
    lst3.append((y[i]-meany)**2)
c=sum(lst3)
print("The Sum Of(y-meany)**2:",c)
sigmax=cmath.sqrt(((b/len(x))))
print("sigmax:",sigmax)
sigmay=cmath.sqrt((c/len(y)))
R = ((sum(lst)/len(x))/(sigmax*sigmay))**2
print("The Coefficient is :",R)

