#include<iostream>
using namespace std;

struct node{
	int data;
	node* pLeft;
	node* pRight;	
};

typedef struct node* Node;

void ThemNode(Node &a, int value){
	if(a == nullptr){
		Node p = new node();
		p->data = value;
		p->pLeft = nullptr;
		p->pRight = nullptr;
		a = p;
	}
	else{
		if(value < a->data) ThemNode(a->pLeft, value);
		else if(value > a->data) ThemNode(a->pRight, value);
	}
}

void DuyetTruoc(Node &a) {
	if(a == nullptr);
	else {
		cout<<a->data<<"  ";
		DuyetTruoc(a->pLeft);
		DuyetTruoc(a->pRight);
	}
}

void DuyetGiua(Node &a) {
	if(a == nullptr);
	else {
		DuyetGiua(a->pLeft);
		cout<<a->data<<"  ";
		DuyetGiua(a->pRight);
	}
}

void DuyetSau(Node &a) {
	if(a == nullptr);
	else {
		DuyetSau(a->pLeft);
		DuyetSau(a->pRight);
		cout<<a->data<<"  ";
	}
}

int main() {
	Node a = nullptr;
	int value, n, n1;
	
	cout<<"n = "; cin>>n; n1 = n;
	while(n1--){
		cout<<"STT "<<n-n1<<"	value = "; cin>>value;
		ThemNode(a, value);
	}
	cout<<"\nduyet truoc: ";
	DuyetTruoc(a);
	cout<<"\nduyet giua: ";
	DuyetGiua(a);
	cout<<"\nduyet sau: ";
	DuyetSau(a);
}
