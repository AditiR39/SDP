list1 = ['a1', 'a2', 'a3', 'a4', 'a5']
list2 = ['b1', 'b2', 'b3']
r = []

for str1, str2 in zip(list1, list2):
    z = str1 + str2
    r.append(z)

if len(list1) > len(list2):
    r.extend(str1+ '' for str1 in list1[len(list2):])

elif len(list2) > len(list1):
    r.extend([str2 + '' for str2 in list2[len(list1):]])

print(r)
