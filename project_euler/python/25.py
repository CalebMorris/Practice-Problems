'''
The Fibonacci sequence is defined by the recurrence relation:

    Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.

Hence the first 12 terms will be:

    F1 = 1
    F2 = 1
    F3 = 2
    F4 = 3
    F5 = 5
    F6 = 8
    F7 = 13
    F8 = 21
    F9 = 34
    F10 = 55
    F11 = 89
    F12 = 144

The 12th term, F12, is the first term to contain three digits.

What is the first term in the Fibonacci sequence to contain 1000 digits?
'''
def add_long( n, m ):
	'''
	len(m) >= len(n) ALWAYS
	'''
	ret = []
	len_diff = len(m)-len(n)
	#print "len_diff",len_diff
	for x in range(len(n)):
		ret.insert(0,n[len(n)-1-x]+m[len(m)-1-x])
	if( len_diff > 0 ):
		for x in range(1,len_diff+1):
			ret.insert(0,m[len_diff-x])
	for x in range(len(ret)-1):
		if( ret[len(ret)-1-x] > 9 ):
			ret[len(ret)-2-x] += ret[len(ret)-1-x]/10
			ret[len(ret)-1-x] = ret[len(ret)-1-x]%10
	while( ret[0] > 9 ):
		ret.insert(0,ret[0]/10)
		ret[1] = ret[1]%10
	#print ret
	return ret

t1 = [1]
t2 = [1]
tmp = []
count = 0

while( len(t2) < 1000 and t2[0]<150 ):
	tmp = add_long(t1,t2)
	t1 = t2
	t2 = tmp
	count += 1

print "The final number is ",count+2
