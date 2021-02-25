import os
import matplotlib.pyplot as plt
list_1= open("context.txt","r")
f=list_1.read()
def freq(file):
    list_1= open(file,"r")
    f=list_1.read()
    s=f.split("\n")
    l=[]
    for i in f.lower().split():
        i=i.strip(",")
        i=i.strip(".")
        i=i.strip("(")
        i=i.strip(")")
        i=i.strip(":")
        i=i.strip('\"')
        i=i.strip(";")
        l.append(i)
    f1={}
    for i in l:
        if i not in f1:
            f1[i]=0
        f1[i]+=1

    for i in f1:
        print(i,"===>",f1[i])
    return "--->"
s_w=["i","me","myself","me","our","ours","ourselves","you","you're","you've","you'll","you'd","your","yours","yourself","yourselves","above","below","to","from","up","in","may","as","his"]
s1=""
for i in f.split():
    if not i in s_w:
        s1=s1+i+" "
list_2=open("context2.txt","w+")
list_2.write(s1)
list_2.close()
print("frequency of words before:")
freq("sport.txt")
print("*************************************************************************************")
print("frequency of words after:")
freq("sport2.txt")
x=["file1","file2"]
y=[os.path.getsize("sport.txt"),os.path.getsize("sport2.txt")]
plt.plot(x,y)
plt.show()
