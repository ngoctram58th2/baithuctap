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
int ktranhuan(NgayThang ngay)
{
    if((((ngay.year)%100==0) && ( (ngay.year)%400==0) )||(((ngay.year)%100!=0) && ( (ngay.year)%4==0) ))
        return 1;
    else
        return 0;
}
int TimNN(NgayThang n)
{
	int std=0;
	for(int i=0;i<n.mm;i++)
		std += n.dd;
		if(ktranhuan) std+1;
		else std;
}
int main()
{	
	struct NgayThang ngay;
	string s;
	Nhap(s,ngay);
	LayDMY(s,ngay);
	cout<<endl;
	int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	if(ktranhuan(month)) 
		cout << "Nam nhuan";
		
	else
		cout << "Khong nhuan";
}
