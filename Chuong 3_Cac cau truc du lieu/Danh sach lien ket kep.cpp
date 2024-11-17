#include<iostream>
#include <windows.h>

using namespace std;

struct Node {
    short info;
    Node* next;
    Node* prev;
};

typedef Node* node;

node Taonut(short value) {
    node tmp = new Node();
    tmp->info = value;
    tmp->next = nullptr;
    tmp->prev = nullptr;
    return tmp;
}

void Bosung_taivitriM(node &L, node &M, short value) {
    node tmp = Taonut(value);
    if (M == nullptr) ; //khong tim thay vi tri M
    else if (L == nullptr) L = tmp; // danh sach rong
    else if (L == M) { // phan tu dau danh sach
        tmp->next = L;
        L->prev = tmp;
        L = tmp;
    }
    else {
        tmp->next = M;
        tmp->prev = M->prev;
        if (M->prev) M->prev->next = tmp;
        M->prev = tmp;
    }
}

void Bosungcuoids(node &L, short value) {
    node tmp = Taonut(value);
    if (L == nullptr) L = tmp; // danh sach rong
    else {
        node p = L;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = tmp;
        tmp->prev = p;
    }
}

void Xoanut_taivitriM(node &L, node &M) {
    if (L == nullptr || M == nullptr); // danh sach rong hoac khong tim thay vi tri M
    else if (L == M) { // phan tu dau danh sach
        L = L->next;
        if (L) L->prev = nullptr;
        delete M;
    }
    else {
        if (M->prev) M->prev->next = M->next;
        if (M->next) M->next->prev = M->prev;
        delete M;
    }
}

void Xoanut_infoX(node &L, short x) {
    if (L == nullptr); // danh sach rong
    else if (L->info == x) { // phan tu dau danh sach
        node tmp = L;
        L = L->next;
        if (L) L->prev = nullptr;
        delete tmp;
    }
    else {
        node p = L;
        while (p != nullptr && p->info != x) {
            p = p->next;
        }
        if (p == nullptr) {
            cout << "\nKhong co nut nao thoa man" << endl;
            return;
        }
        if (p->prev) p->prev->next = p->next;
        if (p->next) p->next->prev = p->prev;
        delete p;
    }
}

void In(node L) {
    cout << "--------------------------LIST-----------------------------------\n";
    cout << "Danh sach hien tai: ";
    node p = L;
    while (p != nullptr) {
        cout << p->info << "  ";
        p = p->next;
    }
    cout << "\n-------------------------------------------------------------\n";
}

node Timvitri(node L, int m) {
    int cnt = 0;
    node p = L;
    while (p != nullptr) {
        if (++cnt == m) return p; // phep thu voi phan tu thu m
        p = p->next;
    }
    return nullptr;
}

int main() {
    node L = nullptr, M = nullptr, VitriM = nullptr;
    int n, n1, lc, m;
    bool ketthuc = 0;
    short value;
    cout << "---------------------------CREATE---------------------------" << endl;
    cout << "Nhap so phan tu = "; cin >> n; n1 = n;
    while (n1--) {
        cout << "STT : " << n - n1;
        cout << "        value = "; cin >> value;
        Bosungcuoids(L, value);
    }
    system("cls"); In(L);
    cout << "\n---------------------------MENU---------------------------";
    cout << "\n|1. Bo sung phan tu moi vao nut duoc tro boi con tro M";
    cout << "\n|2. Bo sung mot nut moi vao cuoi danh sach";
    cout << "\n|3. Loai bo phan tu duoc tro boi con tro M";
    cout << "\n|4. Xoa mot nut co gia tri info = X";
    cout << "\n---------------------------ORDER---------------------------";
    while (!ketthuc) {
        cout << "\nLua chon : "; cin >> lc;
        switch (lc) {
            case 1:
                do {
                    cout << "Nhap vi tri M: "; cin >> m;
                } while (m < 1 || m > n);
                cout << "Nhap gia tri: "; cin >> value;
                VitriM = Timvitri(L, m);
                Bosung_taivitriM(L, VitriM, value);
                In(L);
                n++;
                break;
            case 2:
                cout << "Nhap so phan tu can bo sung: "; cin >> n1;
                n += n1;
                while (n1--) {
                    cout << "STT : " << n - n1;
                    cout << "        value = "; cin >> value;
                    Bosungcuoids(L, value);
                }
                In(L);
                break;
            case 3:
                do {
                    cout << "Nhap vi tri M: "; cin >> m;
                } while (m < 1 || m > n);
                VitriM = Timvitri(L, m);
                Xoanut_taivitriM(L, VitriM);
                In(L);
                n--;
                break;
            case 4:
                cout << "Nhap gia tri X can xoa: "; cin >> value;
                Xoanut_infoX(L, value);
                In(L);
                n--;
                break;
        }
        cout << "\nBan co muon thoat khong?            0.Khong        1.Co        "; cin >> ketthuc;
    }
}

