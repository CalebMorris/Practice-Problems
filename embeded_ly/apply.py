import math, urllib2
def one(n=8001):
	r = 0
	i = 10
	while r != n:
		i+=1
		s = 0
		x = math.factorial(i)
		while x > 0:
			s += x%10
			x/=10
		r = s
	return i
def two (url = "http://apply.embed.ly/static/data/2.html"):
	source = urllib2.urlopen(url).read()
	a=[]
	depth = 0
	for x in "".join(source.split('\n')).split('<')[7:-2]:
		if x[0] == 'p':
			a.append(depth)
			depth+=1
		elif x[0] == '/':
			depth-=1
		else:
			depth+=1
	avg = sum(a)/1./len(a)
	var = 0
	for x in a:
		var += (x-avg)**2
	return "%.1f" % (var/len(a))**.5

def three (n = 900):
	s = 0
	for x in range(n):
		s+=1./(x+1)
	k = 0
	i = 0
	while k < s/2.:
		i += 1
		k += 1./i
	return i

print one()
print two()
print three()
