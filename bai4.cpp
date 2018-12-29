#include<iostream>
#include<fstream>

using namespace std;

fstream fi;

void DocFile(int a[10][10],int n)//Doc file
{
	for(int i = 0; i < n; i++)
		for(int j=0;j < n;j++)
			fi >> a[i][j];
	fi.close();
}

void XuatDoThi(int a[10][10],int n) //xuat ra man hinh
	{
		for(int i = 0; i < n; i++)
		{
		for(int j=0;j < n;j++)
			cout << a[i][j]<<" ";
			cout<<endl;
		}
	}
void TaoMoi(int a[10][10], int &n)//tao moi 1 mang 2 chieu
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

typedef struct Cap
{
	int Dinh;
	int Tong;
}Cap;

DuongDiNN()
{
	
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

/*tao 1 bien di
Xet cac dinh chua duoc chon
Kiem tra xem co duong di tu dinh duoc chon toi dinh con lai
Neu co duong di -> gan dinh dang xet 
*/

