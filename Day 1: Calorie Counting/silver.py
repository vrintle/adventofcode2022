a = []
sum = 0
while True:
	try:
		s = input()
	except:
		break
	if len(s) == 0:
		a.append(sum)
		sum = 0
	else:
		sum = sum + int(s)
a.append(sum)
a.sort()
# print(a)
print(a[-1])
