#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define Dodai 1000001
using namespace std;
typedef char ElementType;
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
void push_stack(stack &s, char x) {
	if (s.top != Dodai) {
		s.top++;
		s.Phantu[s.top]=x;
	}
	else {
		cout<<"Loi danh sach"<<endl;
	}
}
void gettop_stack(stack &s) {
	cout<<s.Phantu[s.top]<<"\t";
}
void delete_stack(stack &s, int &flag) {
	if (s.top!=0) {
		s.top--;
	}
	else {
		flag=0;
	}
}
int main () {
	stack s;
	int flag;
	char r[1000];
	cin.getline(r, 1000);
	cout<<endl;
	makenull_stack(s);
	for ( int i=0;i<strlen(r);i++ ) {
		if ( r[i]=='(' ) {
			push_stack(s, r[i]);
		}
		else {
			if ( r[i]==')' ) {
				delete_stack(s, flag);
			}
		}
	}
	if ( s.top == 0 && flag != 0 ) {
		cout<<"RIGHT";
	}
	else {
		cout<<"WRONG";
	}
return 0;
}
