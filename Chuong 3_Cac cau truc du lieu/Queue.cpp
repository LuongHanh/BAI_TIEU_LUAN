#include <iostream>
#include <cmath>
using namespace std;

struct Queue {
    int front, rear;
    int *nodes;
};

// Khoi tao hang doi
Queue* init() {
    Queue* queue = new Queue;
    queue->front = -1;
    queue->rear = -1;
    queue->nodes = new int[250];
    return queue;
}

// Kiem tra neu hang doi day
bool isFull(Queue* queue) {
    if (queue->rear == 249) return true;
    return false;
}

// Kiem tra neu hang doi rong
bool isEmpty(Queue* queue) {
    if (queue->front == -1 || queue->front > queue->rear) return true;
    return false;
}

// Them phan tu vao hang doi
void Enqueue(Queue* queue, int node) {
    if (isFull(queue)) return;
    if (queue->front == -1)
        queue->front = 0;
    queue->nodes[++queue->rear] = node;
}

// Lay phan tu khoi hang doi
int Dequeue(Queue* queue) {
    if (isEmpty(queue)) return -1;
    int result = queue->nodes[queue->front++];
    if (queue->front > queue->rear) {
        queue->front = -1;
        queue->rear = -1;
    }
    return result;
}

// Ham tra ve so luong phan tu trong hang doi
int size(Queue* queue) {
    if (isEmpty(queue)) return 0;
    return queue->rear - queue->front + 1;
}

int main() {
    int dec, index = 0, Bin[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    Queue *queue = init();
    cout << "-----------QUEUE------------" << endl;
    
    do {
        cout << "Nhap so decimal: ";
        cin >> dec;
    } while (dec <= 0);

    // Chuyen so thap phan thanh nhi phan
    while (dec > 0) {
        Bin[index++] = dec % 2;
        dec /= 2;
    }

    // Dien so 0 vao mang neu chua du 8 phan tu
    for (int i = index; i < pow(2, 3); i++) Bin[i] = 0;

    // Them cac phan tu vao hang doi
    for (int i = 7; i >= 0; i--) if (Bin[i] != -1) Enqueue(queue, Bin[i]);

    cout << "Binary: ";
    // In ra cac phan tu trong hang doi
    while (!isEmpty(queue)) {
        cout << Dequeue(queue);
    }

    // In kich thuoc cua hang doi
    cout << "\nSize of queue: " << size(queue) << endl;

    return 0;
}

