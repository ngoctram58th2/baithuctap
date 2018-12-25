#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct NgayThang
{
	int dd,mm,year;
}NgayThang;
void Nhap(string &st, NgayThang &Nt)
{
	cout <<"Nhap ngay thang nam:";
	getline(cin,st);
	cout<<st;
}
void LayDMY(string &s, NgayThang &ngay)
{
	ngay.dd= atoi((s.substr(0,2)).c_str());
	cout<<ngay.dd<<endl;
	ngay.mm = atoi((s.substr(3,2)).c_str());
	cout<<ngay.mm<<endl;
	ngay.year = atoi((s.substr(6,4)).c_str());
	cout<<ngay.year<<endl;
}
int main()
{	
	struct NgayThang ngay;
	string s;
	Nhap(s,ngay);

	LayDMY(s,ngay);
	cout<<endl;
}
