#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NgayThang
{
	int dd;
	int mm;
	int year;
}NgayThang;
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
void Nhap(string &stt, NgayThang &date)
{
	cout << "nhap du lieu: (phan biet boi dau /)"; 
	getline(cin, stt);
	cout << "ngay thang vua nhap: " << stt;
}

void chuoi(string &st, NgayThang &date)
{
	date.dd = atoi((st.substr(0,2)).c_str());
	cout << "\nngay: " << date.dd<<endl;
	date.mm = atoi((st.substr(3,2)).c_str());
	cout << "thang: " << date.mm<<endl;
	date.year = atoi((st.substr(6,4)).c_str());
	cout << "nam: " << date.year <<endl;
}

int ktnhuan (int year)
{
	 if(((year)%100 == 0) && ((year)%400 == 0) || (((year)%100 != 0) && ((year)%4 == 0)))
        return 1;
    else
        return 0;
}


int STT(NgayThang date)
{
	int STT=0;
	for(int i =0; i< date.mm; i++)
	STT += month[i];
	STT += date.dd;
	if(ktnhuan==0 && date.mm > 2) STT +=1;
	return STT;

}

NgayThang NgayTuSTT(int n,int year)
{
	int i=0;
	int ngay= n;
	int kt = ktnhuan(ngay);
	while(n >0)
		{
			if((kt==1) && (i==2))
				n = n -29;
			else
				n = n - month[i];
			if(n>0)
				{
					ngay = n;
					i++;
				}
		}
	NgayThang nt;
	nt.dd = ngay;
	nt.mm = i;
	nt.year = year;
	return nt;
}
NgayThang TongNgayThang(NgayThang n,int x) //x,a
{
	
	int kq= x + STT(n);
	int year=n.year;
	if(x <= 365)
	if(kq <= 365)
		return NgayTuSTT(kq,year);
	else
		if(ktnhuan(year)==1)
			if(kq == 366)
				return NgayTuSTT(kq,year);
			else
				return NgayTuSTT(kq-366,year+1);
		else
			return 	NgayTuSTT(kq-365,year+1);

	else
		if(ktnhuan(year)==1)
			return NgayTuSTT(kq+366,year+1);
		else
			return NgayTuSTT(kq+365,year+1); 
}
int main()
{
	struct NgayThang ngay;
	string st;
	int x;
	Nhap(st, ngay);
	chuoi(st, ngay);
	cout << "\nSTT ngay trong nam la: " << STT(ngay);
	cout<<"\nNhap vao so nguyen can tinh: ";
	cin>> x;
	TongNgayThang(ngay,x);
}
