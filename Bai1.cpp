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
}Contact;
vector<Contact>db;
 
void GhiVaoFile();
void Them(Contact c);
void DanhBa();
void DocFile();
void ThemDB(Contact c);
void LietKe();
void Xuat(Contact c);
void CapNhat();
void TimTheoTen(char t[]);


void GhiVaoFile()//ghi du lieu vao file
{
	FILE * f=fopen("db.dat","wb");//mo file len
	Contact c;
	for(int i=0; i < db.size(); i++)
		{
			c=db[i];
			fwrite(&c, sizeof(Contact),1,f);
		}
		fclose(f);
}
void Them(Contact c) //them vao du lieu va xuat ra man hinh
{
	  db.push_back(c);//them 1 gia tri cho vecto
	  GhiVaoFile();
}
void DanhBa()
{
	Contact c;
 	strcpy(c.ten,"bo");
	strcpy(c.sdt,"054365465");
	strcpy(c.gmail,"bo@gmail.com");
	strcpy(c.diachi,"59 Nguyen Dinh Chieu");
	Them(c);
	strcpy(c.ten,"uyen phuong");
	strcpy(c.sdt,"035463214");
	strcpy(c.gmail,"phuong@gmail.com");
	strcpy(c.diachi,"59 Nguyen Dinh Chieu");
	Them(c);
	strcpy(c.ten,"thu");
	strcpy(c.sdt,"0643534533");
	strcpy(c.gmail,"thu@gmail.com");
	strcpy(c.diachi,"24 Doan Tran Nghiep");
	Them(c);
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

void Xoa(char sd[])

{
for(int i=0;i<db.size();i++)
			if(strcmp(db[i].sdt,sd)==0)// so sanh sdt can tim voi sdt trong danh ba
				db.erase(db.begin()+i);//xoa db da tim duoc
	cout<<"Cap nhat lai danh ba sau khi xoa: ";
	CapNhat();	//xuat ra cac danh ba con lai
}

void ThemDB(Contact c)//them vao 1 danh ba
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
	Them(c);
}


void LietKe()
	{
		
	for (int i = 0; i<db.size();i++) //vong lap for 
		{
		  cout << "\nSo dien thoai: "<<db[i].sdt<<endl;
		  cout << "Ten: "<<db[i].ten<<endl;
		  cout << "Gmail: "<<db[i].gmail<<endl;
		  cout << "Dia chi: "<<db[i].diachi<<endl;
		}
	}
	
void Xuat(Contact c)
{
		cout<<"Ten: "<<c.ten<<endl;
		cout<<"So dien thoai: "<<c.sdt<<endl;
		cout<<"Dia chi: "<<c.diachi<<endl;
		cout<<"Gmail: "<<c.gmail<<endl;
}
//them moi contact vao dl
void CapNhat() 
//cap nhat them vao
{
	Contact c;
	FILE*f=fopen("db.dat","wb");//mo file len
	cout<<"\n------------------------------\n";
	cout <<"Danh ba sau khi cap nhat";
	LietKe();
	for(int i = 0 ; i < db.size() ; i++)
		fwrite(&db[i],sizeof(db),1,f);	
		fclose(f);
}

void TimTheoTen(char t[])
{
	for(int i=0;i<db.size();i++)
			if(strcmp(db[i].ten,t)==0)// so sanh de tim ten trong danh sach voi ten nhap
				Xuat(db[i]);
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
	Contact c;
	//Danh ba co san
	ThemDB(c);//them 1 danh ba moi
	DanhBa();
	CapNhat();
	cout<<"-----------------------------\n";
	cout<<"Tim kiem theo ten(bo): "<<endl;
	TimTheoTen("bo");
	cout<<"-----------------------------\n";
	cout<<"Xoa danh ba co sdt 0643534533\n";
	Xoa("0643534533");
	
}
	
