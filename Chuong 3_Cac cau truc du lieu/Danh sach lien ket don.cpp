#include<iostream>
#include <windows.h>

using namespace std;

struct Node{
	short info;
	Node* link;
};

typedef struct Node* node;

node Taonut(short value){
	node tmp = new Node();
	tmp->info = value;
	tmp->link = nullptr;
	return tmp;
}

void Bosung_taivitriM(node &L, node &M, short value){
	node tmp = Taonut(value);
	if(M == nullptr) ; //ds rong
	else if(L == nullptr) L = tmp;
	else if(L == M) {	//pt dau ds
		tmp->link = L;
		L = tmp;
	}
	else {
		node p = L;
		while(p->link != M){
			p = p->link;	//Tim duoc M
		}
		tmp->link = p->link;
		p->link = tmp;
	}
}

void Bosungcuoids(node &L, short value){
	node tmp = Taonut(value);
	if(L == nullptr) L = tmp; //ds rong
	else {
		node p = L;
		while(p->link != nullptr){
			p = p->link;
		}
		p->link = tmp;
	}
}

void Xoanut_taivitriM(node &L, node &M){
	if(L == nullptr || M == nullptr); //ds rong hoac khong tim thay vi tri M
	else if(L == M) {	//pt dau ds	
		L = L->link;
	}
	else {
		node p = L;
		while(p->link != M){	//tim nut nam ngay truoc M
			p = p->link;	
		}
		p->link = M->link;
		delete M;
	}
}

void Xoanut_infoX(node &L, short x){
	if(L == nullptr) ;	//ds rong
	else if(L->info == x){ //pt dau ds	
		L = L->link;
	}
	else {
		node prev = L, current; 
		current = prev->link;
		while(current->info != x && current->link != nullptr){
			prev = prev->link;	
			current = current->link;
		}
		if(current->link != nullptr)  prev->link = current->link;	
		else cout<<"\nKhong co nut nao thoa man"<<endl;
		delete current;
	}
}


void In(node L) {
	cout<<"--------------------------LIST-----------------------------------\n";
	cout<<"Danh sach hien tai: ";
	node p = L;
	while(p != nullptr) {
		cout<<p->info<<"  ";
		p=p->link;
	}
	cout<<"\n-------------------------------------------------------------\n";
}

node Timvitri(node L, int m) {
	int cnt = 0;
	node p = L;
	while(p != nullptr) {
		if(++cnt == m)return p; //phep thu voi phan tu thu m
		p=p->link;
	}
}

int main(){
	node L = nullptr, M = nullptr, VitriM = nullptr;
	int n,n1, lc, m;
	bool ketthuc = 0;
	short value;
	cout<<"---------------------------CREATE---------------------------"<<endl;
	cout<<"Nhap so phan tu = ";cin>>n; n1=n;
	while(n1--){
		cout<<"STT : "<<n-n1;
		cout<<"		value = ";cin>>value;
		Bosungcuoids(L,value);
	}
	system("cls"); In(L);
	cout<<"\n---------------------------MENU---------------------------";
	cout<<"\n|1. Bo sung phan tu moi vao nut duoc tro boi con tro M";
	cout<<"\n|2. Bo sung mot nut moi vao cuoi danh sach";
	cout<<"\n|3. Loai bo phan tu duoc tro boi con tro M";
	cout<<"\n|4. Xoa mot nut co gia tri info = X";
	cout<<"\n---------------------------ORDER---------------------------";
	while(!ketthuc){	
			cout<<"\nLua chon : ";cin>>lc;
			switch(lc) {
				case 1:
					do{
						cout<<"Nhap vi tri M: ";cin>>m;
					}
					while(m<1 || m>n);
					cout<<"Nhap gia tri: ";cin>>value;
					VitriM = Timvitri(L,m);
					Bosung_taivitriM(L,VitriM,value);
					In(L);
					n+=m;
					break;
				case 2:
					cout<<"Nhap so phan tu can bo sung: ";cin>>n1;
					n+=n1;
					while(n1--){
						cout<<"STT : "<<n-n1;
						cout<<"		value = ";cin>>value;
						Bosungcuoids(L,value);
					}
					In(L);
					break;
				case 3:
					do{
						cout<<"Nhap vi tri M: ";cin>>m;
					}
					while(m<1 || m>n);
					VitriM = Timvitri(L,m);
					Xoanut_taivitriM(L,VitriM);
					In(L);
					n--;
					break;
				case 4:
					cout<<"Nhap gia tri X can xoa: ";cin>>value;
					Xoanut_infoX(L,value);
					In(L);
					n--;
					break;
			}
		cout<<"\nBan co muon thoat khong?			0.Khong		1.Co		";cin>>ketthuc;                                                   
	}
}
