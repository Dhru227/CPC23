#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge {
    int src, dest, weight;
};

class Graph {
    int V;
    vector<Edge> edges;

public:
    Graph(int v) : V(v) {}

    void addEdge(int src, int dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    int findParent(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return findParent(parent, parent[i]);
    }

    void unionSets(vector<int>& parent, int x, int y) {
        int xset = findParent(parent, x);
        int yset = findParent(parent, y);
        parent[xset] = yset;
    }

    int kruskalMST() {
        vector<int> parent(V, -1);
        sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
            return a.weight < b.weight;
        });

        int cost = 0;
        int edgeCount = 0;

        for (auto& edge : edges) {
            int x = findParent(parent, edge.src);
            int y = findParent(parent, edge.dest);

            if (x != y) {
                unionSets(parent, x, y);
                cost += edge.weight;
                edgeCount++;
            }
        }

        return (edgeCount == V - 1) ? cost : -1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int K;
        cin >> K;

        for (int t = 0; t < K; t++) {
            int N, M;
            cin >> N >> M;

            Graph graph(N);

            for (int i = 0; i < M; i++) {
                int U, V, W;
                cin >> U >> V >> W;
                graph.addEdge(U, V, W);
            }

            int minCost = graph.kruskalMST();
            cout << minCost << endl;
        }
    }

    return 0;
}
