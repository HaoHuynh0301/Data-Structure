
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#define Dodai 100
#define oo 100000
using namespace std;
typedef int ElementsType;
typedef int position;
typedef struct {
	ElementsType Phantu[100];
	position Last;
}List;
void Makenull(List &L) {
	L.Last=0;
}
void Sapxep(List &L) {
	int i,j,swap;
	for (i=0;i<L.Last;i++) {
		for (j=i+1;j<L.Last;j++) {
			if (L.Phantu[i]>=L.Phantu[j]) {
				swap=L.Phantu[i];
				L.Phantu[i]=L.Phantu[j];
				L.Phantu[j]=swap;
			}
		}
	}
}
void Sapxep2(List &L, int p) {
	int i,j,swap;
	for (i=0;i<=p;i++) {
		for (j=i+1;j<=p;j++) {
			if (L.Phantu[i]>=L.Phantu[j]) {
				swap=L.Phantu[i];
				L.Phantu[i]=L.Phantu[j];
				L.Phantu[j]=swap;
			}
		}
	}
}
void Xuatra(List &L) {
	int i;
	cout<<"  Danh sach in dung xuoi: "<<endl;
	cout<<endl;
	for (i=0;i<L.Last;i++) {
		printf("     ***   Phan tu thu %d: %d\n", i+1, L.Phantu[i] );		
	}	
}
// HAM NHAP VAO //
// ==== //i
void Readlist(List &L) {
	position i;
	printf(" ****   SO PHAN TU CUA DAY: ");
	scanf("%d", &L.Last);
	printf("\n");
	for (i=0;i<L.Last;i++) {
		printf("     ***   Phan tu thu %d: ", i+1 );
		scanf("%d", &L.Phantu[i]);
	}
	printf("\n");
}
void Readlist2(List &L) {
	printf(" ****   SO PHAN TU CUA DAY: ");
	scanf("%d", &L.Last);
	printf("\n");
	printf("     ***   Phan tu thu 1: " );
	scanf("%d", &L.Phantu[0]);
	printf("\n");
	printf("     ===>   DANH SACH LA: ");
	printf("%d", L.Phantu[0]);
	printf("\n");
	printf("\n");
	for (int i=1;i<L.Last;i++) {
		printf("     ***   Phan tu thu %d: ", i+1 );
		scanf("%d", &L.Phantu[i]);
		printf("\n");
		Sapxep2(L, i);
		printf("     ===>   DANH SACH LA: ");
		for (int j=0;j<=i;j++) {
			printf("%d ", L.Phantu[j]);
		}
		printf("\n");
		printf("\n"); 
	}
}
// NHUNG HAM DELETE //
// ==== //
void Loaibo(List &L) {
	int i,j,h;
	for (i=0;i<L.Last-1;i++) {
		for (j=i+1;j<L.Last;j++) {
			if (L.Phantu[i]==L.Phantu[j]) {
				for (h=j+1;h<L.Last;h++) {
					L.Phantu[h-1]=L.Phantu[h];
							i--;
				}
			L.Last--;
		}
	}
	}
}
void Delete(List &L, position d) {
	printf("Nhap vao vi tri can xoa: ");
	scanf("%d", &d);
	d--;
	printf("\n");
	ElementsType i;
	if (d>L.Last-1 || d<0 ) {
		printf("Khong the xoa !\n");
		printf("\n");
		printf("==============\n");
	}
	else {
		for (i=d+1;i<L.Last;i++) {
			L.Phantu[i-1]=L.Phantu[i];
		}
	L.Last--;
	printf("==============\n");
	}	
}
void Delete1(List &L, position d) {
	printf("\n");
	ElementsType i;
	if (d>L.Last-1 || d<0 ) {
		printf("Khong the xoa !\n");
		printf("\n");
		printf("==============\n");
	}
	else {
		for (i=d;i<L.Last;i++) {
			L.Phantu[i-1]=L.Phantu[i];
		}
	L.Last--;
	printf("==============\n");
	}	
}
void Xoaso(List &L, ElementsType &c) {
	int i,j,cout=0;
	printf("Nhap vao so can tim va xoa: ");
	scanf("%d", &c);
	for (j=0;j<L.Last;j++) {
		if (L.Phantu[j]==c) {
			break;
		}
		else {
			cout++;
		}
	}
		if (cout==L.Last) {
		printf("Khong tim thay phan tu can xoa !\n");
	}
	else {
		for (i=j;i<L.Last-1;i++) {
			L.Phantu[i]=L.Phantu[i+1];
		}
	L.Last--;
	printf("\n");
	}	
} 
void Xoaso2(List &L, ElementsType c) {
	int i,j,cout=0;
	for (j=0;j<L.Last;j++) {
		if (L.Phantu[j]==c) {
			break;
		}
		else {
			cout++;
		}
	}
		if (cout==L.Last) {
		printf("Khong tim thay phan tu can xoa !\n");
	}
	else {
		for (i=j;i<L.Last-1;i++) {
			L.Phantu[i]=L.Phantu[i+1];
		}
	L.Last--;
	printf("\n");
	}	
} 
// ==== //
// ==== //
// NHUNG HAM XUAT RA //
// ==== //
void Xuatra2(List &L) {
	position i;
	printf("Danh sach in dung nguoc: \n");
	printf("\n");
	for (i=L.Last-1;i>=0;i--) {
		printf("Phan tu thu %d: %d\n", i+1, L.Phantu[i] );		
	}
}
// ==== //
// NHUNG HAM INSERT //
// ==== //
void Insert(List &L, position p, int x) {
	printf("Nhap vao vi tri va gia tri can chen: ");
	scanf("%d %d", &p, &x);
	printf("\n");
	p--;
	int i;
	if (p>L.Last-1 || p<0) {
		printf("*** Khong the chen ! ***\n");
		printf("\n");
		printf("==============\n");
	}
	else {
		for (i=L.Last-1;i>=p;i--) {
			L.Phantu[i+1]=L.Phantu[i];
		}
	L.Phantu[p]=x;
	L.Last++;		
	}
}
void Inserttructiep(List &L, position p, int x) {
	int i;
		for (i=L.Last;i>=p;i--) {
			L.Phantu[i+1]=L.Phantu[i];
		}
	L.Phantu[p]=x;
	L.Last++;		
}
void Inserttructiep2(List &L, position p, int x) {
	int i;
		for (i=L.Last-1;i>=p;i--) {
			L.Phantu[i+1]=L.Phantu[i];
		}
	L.Phantu[p+1]=x;
	L.Last++;		
}
void Inserttt(List &L, int x) {
	int J=L.Last-1;
	while (J != 0) {
		if ( x >= L.Phantu[J] && J==L.Last-1) {
			Inserttructiep(L, J, x);
			J=0;
		}
		else if ( x >= L.Phantu[J] && J!=L.Last-1 ) {
			Inserttructiep2(L, J, x);
			J=0;
		}
		else {
			J--;
		}
	}
}
void Insert2(List &L, int &x) {
	for (int i=L.Last-1;i>=0;i--) {
		L.Phantu[i+1]=L.Phantu[i];
	}
	L.Phantu[0]=x;
	L.Last++;
}
// ==== //
void List2(List &H) {
	List L;
	printf("Nhap vao so phan tu cua day 2: ");
	scanf("%d", &H.Last);
	for (int i=0;i<H.Last;i++) {
		printf("Phan tu thu %d: ", i+1);
		scanf("%d", &H.Phantu[i]);
	}
	Sapxep(H);
}
void BT10(List &L) {
	for(int i=0;i<L.Last;i++) {
		if ( L.Phantu[i]%2!=0 ) {
			for (int j=i+1;j<L.Last;j++) {
				L.Phantu[j-1]=L.Phantu[j];
			}
			L.Last--;
		}
	}
}
void Tachso(List &h, List &l, List &k) {
	Makenull (l);
	Makenull (k);
	for (int i=0;i<h.Last;i++) {
		if (h.Phantu[i]%2!=0) {
			Insert2(l, h.Phantu[i]);
		}
		else {
			Insert2(k, h.Phantu[i]);
		}
	}
	printf("***  Danh sach so le: ***\n");
	Sapxep(l);
	printf("\n");
	Xuatra(l);
	printf("\n");
	printf("***  Danh sach so chang: ***\n");
	Sapxep(k);
	printf("\n");
	Xuatra(k);
	printf("\n");
}
void BT9(List &L1, List &L2, List &L) {
	for (int i=0;i<L1.Last;i++) {
		Insert2(L, L1.Phantu[L1.Last-1-i]);
	}
	for(int j=0;j<L2.Last;j++) {
		Insert2(L, L2.Phantu[j]);
		Sapxep(L);
	}
}
int main () {
	ElementsType i,n,x,d,c,N,j,h,next,number,number2,number1,flag=1;
	position p;
	char flagg;
	List L,H,K,l,k;
	int zzzz=2;
	while (flag==1) {
	printf("***** DANH SACH NHUNG LENH CAN THUC HIEN: \n");
	printf("\n");
	printf(" **** N1 ( BT 1a & 1b ): In nguoc hoac in xuoi phan tu\n");
	printf(" **** N3 ( BT3 ): Sap xep cac phan tu\n");
	printf(" **** N4 ( BT4 ): Them phan tu\n");
	printf(" **** N4: Xoa phan tu du tren vi tri\n");
	printf(" **** N5 ( BT5 ): Xoa phan tu du tren gia tri cu the\n");
	printf(" **** N6 ( BT6 ): Sap xep cac phan tu\n");
	printf(" **** N7 ( BT7 ): Tim phan tu trung va xoa\n");
	printf(" **** N8 ( BT8 ): Them vao day va sap xep\n");
	printf(" **** N9 ( BT9 ): Nhap them 1 List va tao danh sach lien ket\n");
	printf(" **** N10 ( BT10 ): Xoa cac so le tu danh sach lien ket\n");
	printf(" **** N11 ( BT11 ): Chia thanh 2 danh sach le va chang\n");
	printf("\n");
	printf("====> NHAP VAO LENH BAN CAN: ");
	scanf("%d", &N);
	printf("\n");
	Makenull(H);
	Makenull(K);
	if (N==1) {
		printf("CHON LENH BAN MUON TIEP TUC: \n");
		printf("\n");
		printf(" **** N1: In xuoi\n");
		printf(" **** N2: In nguoc\n");
		printf("\n");
		printf("====> NHAP VAO LENH BAN CAN: ");
		printf("\n");
		scanf("%d", &number);
		if ( number == 1) {
			printf("***** NHAP VAO DANH SACH CUA BAN: \n");
			printf("\n");
			Makenull(L);
			Readlist(L);			
			Xuatra(L);
		}
		else {
			printf("***** NHAP VAO DANH SACH CUA BAN: \n");
			printf("\n");
			Makenull(L);
			Readlist(L);
			Xuatra2(L);
		}
	}	
	else if (N==3) {
		Makenull(L);
		Readlist(L);
		Sapxep(L);
		Xuatra(L);
	}
	else if (N==4) {
		printf("***** NHAP VAO DANH SACH CUA BAN: \n");
		printf("\n");
		Makenull(L);
		Readlist(L);
		cout<<"Nhap vao so can chen: ";
		cin>>zzzz;
		cout<<endl;
		Insert2(L, zzzz);
		Sapxep(L);
		Xuatra(L);
	}
	else if (N==5) {
		Makenull(L);
		Readlist(L);
		Sapxep(L);
		printf("**** DANH SACH SAU KHI SAP XEP: \n");
		printf("\n");
		Xuatra(L);
		printf("\n");
		Xoaso(L, c);
		Xuatra(L);
	}
	else if (N==6) {
		Makenull(L);
		Readlist2(L);
	}
	else if (N==7) {
		Makenull(L);
		Readlist(L);
		Sapxep(L);
		Loaibo(L);
		Xuatra(L);
	}
	else if (N==8) {
		Makenull(L);
		Readlist2(L);
	}
	else if (N==9) {
		Makenull(L);
		Makenull(H);
		Makenull(K);
		Readlist(L);
		Readlist(H);
		BT9(L, H, K);
		Xuatra(K);
	}
	else if (N==10) {
		Makenull(L);
		Readlist(L);
		BT10(L);
		Xuatra(L);
	}
	else {
		Makenull(L);
		Readlist(L);
		Tachso(L, K, H);
	}
	cout<<"Ban co muon lam tiep khong ? ( c/k )";
	cin>>flagg;
	cout<<endl;
	if (flagg!='c') {
		flag=0;
	}
}
return 0;
}