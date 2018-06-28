#Script generating a file with sorted int between mini & maxi
from random import randint

size = 1000
maxi = 10000
mini = 1
tab = []
f = open('sorted_int.txt', 'w')
for i in range(0, size):
	tab.append(randint(mini, maxi))
tab.sort()
for a in tab:
	f.write(str(a) + "\n")
f.close()