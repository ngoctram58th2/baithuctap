#include<iostream>
#include<fstream>

using namespace std;

fstream fi;


void DocFile(int a[10][10],int n)
{
	for(int i = 0; i < n; i++)
		for(int j=0;j < n;j++)
			fi >> a[i][j];
	fi.close();
}

void XuatDoThi(int a[10][10],int n)
	{
		for(int i = 0; i < n; i++)
		{
		for(int j=0;j < n;j++)
			cout << a[i][j]<<" ";
			cout<<endl;
		}
	}
void TaoMoi(int a[10][10], int &n)
{
	cout<<"Nhap n: ";
	cin>>n;
	fi.open("dothi.txt",ios::out);
	fi<<n<<endl;
	for(int i=0;i<n; i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<"Hang so "<<i<<" cot " << j <<" :";
			cin >> a[i][j];
			fi<<a[i][j]<<" ";
		}
		cout<<endl;
		fi<<endl;
	}
	fi.close();
}

int main()
{
	int n;
	int a[10][10];
	TaoMoi(a,n);
	fi.open("dothi.txt",ios::in);
	fi >> n;
	DocFile(a,n);
	XuatDoThi(a,n);
	fi.close();
}
