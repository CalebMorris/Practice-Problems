import random

n = random.randint(2,50)
k = random.randint(2,n)

print n,k

for x in xrange(n-1):
	a = random.randint(0,n-1)
	b = -1
	while b < 0 or a == b:
		b = random.randint(0,n-1)
	weight = random.randint(1,1000)
	print a,b,weight

machines = []
while len(machines) < k:
	tmp = random.randint(0,n)
	if (tmp not in machines):
		machines.append(tmp)

for x in machines:
	print x
