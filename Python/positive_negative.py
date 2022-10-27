# negative numbers to beginning and positive to end of array.

def move(arr):
  arr.sort()
 
# driver code
arr = [ -1, 2, -3, 4, 5, 6, -7, 8, 9 ]
move(arr)
for e in arr:
    print(e , end = " ")
 
