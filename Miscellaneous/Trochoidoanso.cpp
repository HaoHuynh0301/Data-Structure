#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int main () {
	bool tm=false;
	while (tm==false) {
	srand(time(NULL));
	int sm=1+rand()%10;
	int sn, flag=1, i;
	char choice;
		cout<<"CHAO MUNG BAN DEN VOI GAME AN LONE CUNG HAO :)))"<<endl;
		cout<<endl;
		for ( i=1;i<=7;i++) {
			cout<<"  ***  lan chon thu "<<i<<": ";
			cin>>sn;
			cout<<endl;
				if (sn==sm) {
				cout<<"===> Ban da chon dung!"<<endl;
				cout<<endl;
				flag=0;
				break;
			}
			else {
				cout<<"===> Ban chon sai con me no roi"<<endl;
				cout<<endl;
			}
		}
	if (flag==1) {
		cout<<"Game Over"<<endl;
		cout<<endl;
		cout<<"So ma may chon la: "<<sm<<endl;
	}
	else {
		cout<<"  ***  M win cmnr";
	}
	cout<<endl;
	cout<<endl;
	cout<<"  ***  M co muon tiep tuc choi ko ? (c/k) ";
	cin>>choice;
	cout<<endl;
	if (choice!='c') {
		cout<<"Bai Bai thang ngu :)))";
		tm=true;
	}
}
return 0;
}
