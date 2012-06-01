'''
A permutation is an ordered arrangement of objects. 
For example, 3124 is one possible permutation of the digits 1, 2, 3 and 4. 
If all of the permutations are listed numerically or alphabetically, 
we call it lexicographic order. 
The lexicographic permutations of 0, 1 and 2 are:

012   021   102   120   201   210

What is the millionth lexicographic permutation 
of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?

'''
'''
notes
there will be len(elements)! permutations
will probably do a recursive call :/
'''
import collections
def flatten(l):
	for el in l:
		if isinstance(el, collections.Iterable) and not isinstance(el, basestring):
			for sub in flatten(el):
				yield sub
		else:
			yield el

def perm(it):
	#print "Entering with",it
	ret = []
	ret_val = []
	if( len(it) <= 1 ):
		#print "Exiting with",it
		return it
	for x in range(len(it)):
		t = [it[x]] + it[:x] + it [x+1:]
		#print "t",t
		for x in perm(t[1:]):
			ret.append([t[0]]+[x])
	for x in ret:
		tmp = flatten(x)
		z = []
		for y in tmp:
			z.append(y)
		ret_val.append(z)
	#print "Exiting with", ret_val
	return ret_val

[0,1,2]
#print perm([0])
#print perm([0,1])
#print perm([0,1,2])
#print perm([0,1,2,3])

print perm([0,1,2,3,4,5,6,7,8,9])[999999]
