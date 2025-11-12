import sys

def floyd_warshall(cost):
    n = len(cost)
    dist = [row[:] for row in cost]

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if dist[i][k] + dist[k][j] < dist[i][j]:
                    dist[i][j] = dist[i][k] + dist[k][j]
    return dist

if __name__ == "__main__":

    INF = sys.maxsize

    cost = [
        [0, 3, INF, 7],
        [INF, 0, INF, 2],
        [5, INF, 0, INF],
        [INF, INF, 1, 0]
    ]

    result = floyd_warshall(cost)

    print("Shortest distances between every pair of vertices:")
    for i in range(len(result)):
        for j in range(len(result)):
            if result[i][j] == INF:
                print("INF", end="\t")
            else:
                print(result[i][j], end="\t")
        print()