#include <iostream>
#define Maxleght 100
using namespace std;
typedef struct List {
    int Element[100];
    int Last;
};

void Makenull_List(List &L) {
    L.Last=0;
}

void Read_List(List &L) {
    cout<<"\t\t\t\tInput Size of List: "; cin>>L.Last; cout<<endl<<endl;
    for(int i=0;i<L.Last;i++) {
        cout<<"\t\t\t\tInput the "<<i+1<<" member of Array: "; cin>>L.Element[i]; cout<<endl<<endl;
    }

}

void Print_List(List &L) {
    cout<<"\t\t\t\t\t  LIST"<<endl<<endl;
    for(int i=0;i<L.Last;i++)  {
        cout<<"\t\t\t\tthe "<<i+1<<" member of Array: "<<L.Element[i]<<endl<<endl;
    }
}

void Inser_List(List &L, int x, int Positon) {
    int Flag=0;
    cout<<"\t\t\tInput the number that you want to insert to the List: "; cin>>x; cout<<endl<<endl;
    for(int i=0;i<L.Last;i++) {
        if (L.Element[i] == x) {
            cout<<"\t\t\t\tThis number already existed before !"<<endl<<endl;
            Flag=1;
        }
    }
        if (Flag == 0) {
            cout<<"\t\t\tInput the position that you wan to put the number to the List: "; cin>>Positon; cout<<endl<<endl;
            for (int y=L.Last-1;y>=Positon-1;y--) {
                L.Element[y+1]=L.Element[y];
            }
            L.Element[Positon-1]=x;
            ++L.Last;
        }
}

void Delete_Value_List(List &L, int Value) {
    cout<<"\t\t\tInput the number that you want to delete from the List: "; cin>>Value; cout<<endl<<endl;
    for(int i=0;i<L.Last;i++) {
        if (L.Element[i] == Value) {
            for(int y=Value;y<L.Last;y++) {
                L.Element[y-1]=L.Element[y];
            }
        }
    }
    --L.Last;
}

void Delete_Position_List(List &L, int Position) {
    cout<<"\t\t\tInput the position that you want to delete from the List: "; cin>>Position; cout<<endl<<endl;
    for(int i=Position;i<L.Last;i++) {
        L.Element[i-1]=L.Element[i];
    }
    --L.Last;
}

void Arrange_List(List &L) {
    for(int i=0;i<L.Last;i++) {
        for(int y=i+1;y<L.Last;y++) {
            if (L.Element[i]>L.Element[y]) {
                int Replace;
                Replace=L.Element[i];
                L.Element[i]=L.Element[y];
                L.Element[y]=Replace;
            }
        }
    }
}
int main()
{
    List L;

    int x, PositionI, PositionII, Value;

    Makenull_List(L);

    Read_List(L);

    Print_List(L);

    Arrange_List(L);

    Print_List(L);

    return 0;
}
