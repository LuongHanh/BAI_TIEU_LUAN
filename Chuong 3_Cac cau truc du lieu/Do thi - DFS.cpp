#include <iostream>
using namespace std;
#define V 6 // So dinh cua do thi
// Ham DFS de quy
void DFSUtil(int graph[V][V], int u, bool visited[]) {
    visited[u] = true; // Danh dau dinh da tham
    cout << u << " ";  // In dinh da duyet

    // Duyet tat ca cac dinh ke cua u
    for (int v = 0; v < V; v++) {
        if (graph[u][v] && !visited[v]) {
            DFSUtil(graph, v, visited); // Goi de quy
        }
    }
}
// Ham DFS
void DFS(int graph[V][V], int start) {
    bool visited[V] = {false}; // Mang danh dau cac dinh da tham

    cout << "Thu tu duyet DFS tu dinh " << start << ": ";
    DFSUtil(graph, start, visited); // Goi ham de quy
    cout << endl;
}
int main() {
    // Ma tran ke bieu dien do thi
    int graph[V][V] = {
        {0, 1, 1, 0, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {1, 1, 0, 0, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 0, 1, 1, 0, 1},
        {0, 0, 0, 1, 1, 0}
    };

    DFS(graph, 0); // Thuc hien DFS tu dinh 0
    return 0;
}

