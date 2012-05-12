tmp = raw_input().split()
n = int(tmp[0])
k = int(tmp[1])
print n, k
paths = []
machines = []
for x in xrange(n-1):
	paths.append(raw_input())
	print paths
for x in range(k):
	machines.append(input())
	print machines
#input done i guess
t = []
matrix = []
for x in xrange(n):
	matrix.append([])
	for y in xrange(n):
		matrix[x].append(-1)

for x in paths:
	y = x.split()
	matrix[int(y[0])][int(y[1])] = int(y[2])
	matrix[int(y[1])][int(y[0])] = int(y[2])

for z in matrix:
	print z
