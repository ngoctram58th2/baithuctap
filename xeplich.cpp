#include<iostream>
using namespace std;
void SapXep(int a[], int b[], int c[], int n)
{
	for(int i=0; i< n-1; i++)
	for(int j=i+1;j< n;j++)
	if( b[i]>b[j]){
		swap(b[i],b[j]);
		swap(c[i],c[j]);
		swap(a[i],a[j]);
	}
}
int GTLN(int a[],int n){
	int m=a[0];
	for(int i=0;i<n;i++)
	if(m<a[i]) m= a[i];
	return m;
}
int XepLich(int a[], int b[], int c[], int n){
	int L[n];
	for(int i=0; i< n; i++)
	{
		L[i]= c[i];
		for(int j=0; j<n; j++)
		if(b[j]>=a[i]&&L[i]<L[j]+c[i])
		L[i]=L[j]+c[i];
	}
	return GTLN(L,n);
}
void XuatMang(int a[], int n){
	for (int i=0; i<n;i++)
	cout<< a[i]<<" ";
	cout<< endl;
}
int main(){
	int a[6]={3,1,9,5,4,6};
	int b[6]={7,8,12,10,7,12};
	int c[6]={4,2,7,9,3,5};
	SapXep(a,b,c,6);
	XuatMang(a,6);
	XuatMang(b,6);
	XuatMang(c,6);
	cout<<"so tien thu duoc lon nhat:"<<XepLich(a,b,c,6);
}
