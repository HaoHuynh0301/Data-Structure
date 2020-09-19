#include <iostream>
#include <stdlib.h>
#define B 10
using namespace std;

typedef int ElementType;
typedef struct Node {
    ElementType Data;
    Node* Next;
};
typedef Node* Position;
typedef Position Dictionary[B];

int h(ElementType x) {
    return x%B;
}

void Makenull_SET(Dictionary &D) {
    for(int i=0;i<B;i++) {
        D[i]=NULL;
    }
}

int Member_SET(ElementType x, Dictionary &D) {
    Position P=D[h(x)];
    while(P != NULL) {
        if(P->Data == x) {
            return 1;
        }
        else {
            P=P->Next;
        }
    }
}

void Insert_SET(ElementType x, Dictionary &D) {
    int Bucket;
    Position P;
    if (!Member_SET(x, D)) {
        Bucket=h(x);
        P=D[Bucket];
        D[Bucket]=new (Node);
        D[Bucket]->Data=x;
        D[Bucket]->Next=P;
    }
}

void Insert_SET2(ElementType x, Dictionary &D) {
	cout<<"\t\t\t\tInput the new number that you want to insert to the Dictionary: "; cin>>x;
    int Bucket;
    Position P;
    if (!Member_SET(x, D)) {
        Bucket=h(x);
        P=D[Bucket];
        D[Bucket]=new (Node);
        D[Bucket]->Data=x;
        D[Bucket]->Next=P;
    }
  cout<<endl;
}


void Delete_SET(ElementType x, Dictionary &D) {
	cout<<"\t\t\t\tInput the number that you want to delete from Dictionary: "; cin>>x; cout<<endl<<endl;
    int Bucket, Done;
    Position P, temp;
    Bucket=h(x);
    if (D[Bucket] != NULL) {
      if(D[Bucket]->Data == x) {
        temp=D[Bucket];
        D[Bucket]=D[Bucket]->Next;
        free(temp);
      }
      else {
        P=D[Bucket];
        while (P->Next != NULL) {
          temp=temp->Next;
          P->Next=temp->Next;
          free(temp);
        }
      }
    }
 
}

void Read_SET(Dictionary &D) {
	int Size; cout<<"\t\t\t\tInput the Size of the Dictionary: "; cin>>Size; cout<<endl<<endl;
	for(int i=1;i<=Size;i++) {
		int x;
		cout<<"\t\t\t\tThe "<<i<<" Element of Dictionary: "; cin>>x; cout<<endl<<endl; Insert_SET(x, D);  
	}
}

void Print_SET(Dictionary &D) { 
  cout<<"\t\t\t\t";
  for(int i=0;i<B;i++) {
    for(Position P=D[i]; P != NULL; P=P->Next) {
      cout<<"\t"<<P->Data;
    }
  }
   cout<<endl<<endl;
}
int main()
{
  Dictionary D;
  char choice;
  int selection, check, x;
  Makenull_SET(D);
  cout<<"\t\t\t\t\t=== DICTIONARY ==="<<endl<<endl;
  cout<<"\t\t\t\tInput your Set: "<<endl<<endl; Read_SET(D);
   do {
        cout<<"\t\t\t\t\t=== SELECTIONS ==="<<endl<<endl;
        cout<<"\t\t\t\t Press 1: Insert new number to Set"<<endl<<endl;
        cout<<"\t\t\t\t Press 2: Delete Member"<<endl<<endl;
        cout<<"\t\t\t\t Press 3: Print the Set"<<endl<<endl;
        cout<<"\t\t\t\t===> Input your selection: "; cin>>selection; cout<<endl;
        if (selection == 1) {
          Insert_SET2(x, D);
        }
        else if (selection == 2) {
          Delete_SET(x, D);
        }
        else if (selection == 3) {
          Print_SET(D);
        }
        cout<<"\t\t\t\tDo you want to continue ? ( y/n )"; cin>>choice; cout<<endl<<endl;
        system("cls");
   } while (choice == 'y');

    return 0;
}
