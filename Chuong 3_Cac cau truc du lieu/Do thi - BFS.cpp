#include <iostream>
#include <queue> // Su dung hang doi
using namespace std;

#define V 6 // So dinh cua do thi

// Ham BFS
void BFS(int graph[V][V], int start) {
    bool visited[V] = {false}; // Mang danh dau cac dinh da tham
    queue<int> q;              // Hang doi cho BFS

    visited[start] = true; // Danh dau dinh bat dau
    q.push(start);         // Them dinh bat dau vao hang doi

    cout << "Thu tu duyet BFS tu dinh " << start << ": ";
    while (!q.empty()) {
        int u = q.front(); // Lay dinh dau hang doi
        q.pop();
        cout << u << " ";  // In dinh da duyet

        // Duyet tat ca cac dinh ke cua u
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !visited[v]) {
                visited[v] = true;
                q.push(v);
            }
        }
    } cout << endl;
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

    BFS(graph, 0); // Thuc hien BFS tu dinh 0
    return 0;
}

