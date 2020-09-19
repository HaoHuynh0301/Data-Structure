#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
    int Data;
    Node* Next;
};

typedef Node* Set;
typedef Set Position;

void Makenull_Set(Set &S) {
    S=new(Node);
    S->Data=0;
    S->Next=NULL;
}

int Member(int x, Set &S) {
    Position P;
    P=S;
    while(P != NULL) {
        if (P->Data == x) {
            return 1;
        }
        else {
            P=P->Next;
        }
    }
    return 0;
}

void Insert_Set(int x, Position P, Set &S) {
    P=S;
    while(P->Next != NULL) {
        if (P->Next->Data <= x) { P=P->Next;}
        else { P=P->Next; }
    }
    if ( P->Next == NULL || P->Next != NULL && P->Next->Data != x) {
        Position T;
        T=new (Node);
        T->Data=x;
        T->Next=P->Next;
        P->Next=T;
    }
}

void Read_Set(Set &S) {
    Position P=S;
    int size;
    cout<<"\t\t\t\t\tInput the size of Set: "; cin>>size; cout<<endl<<endl;
    for(int i=1;i<=size;i++) {
        int x; cout<<"\t\t\t\t\t  Input the "<<i<<" Element of Set: "; cin>>x; cout<<endl<<endl;
        Insert_Set(x, P, S);
        P=P->Next;
    }
}

void Print_Set(Set &S) {
    cout<<"\t\t\t";
    for(Position P=S->Next;P != NULL;P=P->Next) {
        cout<<"\t"<<P->Data;
    }
    cout<<endl<<endl;
}

void Check_Member_Set(Set &S) {
    int Check;
    cout<<"\t\t\t\tInput the number that you want to check: "; cin>>Check; cout<<endl<<endl;
    if (Member(Check, S) == 1) {
        cout<<"\t\t\t\tThat number exists in the Set !"<<endl<<endl;
    }
    else {
        cout<<"\t\t\t\tThat number dose not exist in the Set !"<<endl<<endl;
    }
}
void Interation_Set(Set &S1, Set &S2, Set &S3) {
    Position P1, P2, P3;
    P1=S1->Next;
    P2=S2->Next;
    P3=S3;
    while (P1 != NULL && P2 != NULL) {
        if (P1->Data == P2->Data) {
            Position T=new (Node);


            // ChÆ°a hiá»ƒu

            P3->Next=new (Node);
            P3=P3->Next;

            //
            P3->Data=P1->Data;
            P1=P1->Next;
            P2=P2->Next;
        }
        else {
            if (P1->Data < P2->Data) {
                P1=P1->Next;
            }
            else {
                P2=P2->Next;
            }
        }
    }
    P3->Next=NULL;
}

void Union_Set(Set &S1, Set &S2, Set &S3) {
    Position P1, P2, P3;
    P1=S1->Next;
    P2=S2->Next;
    P3=S3;
    while (P1 != NULL || P2 != NULL) {
        if (P1->Data != P2->Data) {
          if (P1 == NULL && P2 != NULL) {
            P3->Next=new (Node);
            P3=P3->Next;
            P3->Data=P2->Data;
            P2=P2->Next;
          } 
          else if (P2 == NULL && P1 != NULL) {
            P3->Next=new (Node);
            P3=P3->Next;
            P3->Data=P1->Data;
            P1=P1->Next;          
          }
          else if (P1 != NULL && P2 != NULL) {
            P3->Next=new (Node);
            P3=P3->Next;
            P3->Data=P1->Data;
            P1=P1->Next;

            // chÃ¨n pháº§n tá»­ tá»« S2 vÃ´ S3

            P3->Next=new (Node);
            P3=P3->Next;
            P3->Data=P2->Data;
            P2=P2->Next;
          }
        }
        else {
            P3->Next=new (Node);
            P3=P3->Next;
            P3->Data=P1->Data;
            P1=P1->Next;
            P2=P2->Next;
        }
    }
}
int main()
{
    Set S, S1, S2, S3;
    int selection;
    char choice;
    do {
        cout<<"\t\t\t\t=== Set Excercised Code by Pointer ==="<<endl<<endl;
        cout<<"\t\t\t\t\t=== All Selections ==="<<endl<<endl;
        cout<<"\t\t\t\t   Press 1: Input the new Set and print it"<<endl<<endl;
        cout<<"\t\t\t\t   Press 2: Input the new Set and check the number"<<endl<<endl;
        cout<<"\t\t\t\t   Press 3: Input 2 Sets and make an Interation Set"<<endl<<endl;
        cout<<"\t\t\t\t   Press 4: Input 2 Sets and make an Union Set"<<endl<<endl;
        cout<<"\t\t\t\t   ==>  Input your Selection: "; cin>>selection; cout<<endl<<endl;
        if (selection == 1) {
            Makenull_Set(S);
            Read_Set(S);
            Print_Set(S);
        }
        if (selection == 2) {
            Makenull_Set(S);
            Read_Set(S);
            Check_Member_Set(S);
        }
        if (selection == 3) {
            Makenull_Set(S1);
            Makenull_Set(S2);
            Makenull_Set(S3);
            Read_Set(S1);
            Read_Set(S2);
            Interation_Set(S1, S2, S3);
            Print_Set(S3);

        }
        if (selection == 4) {
            Makenull_Set(S1);
            Makenull_Set(S2);
            Makenull_Set(S3);
            Read_Set(S1);
            Read_Set(S2);
            Union_Set(S1, S2, S3);
            Print_Set(S3);
        }
        cout<<"\t\t\t\t==> Do you want to continue ? ( y/n ): "; cin>>choice; cout<<endl<<endl;
        system("cls");
    } while (choice == 'y');

    return 0;
}
