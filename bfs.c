#include <stdio.h>

int queue[20], front = -1, rear = -1;
int visited[20];
int adj[20][20];
int n;

void enqueue(int v)
{
    if (rear == 19)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

int dequeue()
{
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

void bfs(int start)
{
    int i, v;
    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (adj[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()   // 👈 THIS MUST EXIST
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
        visited[i] = 0;
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}