#include <iostream>
#include<string>
#include<stdlib.h>
using namespace std;
typedef struct NgayThang
{
	int dd,mm,year;

}NgayThang;

void chuoi( string st,NgayThang &x);
int NamNhuan(int year);
int stt(NgayThang x);
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
NgayThang NgayTuSTT(int stt, int year);
NgayThang congNgayThang(NgayThang x, int a)
void Nhap(string &st, NgayThang &Nt)
{
	cout <<"Nhap ngay thang nam:";
	getline(cin,st);

}
void chuoi(string &s, NgayThang &ngay)
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
	int stt=0;
	for(int i=0;i<n.mm;i++)
		stt += n.dd;
		if(ktranhuan) std+1;
		else stt;
int TongNgayThang(int stt, int year)
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

NgayThang NgayTuSTT(int stt, int year){
	int i=1;
	int ngay=stt;
	int kt =NamNhuan(year);
	while(stt > 0){
		if((kt == 1) && (i==2))
			stt = stt-29;
		else stt = stt- month[i];
		if(stt > 0)
		{
			ngay= stt;
			i++;
		}	
		ngaythang x;
		x.dd=ngay;
		x.mm=i;
		x.year= year;
		return x;			
	}	
}
int stt(NgayThang x)
{
	int stt=0;
	for(int i =0; i< x.month; i++)
	stt+=month[i];
	stt += x.day;
	if(NamNhuan==0 && x.month>2) stt+=1;
	return stt;

}

void Cong(NgayThang a, int &x)
{
	
	cout << "\nnhap so cong them: ";
	cin >> x;
	
	int n = STTday(a) + x;
	
	NgayThang b;
	b.year = a.year;
	b.month = 1;
	b.day = 0;
	
	while(n > 365)
		for(n; n >= 366; n-=366)
		{
			if(KTyear(b) == 0)
				n++;
			b.year++; 
		}
	if(n == 365)
	{
		b.year++; 
		b.day = 1; 
		b.month = 1; 
	}
	else
		if(n < 365)
			STTSangNgay(b, n); 
}
-
int main()
{	
	struct NgayThang ngay;
	string s;
	
	Nhap(s,ngay);
	chuoi(s,ngay);
	cout<<endl;

}
