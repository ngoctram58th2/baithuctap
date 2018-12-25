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
NgayTuSTT(int stt, int year)
{
int kq= a + sttNgayTrongNam(x);
	int year=x.year;
	if(kq <= 365)
		return NgayTuSTT(kq,year);
		else
			if(NamNhuan(year)==1)
				if(kq == 366)
					return NgayTuSTT(kq,year);
				else
					return NgayTuSTT(kq-366,year+1);
			else
				return 	NgayTuSTT(kq-365,year+1);	
}

int main()
{	
	struct NgayThang ngay;
	string s;
	
	Nhap(s,ngay);
	LayDMY(s,ngay);
	cout<<endl;
	if(ktranhuan(ngay)) 
		cout << "Nam nhuan";
	else
		cout << "Khong nhuan";
}
