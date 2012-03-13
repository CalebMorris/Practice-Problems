'''
A palindromic number reads the same both ways. 
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 x 99.
Find the largest palindrome made from the product of two 3-digit numbers.
'''

def pal(n):
	while len(n) > 1:
		if n[0] != n[-1]:
			return False
		n = n[1:-1]
	return True

largest = 0
for x in range(100,999):
	for y in range(100,999):
		tmp = x*y
		if (pal(str(tmp))) and tmp > largest:
			largest = tmp
print largest 
