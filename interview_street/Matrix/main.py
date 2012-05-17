from sets import Set
from graph import graph

tmp = raw_input().split()
n = int(tmp[0])
k = int(tmp[1])
print n, k
paths = []
machines = []
for x in xrange(n-1):
	paths.append(raw_input())
print "Paths:", paths
for x in range(k):
	machines.append(input())
print "Machines:",machines
#input done i guess
gr = graph(n)

for x in paths:
	y = x.split()
	gr.add_edge(int(y[0]),int(y[1]),int(y[2]))
	#print gr.path_exists(int(y[0]),int(y[1]))
gr.pretty_print()
#all edges and nodes in Graph() datatype

def cut_off(G, machines):
	'''
		returns True if no machines are connected
		input: 
			G: Graph of nodes and edges
			machines: iterable list of the machine occupied nodes
	'''
	for x in machines:
		for	y in machines:
			# dont need to check 0,1 and 1,0
			if x <= y:
				pass
			else:
				if( G.path_exists(x,y) ):
					return False
	return True
#end (*)cut_off

if(not cut_off(gr,machines)):
	print "The machines are winning"

cheapest = float('inf')
Q = []
for x in gr.nodes:
	Q.append(x)


'''
#simple tests for testInput
print gr.path_exists(0,1)
print gr.path_exists(0,2)
print gr.path_exists(0,3)
print gr.path_exists(0,4)
print gr.path_exists(1,2)
print gr.path_exists(1,3)
print gr.path_exists(1,4)
print gr.path_exists(2,3)
print gr.path_exists(2,4)
print gr.path_exists(3,4)
'''



"""
for x in xrange(n):
	for y in xrange(n):
		print "x, y: ",x,y
		print path_exists(x,y,n,matrix)
"""

