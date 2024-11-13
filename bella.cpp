#include <iostream>
#include <vector>
#include <climits>

using namespace std;

void printAdjacencyMatrix(const vector<vector<int>> &adjMatrix, int V)
{
    cout << "Adjacency Matrix: \n";
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adjMatrix[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void bellmanFord(const vector<vector<int>> &adjMatrix, int V, int E, int source)
{
    vector<int> distance(V, INT_MAX);
    distance[source] = 0;

    for (int i = 1; i <= V - 1; i++)
    {
        for (int u = 0; u < V; u++)
        {
            for (int v = 0; v < V; v++)
            {
                if (adjMatrix[u][v] != INT_MAX && distance[u] != INT_MAX && distance[u] + adjMatrix[u][v] < distance[v])
                {
                    distance[v] = distance[u] + adjMatrix[u][v];
                }
            }
        }
        printAdjacencyMatrix(adjMatrix, V);
    }

    cout << "Shortest distances from source " << source << ": \n";
    for (int i = 0; i < V; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "Vertex " << i << " is unreachable\n";
        else
            cout << "Vertex " << i << " : " << distance[i] << endl;
    }
}

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adjMatrix(V, vector<int>(V, INT_MAX));

    cout << "Enter the edges (u, v, weight) format (0-based indexing):\n";
    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adjMatrix[u][v] = weight;
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    bellmanFord(adjMatrix, V, E, source);

    return 0;
}
