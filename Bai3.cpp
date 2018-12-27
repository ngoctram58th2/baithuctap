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
	string DA;
	
}TN;
typedef struct Nguoi
{
	string Ten;
	int Diem;
}Nguoi;

vector<TN> ds;

bool KiemTra (string A,string B){
	if(A.compare(B)==0)//ham so sanh chuoi string
	 return true;
	else
		return false; 
}

void LuuDiem(string ten, int diem)
{	
	fstream f;
	f.open("luudiem.txt", ios::out | ios::app);
	f << ten << "\t" << diem << endl;
	f.close();
}

void Xuat(){
	string s;
		ifstream f2("luudiem.txt");
		// vong lap
		getline(f2, s);// lay ten va diem tu file luudiem
		do{
			cout << s << endl;
			getline(f2, s);
		}while(s.compare("") != 0);// neu dong cuoi cung trong file txt khong co gi het thi ket thuc viet doc
		f2.close();
}

void DocDe()
{
	ifstream f("ch.txt");
	TN T1;
	int SL, diem, xem;
	string s, Ans, ten; //luu bien s kieu string
	getline(f,s); 
	SL=atoi(s.c_str()); //doi tu string sang kieu int
	for(int i=0; i< SL; i++)
	{
		getline(f,s); T1.CauHoi=s;
			cout<<s<<endl;
			getline(f,s);
			T1.A=s;
			cout<<s<<endl;
			getline(f,s);	
			T1.B=s;
			cout<<s<<endl;
			getline(f,s);
			T1.C=s;
			cout<<s<<endl;
			getline(f,s);
			T1.DA=s;
			cout<<"Dap an(Nhap A,B,C):  ";
			getline(cin,Ans);
			if(KiemTra(T1.DA,Ans) == true)
			{
				cout << "Dap an dung."<<endl;
				diem+=2;
				cout<<"-----------------------------------\n";
			}
			else
			{
				cout<<"Dap an sai."<<endl;
				diem+=0;
				cout<<"Dap an dung la: ";
				T1.DA=s;
				cout<<s<<endl;
				cout<<"-----------------------------------\n";
			}

	}
	cout<<"Tong diem la: ";
	cout<<diem;
	cout<<"\nNhap ten: ";
	getline(cin,ten);
	LuuDiem(ten,diem);
	cout<<"Da luu diem\n";
	cout<<"Nhap 1 neu muon xem diem: ";
	cin>> xem;
	if(xem==1)
		Xuat();
}






	
int main()
{
	DocDe();
}