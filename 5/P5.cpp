#include <iostream>
#include <vector>

using namespace std;

struct adjacent_vertex {
    int vertex;
    int weight;
};

int main() {
    const int INF = 2147483647;
    int n;
    cin >> n;
    vector<vector<adjacent_vertex>> adjacency_list;
    for (int i = 0; i < n; i++) {
        int mi;
        cin >> mi;
        vector<adjacent_vertex> adjacent_vertices;
        adjacency_list.push_back(adjacent_vertices);
        for (int j = 0; j < mi; j++) {
            adjacent_vertex adj;
            cin >> adj.vertex >> adj.weight;
            adj.vertex--;
            adjacency_list[i].push_back(adj);
        }
    }
    int s, t;
    cin >> s >> t;
    s--;
    t--;

    vector<int> d(n, INF);
    d[s] = 0;
    vector<bool> u(n, false);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++) {
            if (!u[j] && (v == -1 || d[j] < d[v])) {
                v = j;
            }
        }
        if (d[v] == INF) {
            break;
        }
        u[v] = true;
        for (int j = 0; j < adjacency_list[v].size(); j++) {
            int vertex = adjacency_list[v][j].vertex;
            int weight = adjacency_list[v][j].weight;
            if (d[v] + weight < d[vertex]) {
                d[vertex] = d[v] + weight;
                p[vertex] = v;
            }
        }
    }
    vector<int> path;
    for (int v = t; v != s; v = p[v]) {
        path.push_back(v);
    }
    path.push_back(s);
    if (d[t] == INF) {
        cout << -1;
    }
    else {
        cout << d[t] << endl;
        cout << path.size() - 1 << endl;
        for (int i = path.size() - 1; i >= 0; i--) {
            cout << path[i] + 1 << " ";
        }
    }
    return 0;
}


