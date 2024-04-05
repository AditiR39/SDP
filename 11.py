a= [3, 1, 1]
b= [6, 5, 4]
a.sort()
b.sort()
n=len(a)
sum=0
for i in range(n):
    sum += ( a[i] * b[n - i - 1] )
print(sum)