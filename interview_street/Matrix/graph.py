from sets import Set
from math import isinf

class graph:
	def __init__(self):
		self.nodes = []
		self.adjacents = []
		#self.pretty_print()

	def __init__(self, size):
		self.nodes = []
		self.adjacents = []
		for x in xrange(size):
			self.add_node(x)
		#self.pretty_print()

	def add_node(self, new_node):
		self.nodes.append(new_node)
		self.adjacents.append([])
		for x in self.adjacents:
			x.append(-1)
		for x in range(len(self.adjacents[0])-1):
			self.adjacents[len(self.adjacents)-1].append(-1)
		#self.pretty_print()

	def add_edge(self, node_a, node_b, edge_weight):
		self.adjacents[node_a][node_b] = edge_weight
		self.adjacents[node_b][node_a] = edge_weight
		#self.pretty_print()

	def path_exists(self, node_a, node_b):
		print "Find if there is a path between:",node_a,"and",node_b
		flag = False
		Q = []
		for x in self.nodes:
			Q.append(x)

		def neighbors(node):
			neighb = []
			for x in Q:
				if( self.adjacents[x][node] != -1 ):
					neighb.append(x)
			#print "neighbors of ",node,"are"
			#print "neighbors", neighb
			return neighb

		def smallest(it):
			#print "smallest of ",it
			current = 0
			while it[current] < 0:
				current += 1
			for x in xrange(len(it)):
				if(it[x] < it[current] and it[x]>=0):
					current = x
			return current

		dist = []
		previous = []
		for x in self.nodes:
			dist.append(float('inf'))
			previous.append(-1)
		dist[node_a] = 0
		while len(Q) > 0:
			#
			tmpD = []
			for x in self.nodes:
				if x in Q:
					tmpD.append(dist[x])
				else:
					tmpD.append(-1)
			#print "tmpD, ",tmpD
			u = smallest(tmpD)
			if(isinf(dist[u])):
				break;
			#print "removing, ",u
			#print Q
			Q.remove(u)
			for v in neighbors(u):
				alt = dist[u] + self.adjacents[u][v]
				if alt < dist[v]:
					dist[v] = alt
					previous[v] = u
		if( not isinf(dist[node_b]) ):
			flag = True

		return flag

	def pretty_print(self):
		print "Nodes: "
		for x in self.nodes:
			print x
		print "Edges: "
		for x in self.adjacents:
			print x
