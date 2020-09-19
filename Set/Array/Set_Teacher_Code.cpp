#include <iostream>
#define maxlenght 100

using namespace std;

typedef struct Set {
    int Size;
    int Element[maxlenght];
};

void Makenull_Set(Set &S) {
    cout<<"\t\t\t\tInput Size of Set: "; cin>>S.Size; cout<<endl<<endl;
    for(int i=1;i<=S.Size;i++) {
        S.Element[i]=0;
    }
}

void Read_Set(Set &S) {
    for(int i=1;i<=S.Size;i++) {
        int x;
        cout<<"\t\t\t\tInput the Element that you want to insert to Set: "; cin>>x; cout<<endl<<endl;
        for(int h=1;h<=S.Size;h++) {
            if (x == h) {
                S.Element[x]=1;
            }
            else { S.Element[x] = 0; }
        }
    }
}

void Print_Set(Set &S) {
    for(int i=1;i<=S.Size;i++) {
        cout<<"The "<<i<<" Element of Set is: "<<S.Element[i]<<endl<<endl;
    }
}

int main()
{
    Set S;
    Makenull_Set(S);
    Read_Set(S);
    Print_Set(S);
    return 0;
}
