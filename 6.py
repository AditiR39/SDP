list1 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
k = 3

for i in range(0, len(list1), k):
    list1[i:i+k] = reversed(list1[i:i+k])

print(list1)