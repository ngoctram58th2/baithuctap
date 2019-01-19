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
	cout << "Nhap ngay thang nam: (phan biet boi dau /, ngay thang 2 chu so): "; 
	getline(cin, stt);
	cout << "ngay thang vua nhap: " << stt;
}

int ktnhuan (int year)
{
	 if(((year)%100 == 0) && ((year)%400 == 0) || (((year)%100 != 0) && ((year)%4 == 0)))
        return 1;
    else
        return 0;
}

void chuoi(string &st, NgayThang &date)
{
	date.dd = atoi((st.substr(0,2)).c_str());//cat chuoi lay ra 2 ky tu
	cout << "\nngay: " << date.dd<<endl;
	date.mm = atoi((st.substr(3,2)).c_str());//cat chuoi lay ra 2 ky tu tiep theo tu ky tu thu 3
	cout << "thang: " << date.mm<<endl;
	date.year = atoi((st.substr(6,4)).c_str());//cat chuoi lay ra 4 ky tu tiep theo tu ky tu thu 6
	cout << "nam: " << date.year <<endl;
	if(ktnhuan(date.year))
		cout<<"La nam nhuan";
	else
		cout<<"Khong phai nam nhuan";
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

NgayThang TongNgayThang(NgayThang n,int x)
{
	
	int kq= x + STT(n);
	int year=n.year;
	if(x <= 365)//neu so nguyen duong nhap tu ban phim nho hon 365
		if(kq <= 365) //neu kq nho hon 365
			return NgayTuSTT(kq,year); //tra ve kq
		else //neu kq <365
			if(ktnhuan(year)==1)//la nam nhuan
				if(kq == 366)//neu kq=366
					return NgayTuSTT(kq,year);//tra ve kq
				else//kq >366
					return NgayTuSTT(kq-366,year+1);//lay kq-365, nam tang them 1
			else//khong la nam nhuan
				return 	NgayTuSTT(kq-365,year+1);//lay kq-365, nam tang them 1
	
	else//neu so nguyen duong lon hon 365
		if(ktnhuan(year)==1)//la nam nhuan
			return NgayTuSTT(kq+366,year+1);//kq cong them 366 va nam tang them 1
		else
			return NgayTuSTT(kq+365,year+1);//kq cong them 365 va nam tang them 1
}

NgayThang TruNgayThang(NgayThang n,int x)
{
	int kq= STT(n)-x;
	int year=n.year;
			
}

int main()
{
	NgayThang ngay;
	string st;
	int x;
	Nhap(st, ngay);
	chuoi(st, ngay);
	cout << "\nSTT ngay trong nam la: " << STT(ngay);
	cout<<"\nNhap vao so nguyen can tinh: ";
	cin>> x;
	cout<<"Ngay thang nam sau khi cong voi so "<<x<<" la: "<<TongNgayThang(ngay,x).dd<<"/"<<TongNgayThang(ngay,x).mm<<"/"<<TongNgayThang(ngay,x).year;
}
