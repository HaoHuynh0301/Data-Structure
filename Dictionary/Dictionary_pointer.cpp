#include <iostream>

#include <stdlib.h>

#define maxlength 10

#define B 5

using namespace std;

typedef struct Node {

    int Data;

    Node* Next;

};

typedef Node* Dictionary[B];

int h(int x) {

    return x%B;

}

void makenull_ditionary(Dictionary &d) {

    for(int i=0;i<maxlength;i++) {

        d[i]=NULL;

    }

}

int Member(int X, Dictionary D) {

    Node* P;

    int Found=0;

    P=D[h(X)];

    while((P!=NULL) && (!Found))

    if (P->Data==X) { Found=1; }

    else  { P=P->Next; }

    return Found;

}

void Insert_Dictionary(int x, Dictionary D) {

    int Bucket;

    Node* P;

    if (!Member(x, D)) {

        Bucket=h(x);

        P=D[Bucket];

        D[Bucket]=(Node*)malloc(sizeof(Node));

        D[Bucket]->Data=x;

        D[Bucket]->Next=P;

    }

}



int main() {

    Dictionary D;

    int x;

    do {

        cout<<"\t\t\t\t==== DICTIONARY ECERSISE ===="<<endl<<endl;

        cout<<"\t\t\t\t    === All selections ==="<<endl<<endl;

        cout<<"Input x: "; cin>>x; cout<<endl<<endl;

    } while ( x != 0);

    return 0;
}
