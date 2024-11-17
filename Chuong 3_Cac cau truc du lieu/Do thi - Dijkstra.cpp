#include <iostream>
using namespace std;

#define V 6        // So luong dinh trong do thi
const int INF = 100000; // Gia tri dai dien cho vo cuc (gia tri lon)

int minDistance(int dist[], bool visited[]) {
    int min = INF, minIndex;

    for (int v = 0; v < V; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void printSolution(int dist[]) {
    cout << "Dinh \t Khoang cach tu nguon" << endl;
    for (int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];     // Mang luu khoang cach ngan nhat tu src den moi dinh
    bool visited[V]; // Mang danh dau dinh da duoc xu ly

    // Khoi tao tat ca khoang cach la vo cuc va chua dinh nao duoc tham
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = false;
    }

    // Khoang cach tu nguon den chinh no la 0
    dist[src] = 0;

    // Tim duong di ngan nhat cho tat ca cac dinh
    for (int count = 0; count < V - 1; count++) {
        // Chon dinh chua xu ly co khoang cach nho nhat
        int u = minDistance(dist, visited);
        visited[u] = true;

        // Cap nhat khoang cach cho cac dinh ke
        for (int v = 0; v < V; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // In ket qua
    printSolution(dist);
}

int main() {
    // Ma tran ke bieu dien do thi
    int graph[V][V] = {
        {0, 7, 9, 0, 0, 14},
        {7, 0, 10, 15, 0, 0},
        {9, 10, 0, 11, 0, 2},
        {0, 15, 11, 0, 6, 0},
        {0, 0, 0, 6, 0, 9},
        {14, 0, 2, 0, 9, 0}
    };

    int src = 0; // Dinh nguon
    cout << "Khoang cach ngan nhat tu dinh " << src << " den cac dinh khac:" << endl;
    dijkstra(graph, src);

    return 0;
}

