"""
The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 11 + 22 + 33 + ... + 10001000.
"""
sum = 0
base = 10**10
for x in range(1000):
	sum = (sum+(x+1)**(x+1))%base
print sum
