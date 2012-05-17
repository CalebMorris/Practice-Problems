from sets import Set
from graph import graph

tmp = raw_input().split()
n = int(tmp[0])
k = int(tmp[1])
#print n, k
paths = []
machines = []
for x in xrange(n-1):
	t = raw_input()
	p_tmp = t.split()
	paths.append((int(p_tmp[0]),int(p_tmp[1]),int(p_tmp[2])))
#print "Paths:", paths
for x in range(k):
	machines.append(input())
#print "Machines:",machines
#input done i guess
gr = graph(n)

for x in paths:
	#print x
	gr.add_edge(x)
	#print gr.path_exists(x[0],x[1])
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

def search( G, paths = None, machines = None, alt = 0, cheap = float('inf') ):
	'''
	Search Algorithm notes
	Start at the highest possible value for the cheapest destruction cost
		* Change this to heuristic later
	For each edge (keeping a running sum of the time for edge destruction)
		remove the edge from the adjacency matrix and run the state-check
	If either the sum is too big or there are no more edges, return <<something>>
	'''
	#print "paths",paths
	#print "alt",alt
	#print "cheap",cheap
	for x in paths:
		#(node_a,node_b,weight)
		if (alt+x[2]) >= cheap:
			pass
		else:
			#only going through first edges, fix this
			G.remove_edge(x[0],x[1])
			if cut_off(G, machines):
				#print "cut off with final edge",x
				#print "with remaining paths",paths
				if(alt+x[2]<cheap):
					cheap = alt+x[2]
			elif not paths:
				#print "no more paths, move on."
				return float('inf')
			else:
				#print "down the rabbit whole on edge",x
				tmp = search(
						G,
						paths[:paths.index(x)]+paths[paths.index(x)+1:],
						machines, 
						alt+x[2],cheap
						)
				if(tmp < cheap):
					cheap = tmp
				#print "tmp search return",tmp
			G.add_edge(x)
	return cheap

#end (*)search
				
	
if(not cut_off(gr,machines)):
	#simple check if I need to even do anything
	#print "The machines are winning"
	print search(gr, paths, machines)
else:
	print "Shortest cut-off is 0"

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
