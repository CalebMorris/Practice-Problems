'''
Let d(n) be defined as the sum of proper divisors of n 
	(numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a != b, then a and b are an amicable pair 
	and each of a and b are called amicable numbers.
For example, the proper divisors of 220 are 
	1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
	The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
Evaluate the sum of all the amicable numbers under 10000.
'''
def amicable(n):
	divs = [1]
	for x in range(2,n):
		if n%x == 0:
			divs.append(x)
	m = sum(divs)
	if m != n:
		divm = [1]
		for x in range(2,m):
			if m%x == 0:
				divm.append(x)
		if sum(divm) == n:
			return n
		else:
			return 0
	else:
		return 0

if __name__=="__main__":
	s = 0
	for x in range(1, 10000):
		s += amicable(x)
	print s
