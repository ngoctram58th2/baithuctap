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
vector<Contact>db; 

void DanhBa(Contact c)
{
 	strcpy(c.ten,"hfgh");
	strcpy(c.sdt,"46564");
	strcpy(c.gmail,"rtyrty");
	strcpy(c.diachi,"fafafadfa");
	db.push_back(c);
}

void GhiVaoFile()
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
FILE *f = fopen("db.dat","rb");
	for(int i=0;i<db.size();i++)
		{
			Contact c;
			fread(&c,sizeof(c),1,f);
			db.push_back(c);
		}
	fclose(f);
	}


void ThemDB(Contact c)
{

	strcpy(c.ten,"fsdfsd");
	strcpy(c.sdt,"423535");
	strcpy(c.gmail,"rtyrty");
	strcpy(c.diachi,"fafafadfa");
	db.push_back(c);
}


void LietKe()
	{
		
	for (int i = 0; i<db.size();i++)
		{
		  cout << "\nSo dien thoai: "<<db[i].sdt<<endl;
		  cout << "Ten: "<<db[i].ten<<endl;
		  cout << "Gmail: "<<db[i].gmail<<endl;
		  cout << "Dia chi: "<<db[i].diachi<<endl;
		}
	}
//them moi contact vao dl
void ThemMoi(Contact c)
{
	  db.push_back(c);
	  GhiVaoFile();
}
void CapNhat() 
//void CapNhat(Contact c);
//tim contact, co sdt
//cap nhat c vao m
{
	Contact c;
	FILE*f=fopen("db.dat","wb");
	cout<<"\n------------------------------\n";
	cout <<"Danh ba sau khi cap nhat";
	LietKe();
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}



/*
//them vao du lieu
//ghi du lieu vao file
int LietKeDB();
//in cac phan tu cua db ra man hinh
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
	Contact c,c1;
	strcpy(c.ten,"hfgh");
	strcpy(c.sdt,"46564");
	strcpy(c.gmail,"rtyrty");
	strcpy(c.diachi,"fafafadfa");
	ThemMoi(c);
	ThemDB(c1);
	LietKe();
	CapNhat();
}
	
