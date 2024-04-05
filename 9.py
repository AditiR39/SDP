r=int(input("enter r"))
unit=int(input("enter unit"))
n=int(input("enter n"))
arr=[]
i=[]
print("enter array")
for i in range(0,n):
    ele=int(input())
    arr.append(ele)
z=r*unit
for x in arr:
    r=r+arr
    if(r<z):
        x=x+1
    else:
        i.append(r)
print(i)