#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Dodai 1000001
using namespace std;
typedef int ElementType;
typedef struct {
	ElementType Phantu[10000];
	int top;
}stack;
void makenull_stack(stack &s) {
	s.top=0;
}
int empty_stack(stack &s) {
	return s.top==0;
}
int full_stack(stack &s) {
	return s.top==Dodai;
}
void push_stack(stack &s, int x) {
	if (s.top != Dodai) {
		s.top++;
		s.Phantu[s.top]=x;
	}
	else {
		cout<<"Loi danh sach"<<endl;
	}
}
void get_stack(stack &s) {
	cout<<s.Phantu[s.top]<<"\t";
}
void delete_stack(stack &s) {
	if (s.top!=0) {
		s.top--;
	}
	else {
		cout<<"Loi ngan xep"<<endl;
	}
}
int main () {
	stack s;
	int x,c;
	char flag;
	do	{
		cout<<"Nhap vao so can doi co so ( BT18a ): ";
		cin>>x;
		cout<<endl;
		makenull_stack(s);
		while (x != 0) {
			push_stack(s, x%2);
			x /= 2;
		}
		while (s.top != 0) {
			get_stack(s);
			delete_stack(s);
		}			
		cout<<endl<<endl;
		cout<<"Tiep tuc hay khong ? ( c/k )"<<endl<<endl;
		cout<<"======> ";
		cin>>flag;
		cout<<endl;
	} while (flag == 'c');
return 0;
}
