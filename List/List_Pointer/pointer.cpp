#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#define Dodai 100

using namespace std;

typedef int ElementType;

typedef struct Node {
	
	ElementType Data;
	
	Node* next;
	
};

typedef Node* position;
typedef position List;

void makenull_List(List &L) {
	L=new (Node);
	L->next=NULL;
}

void insert_Node(ElementType x, position P, List &L) {
	position T=new (Node);
	T->Data=x;
	T->next=P->next;
	P->next=T;
}

void delete_Node(position P, List &L) {
	position T;
	P=T->next;
	T->next=P->next;
}

void read_Node(List &L) {
	position P=L;
	int n;
	cout<<"Nhap vao so phan tu cua danh sach: ";
	cin>>n;
	cout<<endl;
	for (int i=0;i<n;i++) {
		int x;
		cout<<"Nhap vao phan tu: ";
		cin>>x;
		cout<<endl;
		insert_Node(x, P, L);
		P=P->next;
	}
}
void print_Node(List &L) {
	for (position P=L->next;P!=NULL;P=P->next) {
		cout<<P->Data<<endl;
	}
}
int main () {
	List L;
	position P;
	int n;
	makenull_List(L);
	read_Node(L);
	print_Node(L);
return 0;
}
