'''

The prime 41, can be written as the sum of six consecutive primes:
41 = 2 + 3 + 5 + 7 + 11 + 13

This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

'''
def find_key(dic, val):
    """return the key of dictionary dic given the value"""
    return [k for k, v in dic.iteritems() if v == val][0]

primes = []
sums = {}
count = 0
with open("tmp",'r') as f:
	primes = f.read().split()
for x in xrange(len(primes)):
	primes[x] = int(primes[x])

x = 0
while x < 1000000:
	x += primes[count]
	if( x in primes ):
		sums[x]=count
	count+=1

best = 0
terms = 0
for x in xrange(count):
	for y in xrange(count):
		if( y > x ):
			tmp = sum(primes[x:y])
			if( (y-x) > terms and tmp in primes ):
				best = tmp
				terms = y-x

print best
