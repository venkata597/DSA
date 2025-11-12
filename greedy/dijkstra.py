import sys

def dijkstra(cost,src):
    n = len(cost)
    visited = [0]*n
    dist = [sys.maxsize]*n
    dist[0] = 0

    for _ in range(n):
        u = -1
        minimum_dist = sys.maxsize
        for i in range(n):
            if (not visited[i]) and dist[i] < minimum_dist:
                minimum_dist = dist[i]
                u = i
        visited[u] = 1

        for v in range(n):
            if cost[u][v]!=0 and not visited[v]:
                if dist[u] + cost[u][v] < dist[v]:
                    dist[v] = dist[u]+cost[u][v]
    return dist


if __name__ == "__main__":

    cost = [
        [0, 2, 4, 0, 0],
        [2, 0, 1, 7, 0],
        [4, 1, 0, 0, 3],
        [0, 7, 0, 0, 1],
        [0, 0, 3, 1, 0]
    ]

    src = 0
    dist = dijkstra(cost, src)

    print("Shortest distances from vertex ",src,":")
    for i in range(len(dist)):
        print("Vertex ",i,":",dist[i])