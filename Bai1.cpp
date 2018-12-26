#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<fstream>
#include<vector>
#include<string>

using namespace std;


typedef struct Contact
{
	char ten[20];
	char sdt[11];
	char gmail[20];
	char diachi[50];
	bool gioitinh;	
}Contact;
void Nhap(Contact c)
{
	cout <<"0168546321"<<c.sdt<<"\n";
	cout<<"Ten"<<c.ten<<"\n";
}
vector<Contact> db;
void GhiVaoDB()
{
	
	int size = db.size();
	FILE * f=fopen("db.dat","wb");
	Contact c;
	for(int i=0; i <size; i++)
		{
			c=db[i];
			fwrite(&c, sizeof(Contact),1,f);
		}
		fclose(f);
}
void DocFile()
{
	db.clear();
	FILE*f;
	f=fopen("db.dat","rb");
	Contact c;
	if(f!=NULL)
	{
		while(!feof(f))
		{
			fread(&c,sizeof(Contact),1,f);
			db.push_back(c);
		}
		fclose(f);
		db.pop_back();
			
	}
}
void ThemMoi(Contact c)  
{	
	  db.push_back(c);
	  GhiVaoDB();
}


/*void LietKe()
{
	DocFile();
	for (int i = 0; i<sizeof(db);i++)
	Xuat(db[i]);
}
/*them moi contact vao dl
//them vao du lieu
//ghi du lieu vao file
int LietKeDB();
//in cac phan tu cua db ra man hinh
void CapNhat(Contact c);
//tim contact, co sdt
//cap nhat c vao m
//ghi dl vao file
void XoaContact(char*sdt);
//tim contact m co sdt trong db
//xoa contact m
//ghi db vao file

TimTheoTen(char*ten);
//tim contact m co theo ten
//them m vao vector
//*/
int main()
{
	Contact c;
	Nhap(c);
	DocFile();
	GhiVaoDB();
	ThemMoi(c);
}
