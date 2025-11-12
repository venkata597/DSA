import sys

def prims(graph,n):
    selected = [False]*n
    no_of_edges = 0
    selected[0] = True
    cost = 0

    print("Edge : Weight")
    
    while no_of_edges < n:
        minimum =sys.maxsize
        x = 0
        y = 0

        for i in range(n):
            if selected[i]:
                for j in range(n):
                    if (not selected[j]) and graph[i][j]:
                        if minimum > graph[i][j]:
                            minimum = graph[i][j]
                            x = i 
                            y = j
        print(x,"-",y," : ",graph[x][y])
        cost += graph[x][y]
        selected[y] = True
        no_of_edges += 1
    
    print("Total minimum cost: ",cost)


if __name__ == "__main__":
    graph = [
        [0, 4, 2, 0],
        [4, 0, 5, 10],
        [2, 5, 0, 3],
        [0, 10, 3, 0]
    ]
    n = len(graph)
    prims(graph, n)
