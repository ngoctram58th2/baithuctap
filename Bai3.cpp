//Chon de lam
//doc de(doc tu file text)
//doc dong 1
//vong lap for
//Nhap cau tra loi theo quy dinh
//Kiem tra dap an(string a,string b)
//tao struct luu diem

#include<iostream>
#include <stdlib.h>
#include<fstream>
#include<vector>
#include<string>
using namespace std;

typedef struct TN 
{
	string CauHoi;
	string A,B,C;
	char DA;
}TN;
typedef struct Nguoi
{
	string Ten;
	int Diem;
}Nguoi;
vector<TN> ds;
void DocDe()
{
	ifstream f("ch.txt");
	int SL;
	string s; //luu bien s kieu string
	getline(f,s); 
	SL=atoi(s.c_str()); //doi tu string sang kieu int
	for(int i=0; i< SL; i++)
	{
		getline(f,s);
	    ds[i].CauHoi;
		cout<<s<<endl;
		getline(f,s); 
		ds[i].A;
		cout<<s<<endl;
		getline(f,s); 
		ds[i].B;
		cout<<s<<endl;
		getline(f,s); 
		ds[i].C;
		cout<<s<<endl;
		getline(f,s); 
		ds[i].DA;
		cout<<s<<endl;
	}
}

int main()
{
	DocDe();
}
