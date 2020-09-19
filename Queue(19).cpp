#include <stdio.h> 

#include <stdlib.h> 

#include <iostream> 

#define Dodai 5 

using namespace std; 

typedef int ElementType; 

typedef struct { 

ElementType Data[Dodai]; 

int front; 

int rear; 

} Queue; 

void makenull_Queue(Queue &q) { 

q.front=0; 

q.rear=0; 

} 

void read_Queue(Queue &q) { 

cout<<endl; 

for (int i=0;i<Dodai;i++) { 

int x; 

cout<<"Nhap vao x: "; 

cin>>x; 

cout<<endl; 

q.Data[i]=x; 

q.rear++; 

} 

cout<<"Hang day! Ngung nhap cau ui :v"<<endl; 

} 

void delete_Queue(Queue &q) { 

if (q.rear == 0) { 

cout<<"Loi! Ngan xep rong"<<endl; 

} 

else { 

for (int i=1;i<q.rear;i++) { 

q.Data[i-1]=q.Data[i]; 

} 

} 

q.rear=q.rear-1; 

} 

void print_Queue(Queue &q) { 

while (q.rear != 0) { 

cout<<q.Data[q.front]<<endl; 

delete_Queue(q); 

} 

} 

void insert_Queue(Queue &q,ElementType x) { 

if (q.rear == Dodai-1) { 

cout<<"Loi! Ngan xep day"<<endl; 

} 

else { 

q.Data[q.rear+1]=x; 

} 

q.rear=q.rear+1; 

} 

int main () { 

Queue q; 

int n,k; 

char flag; 

do { 

cout<<"N1 (19a)"<<endl; 

cout<<"N2 (19b)"<<endl; 

cout<<"====> "; 

cin>>k; 

cout<<endl; 

if (k == 1) { 

makenull_Queue(q); 

read_Queue(q); 

cout<<endl<<"Het cau a ui ^^"<<endl<<endl; 

} 

else { 

makenull_Queue(q); 

read_Queue(q); 

print_Queue(q); 

cout<<"Het bai b ui ^^"<<endl; 

} 

cout<<"Lam tiep ko ? ( c/k )"<<endl; 

cout<<"====> "; 

cin>>flag; 

} while (flag == 'c'); 

return 0; 

} 
