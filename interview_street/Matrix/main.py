tmp = raw_input().split()
n = int(tmp[0])
k = int(tmp[1])
print n, k
paths = []
machines = []
for x in range(n-1):
	paths.append(raw_input())
	print paths
for x in range(k):
	machines.append(input())
	print machines
#input done i guess
