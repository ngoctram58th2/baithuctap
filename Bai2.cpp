#include <iostream>
#include <stdlib.h>
using namespace std;

typedef struct NgayThang
{
	int dd;
	int mm;
	int year;
}NgayThang;

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

int ktnhuan (NgayThang ngay)
{
	 if(((ngay.year)%100 == 0) && ((ngay.year)%400 == 0) || (((ngay.year)%100 != 0) && ((ngay.year)%4 == 0)))
        return 1;
    else
        return 0;
}

int NgayTungThang(NgayThang date, int i)
{
	int SoNgay;
	
	switch (i)
	{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12: 
			SoNgay = 31;
			break;
		case 4:
		case 6:
		case 9:
		case 11: 
			SoNgay = 30;
			break;
		case 2:
			if (ktnhuan(date) == 1)
			{
				SoNgay = 29;
			}
			else
			{
				SoNgay = 28;
			}
			break;
	}

	return SoNgay;	
}

int NgayTuSTT(NgayThang date)
{
	int ngay = date.dd;
	for(int i = 1; i <= date.mm - 1; i++)
	{
		ngay = ngay + NgayTungThang(date, i);
	}
	return ngay;
}


int main()
{
	struct NgayThang ngay;
	string st;
	Nhap(st, ngay);
	chuoi(st, ngay);
	if(ktnhuan(ngay) == 1 ) cout << ngay.year << " la nam nhuan";
	else cout << ngay.year << " khong phai nam nhuan";
	cout << "\nSTT ngay trong nam la: " << NgayTuSTT(ngay);
	
}
