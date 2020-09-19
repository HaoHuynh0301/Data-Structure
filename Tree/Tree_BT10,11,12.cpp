#include <iostream>

using namespace std;

typedef struct Node {

    int Data;

    Node* right;

    Node* left;

};

void makenull_tree(Node* &t) {

    t=NULL;

}

void insert_tree(Node* &t, int x) {

    if (t == NULL) {

        Node* p;

        p=new Node;

        p->Data=x;

        p->left=NULL;

        p->right=NULL;

        t=p;

    }

    else {

        if (t->Data > x) {

            insert_tree(t->right, x);

        }

        else if (t->Data < x) {

            insert_tree(t->left, x);

        }

    }

}

void Read_tree(Node* &t) {

        int x; cout<<"Nhap vao x: "; cin>>x; cout<<endl;

        insert_tree(t, x);

}

void print_treeNLR(Node* &t) {

    if (t != NULL) {

        cout<<t->Data<<"\t"<<endl<<endl;

        print_treeNLR(t->left);

        print_treeNLR(t->right);

    }

}

int main()
{

    int dem=0, choice, x, c=0;

    char flag, choice2;

    Node* t;

    do {

        cout<<"==== Bai tap 10 ===="<<endl<<endl;

        makenull_tree(t);

        cout<<"Nhap vao cay nhi phan"<<endl<<endl;

        do {

            Read_tree(t);

            cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

        } while (flag == 'c');

        cout<<"Duyet cay theo kieu NRL: "<<endl<<endl;

        print_treeNLR(t);

        cout<<"Ban muon tiep tuc hay khong ? ( c/k )"; cin>>choice2; cout<<endl;

    } while (choice2 == 'c');

    return 0;
}
