#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

void bfs(int graph[5][5], int start, string loc[5])
{
    int visited[5] = {0};
    queue<int> q;
    q.push(start);
    int n = sizeof(graph[0]) / sizeof(graph[0][0]);
    cout<<"BFS of graph is: ";
    while (!q.empty())
    {
        int current = q.front();
        q.pop();

        if (visited[current] == 0)
        {
            cout << loc[current] << " ";
            visited[current] = 1;

            for (int i = 0; i < n; i++)
            {
                if (graph[current][i] == 1 && visited[i] == 0)
                {
                    q.push(i);
                }
            }
        }
    }
}

void dfs(int graph[5][5], int start, string loc[5])
{
    int visited[5] = {0};
    stack<int> s;
    s.push(start);
    int n = sizeof(graph[0]) / sizeof(graph[0][0]);
    cout << "\nDFS of graph is: ";
    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (visited[current] == 0)
        {
            cout << loc[current] << " ";
            visited[current] = 1;

            for (int i = 0; i < n; i++)
            {
                if (graph[current][i] == 1 && visited[i] == 0 )
                {
                    s.push(i);
                }
            }
        }
    }
}

int main()
{

    int graph[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 1, 1, 0},
        {1, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {0, 0, 0, 1, 0},
    };
    string lm[5] = {"frontgate", "class", "canteen", "mba", "backgate"};
    bfs(graph, 1, lm);
    dfs(graph, 1, lm);

    return 0;
}