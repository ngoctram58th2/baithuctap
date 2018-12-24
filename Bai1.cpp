#include <iostream>
using namespace std;
int main()
{
	nt year;
cout<<"Nhap nam: ";
cin>>year;
if( (year%400==0) || (year%4==0 && year%100!=0))
cout<<"Nam "<<year<<" la nam nhuan";
else cout<<"Nam "<<year<<" khong la nam nhuan";
}
