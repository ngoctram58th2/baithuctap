#include <iostream>
#include <stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<fstream>
#include<vector>
#include<string>
#include<windows.h>
#include <cstdlib>
using namespace std;


typedef struct Contact
{
	char ten[20];
	char sdt[11];
	char gmail[20];
	char diachi[50];
	bool gioitinh;
}Contact;
void Nhap()
{
	Contact c;
	strcpy(c.ten,"abc");
	strcpy(c.sdt,"4564645");
	strcpy(c.gmail,"abcs@gmail.com");
	strcpy(c.diachi,"ryhr64465");
}
vector<Contact> db;

void GhiVaoFile()
{

	FILE*f=fopen("db.dat","wb");
	Contact c;
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}

void DocFile()
{
	db.clear();
	FILE*f =fopen("db.dat","rb");
	if( f != NULL)
	{
		while(!feof(f)){
			Contact c;
			fread(&c,sizeof(Contact),1,f);	
			db.push_back(c);
		}
			fclose(f);
			db.pop_back();
	}	
}


void ThemDB(Contact c)
{
	cout<<"Them danh ba\n";
	cout<<"So dien thoai: ";
	cin.getline(c.sdt,11);
	cout<<"Ten: ";
	cin.getline(c.ten,20);
	cout<<"Gmail: ";
	cin.getline(c.gmail,20);
	cout<<"Dia chi: ";
	cin.getline(c.diachi,50);
	db.push_back(c);
}


void LietKe()
	{
	Contact c;
	for (int i = 0; i<sizeof(db);i++)
		{
		  cout << "\nSo dien thoai: "<<c.sdt<<endl;
		  cout << "Ten: "<<c.ten<<endl;
		  cout << "Gmail: "<<c.gmail<<endl;
		  cout << "Dia chi: "<<c.diachi<<endl;
		}
	}
	
void ThemMoi(Contact c)
{
	db.push_back(c);
	GhiVaoFile();
}

void CapNhat(Contact c)
{
	FILE*f=fopen("db.dat","wb");
//	Contact cmoi;
	ThemMoi(c);
	LietKe();
	for(int i = 0 ; i < sizeof(db) ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
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
	DocFile();
	LietKe();
	Contact c;
		strcpy(c.ten,"pipi");
		strcpy(c.sdt,"2656565400");
		strcpy(c.gmail,"asdas@gmail.com");
		strcpy(c.diachi,"fafafadfa");
	ThemMoi(c);
	Contact c1;
		strcpy(c1.ten,"pipivdzvs");
		strcpy(c1.sdt,"265650056565");
		strcpy(c1.gmail,"asdaxzzs@gmail.com");
		strcpy(c1.diachi,"nha trang");
	ThemMoi(c1);
	cout<<"DB";
	LietKe();
	Contact c2;
	ThemDB(c2);
	cout<<"Cap nhat";
	CapNhat(c2);
	GhiVaoFile();
}
	
