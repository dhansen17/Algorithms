import Queue

num_nodes = int(raw_input())

again = True

ans = []
while again:
	edges = []
	num_edges = int(raw_input())

	for i in range(num_edges):
		edges.append(raw_input())

	for e in edges:
		temp = e.split(" ")
		temp = (int(temp[0]), int(temp[1]))

	graph = []
	for i in range(num_nodes):
		graph.append([])

	for e in edges:
		temp = e.split(" ")
		temp = (int(temp[0]), int(temp[1]))
		graph[temp[0]].append(temp[1])
		graph[temp[1]].append(temp[0])

	colors = {}

	que = Queue.Queue()
	que.put(0)
	colors[0] = 0
	a = ""
	while not que.empty():
		current = que.get()
		
		for neighbor in graph[current]:
			try:
				t = colors[neighbor]
				if t == colors[current]:
					a = "NOT BICOLORABLE"
			except:
				colors[neighbor] = (colors[current] + 1) % 2
				que.put(neighbor)
	if a == "":
		a = "BICOLORABLE"
	ans.append(a)


	num_nodes = int(raw_input())
	if num_nodes == 0:
		again = False


for a in ans:
	print a
