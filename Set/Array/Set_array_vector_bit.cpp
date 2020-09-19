#include <iostream>
#define maxlength 10

using namespace std;

typedef struct Set {
    int Element[10];
};

void makenull_set(Set &s) {
    for(int i=0;i<maxlength;i++) {
        s.Element[i]=0;
    }
}

void read_set(Set &s, int &n) {
    cout<<"\t\t\t\t====> Input the size of Data: ";
    cin>>n; cout<<endl;
    for(int i=0;i<n;++i) {
        int x, count=0;;
        if (i==0) {
            cout<<"\t\t\t\t===> Input 1st element of Set: "; cin>>x; cout<<endl;
        }
        else if (i==1) {
            cout<<"\t\t\t\t===> Input 2nd element of Set: "; cin>>x; cout<<endl;
        }
        else if (i==2) {
            cout<<"\t\t\t\t===> Input 3rd element of Set: "; cin>>x; cout<<endl;
        }
        else {
            cout<<"\t\t\t\t===> Input "<<i+1<<"th element of Set: "; cin>>x; cout<<endl;
        }
        for (int j=0;j<maxlength;++j) {
                if(x==j && count-x==0) {
                    s.Element[x-1]=1;
                }
                count++;
            }
    }
    cout<<endl;
}

void print_Set(Set &s) {

    cout<<"\t\t";

    for(int i=1;i<=10;i++) {
        cout<<i<<"\t";
    }
    cout<<endl<<endl;
    cout<<"\t\t";

    for(int i=0;i<maxlength;i++) {
        cout<<s.Element[i]<<"\t";
    }
    cout<<endl<<endl;
}

void Intersection_Set(Set &s1, Set &s2, Set &s3) {
    for(int i=0;i<maxlength;i++) {
        if (s1.Element[i] == s2.Element[i]) {
            s3.Element[i]=s1.Element[i];
        }
    }
}

void Mix_Set(Set &s1, Set &s2, Set &s3) {
    for(int i=0;i<maxlength;i++) {
        s3.Element[i]=s1.Element[i];
    }
    for(int i=0;i<maxlength;i++) {
        if(s2.Element[i] != s3.Element[i]) {
            s3.Element[i]=1;
        }
    }
}

void Insert_Set(Set &s, int &x) {
    cout<<"\t\t\tInput the element that you wanna insert to this Set: "; cin>>x; cout<<endl<<endl;
    for(int i=0;i<maxlength;i++) {
       if(i == x-1) {
            s.Element[i]=1;
       }
    }
}

void Delete_Set(Set &s, int &x) {
    cout<<"\t\tInput the element that you wanna delete from this Set: "; cin>>x; cout<<endl<<endl;
    for(int i=0;i<maxlength;i++) {
        if(i == x-1) {
            s.Element[i]=0;
        }
    }
}
int main()
{
    Set s1,s2,s3;
    int n, m, x, choice;
    char flag='Y';
    makenull_set(s1); makenull_set(s2); makenull_set(s3);
    do {
        cout<<"\t\t\t\t==== SET ECERSISE ===="<<endl<<endl;
        cout<<"\t\t\t\t=== All selections ==="<<endl<<endl;
        cout<<"\t\t\t\tN1: Read and print a Set"<<endl<<endl;
        cout<<"\t\t\t\tN2: Make a Intersection from 2 Sets"<<endl<<endl;
        cout<<"\t\t\t\tN3: Make a Mix Set from 2 Sets"<<endl<<endl;
        cout<<"\t\t\t\tN4: Insert an new element to Set"<<endl<<endl;
        cout<<"\t\t\t\tN5: Delete an element from Set"<<endl<<endl;
        cout<<"\t\t\t\t===> Input your choice: "; cin>>choice; cout<<endl<<endl;
        if (choice == 1) {
            read_set(s1, m);
            print_Set(s1);
            read_set(s2, n);
            print_Set(s2);
        }
        else if(choice == 2) {
            read_set(s1, m);
            read_set(s2, n);
            Intersection_Set(s1, s2, s3);
            print_Set(s3);
        }
        else if(choice == 3) {
            read_set(s1, m);
            read_set(s2, n);
            Mix_Set(s1, s2 , s3);
            print_Set(s3);
        }
        else if(choice == 4) {
            read_set(s1, m);
            print_Set(s1);
            Insert_Set(s1, x);
            print_Set(s1);

        }
        else if(choice == 5) {
            read_set(s1, m);
            print_Set(s1);
            Delete_Set(s1, x);
            print_Set(s1);

        }
    cout<<"\t\t\t\tDo you wanna continue (Y/N) ?"; cout<<endl<<endl<<"\t\t\t\t==> Input your choice: "; cin>>flag; cout<<endl<<endl;
    } while (flag=='Y');

    return 0;
}
