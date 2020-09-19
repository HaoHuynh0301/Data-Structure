#include <iostream>

#include <string.h>

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

        int x; cout<<"=====> Nhap vao x: "; cin>>x; cout<<endl;

        insert_tree(t, x);

}

void print_treeNLR(Node* &t) {

    if (t != NULL) {

        cout<<t->Data<<"    ";

        print_treeNLR(t->left);

        print_treeNLR(t->right);

    }

}

void print_treeLNR(Node* &t) {
	
	if (t != NULL) {
		
		print_treeLNR(t->left);
		
		cout<<t->Data<<"	";
		
		print_treeNLR(t->right);
		
	}
	
}

void print_treeLRN(Node* &t) {
	
	if (t != NULL) {
		
		cout<<t->Data<<"	";
		
		print_treeLRN(t->right);
		
		print_treeLRN(t->left);
		
	}
	
}

bool Kiemtrasonguyento(int x) {

    int c=1;

    if ( x <= 1 ) {

        return false;

    }

    else if (x == 2) {

        return true;

    }

    else {

        for (int i=2;i<=x;i++) {

            if (x%2 == 0) {

                c++;

            }
        }
    }

    if ( c == 1) {

       return true;
    }

    else {

        return false;

    }

}

void Kiemtrasonguyento_tree(Node* &t,int &dem) {

    if (t != NULL) {

        if (Kiemtrasonguyento(t->Data) == true) {

            dem++;

        }

        Kiemtrasonguyento_tree(t->left, dem);

        Kiemtrasonguyento_tree(t->right, dem);

    }

}

void findingnumber_tree(Node* &t, int x) {

    if (t == NULL) {

        cout<<"===== Loi cay rong ! ====="<<endl<<endl;

    }

    else {

        if (t->Data > x) {

            findingnumber_tree(t->right, x);

        }

        else if (t->Data < x) {

            findingnumber_tree(t->left, x);

        }

        else {

        cout<<"===== Co phan tu "<<x<<" trong cay ! ====="<<endl;

        }

    }

}

int DemsoNode_tree (Node* &t) {

	if ( t == NULL) {

		return 0;

		}

	else {

        return 1 + DemsoNode_tree(t->left)+DemsoNode_tree(t->right);

	}
}

void DemsoNodela_tree(Node* &t,int &c) {

    if (t != NULL) {

        if (t->left == NULL && t->right == NULL) {

            ++c;

        }

        DemsoNodela_tree(t->left, c);

        DemsoNodela_tree(t->right, c);

    }

}

void TimNodemax_tree(Node* &t, int &max) {
    if (t != NULL) {

        if (t->Data > max) {

            max = t->Data;

        }

        TimNodemax_tree(t->left, max);

        TimNodemax_tree(t->right, max);

    }

}

void TimNodemin_tree(Node* &t, int &min) {

    if (t != NULL) {

        if (t->Data < min) {

            min = t->Data;

        }

        TimNodemin_tree(t->left, min);

        TimNodemin_tree(t->right, min);

    }

}

void XoaNode_tree(Node* &t, int &det) {

    if (t != NULL) {

        if (det > t->Data) {

            XoaNode_tree(t->left, det);

        }

        else if (det < t->Data) {

            XoaNode_tree(t->right, det);

        }

        else { //Luc nay t->Data = det

            Node* x=t;

            if (t->left == NULL) {

                t=t->right;

            }

            else if (t->right == NULL) {

                t=t->left;

            }

             delete x;

        }

    }

}
int main() {

    int dem=0, choice, x, c=0, cc=0, max = INT_MIN, min = INT_MAX, ins, det;

    char flag, choice2;

    Node* t;

    do {

        cout<<"===== Nhap vao lua chon: ====="<<endl<<endl;

        cout<<"====> N1: Nhap de them phan tu vao cay va duyet cach tien tu "<<endl<<endl;

        cout<<"====> N2: Dem so cac so nguyen to cua cay "<<endl<<endl;

        cout<<"====> N3: Tim phan tu co trong cay "<<endl<<endl;

        cout<<"====> N4: Dem so Node cua cay "<<endl<<endl;

        cout<<"====> N5: Dem so Node la cua cay "<<endl<<endl;

        cout<<"====> N6: Tim Node có gia tri lon nhat "<<endl<<endl;

        cout<<"====> N7: Tim Node có gia tri nho nhat "<<endl<<endl;

        cout<<"====> N8: Chen 1 Node vao cay "<<endl<<endl;

        cout<<"====> N9: Xoa mot Node cua cay "<<endl<<endl;
        
        cout<<"====> N10: Duyet ra kieu LNR "<<endl<<endl;
        
        cout<<"====> N11: Duyet cay kieu LRN "<<endl<<endl;

        cout<<"====> Nhap vao lua chon: "; cin>>choice; cout<<endl;

        if (choice == 1) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            cout<<"Duyet cay theo kieu NRL: "<<endl<<endl;

            print_treeNLR(t);

            cout<<endl<<endl;

        }

        else if (choice == 2) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            Kiemtrasonguyento_tree(t, dem);

            cout<<"===== So cac so nguyen to cua cay la: "<<dem<<" ====="<<endl<<endl;

        }

        else if (choice == 3) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            findingnumber_tree(t, 2);

        }

        else if (choice == 4) {

        	makenull_tree(t);

        	cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

        	do {

        		Read_tree(t);

        		cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

			} while (flag == 'c');

			cout<<DemsoNode_tree(t)<<endl;

		}

		else if (choice == 5) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

           DemsoNodela_tree(t, cc);

           cout<<"So nut la cua cay la: "<<cc<<endl<<endl;

		}

		else if (choice == 6) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            TimNodemax_tree(t, max);

            cout<<"So Node lon nhat la: "<<max<<endl<<endl;

		}

		else if (choice == 7) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            TimNodemin_tree(t, min);

            cout<<"So Node nho nhat la: "<<min<<endl<<endl;

		}

		else if (choice == 8) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            print_treeNLR(t);

            cout<<"Nhap vao Node can chen: "; cin>>ins; cout<<endl<<endl;

            insert_tree(t, ins);

            cout<<"Cay sau khi chen: "<<endl;

            print_treeNLR(t);

		}

		else if (choice == 9) {

            makenull_tree(t);

            cout<<"==== NHAP VAO CAY NHI PHAN ====="<<endl<<endl;

            do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');

            cout<<"Cay nhi phan truoc khi xoa Node: "<<endl; print_treeNLR(t);

            cout<<"Nhap vao gia tri Node can xoa: "; cin>>det; cout<<endl;

            XoaNode_tree(t, det); print_treeNLR(t);

		}
		
		else if (choice == 10) {
			
			makenull_tree(t);
			
			do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');
            
            cout<<"Duyet cay nhi phan theo kieu LNR: "<<endl<<endl; print_treeLNR(t); cout<<endl<<endl;
            
        }	
        
        else if (choice == 11) {
        	
        	makenull_tree(t);
        	
        	do {

                Read_tree(t);

                cout<<"Tiep tuc nhap hay ko ? ( c/k ) "; cin>>flag; cout<<endl;

            } while (flag == 'c');
            
            cout<<"Duyet cay nhi phan theo kieu LRN :"<<endl<<endl; print_treeLRN(t); cout<<endl<<endl;
            
       }
        			

    cout<<"Ban muon tiep tuc hay khong ? ( c/k )"; cin>>choice2; cout<<endl<<endl;

    } while (choice2 == 'c');

    return 0;

}


