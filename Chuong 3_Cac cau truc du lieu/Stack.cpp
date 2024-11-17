#include <iostream>
using namespace std;

struct Stack {
    int top;
    int *nodes;
};

Stack* init() {
    Stack *stack = new Stack;
    stack->top = -1;
    stack->nodes = new int[100]; 
    return stack;
}

bool isEmpty(Stack *stack) {
    if (stack->top == -1) return true; 
    else return false;
}

void push(Stack *stack, int node) { 
    stack->top++;
    stack->nodes[stack->top] = node;
}

int pop(Stack *stack) { 
    if(isEmpty(stack)) return false;
    int result = stack->nodes[stack->top];
    stack->top--;
    return result;
}

// Ham size: tra ve so luong phan tu trong stack
int size(Stack *stack) {
    return stack->top + 1; // Vi top la chi so cua phan tu cuoi cung, cong them 1 de tinh so luong phan tu
}

int main() {
    int dec, index = 0, Bin[8] = {-1,-1,-1,-1,-1,-1,-1,-1};
    Stack *stack = init();
    cout << "-----------STACK------------" << endl;
    do {
        cout << "Nhap so decimal: ";
        cin >> dec;
    } while (dec <= 0);

    while (dec > 0) {
        Bin[index++] = dec % 2;
        dec /= 2;
    }

    for (int i = index; i < 8; i++) Bin[i] = 0;
    for (int i = 0; i < 8; i++) if (Bin[i] != -1) push(stack, Bin[i]);

    cout << "Binary: ";
    while (stack->top > -1) {
        cout << pop(stack); 
    }

    // In kich thuoc cua stack
    cout << "\nSize of stack: " << size(stack) << endl;

    return 0;
}

