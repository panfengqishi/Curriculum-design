/*************************************************
Copyright (C), 2018, Tyut
File name:     person.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   ��Ա�� 
*************************************************/
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <cstring>
#include <string>
#include "date.h"
#include "string_1.h"

using namespace std;

class Person{
protected:
	char name[20];
	char id[20];
	char gender[10];   //ע�⣺��Ҫ����3���ַ���
	Date birthday;
public:
	Person();
	Person(char* sname,char* sid,char* sgender,int yy,int mm,int dd);
	~Person(){}

	void setName(char* sname){
		Strcpy(name,sname);
	}

	char* getName(){
		return name;
	}

	void setId(char* sid){
		Strcpy(id,sid);
	}

	char* getId(){
		return id;
	}

	void setGender(char* sgender){
		Strcpy(gender,sgender);
	}

	char* getGender(){
		return gender;
	}

	void setBirthday(Date d){
		birthday=d;
	}

	Date getBirthday(){
		return birthday;
	}

	virtual void inputData();

	virtual void displayDetails();
};

Person::Person(){
	Strcpy(name,"NA");
	Strcpy(gender,"��");
	Strcpy(id,"000");
	//Data d(1980,1,1);
	//birthday=d;
}

Person::Person(char* sname,char* sid,char* sgender,int yy,int mm,int dd):birthday(yy,mm,dd){
	Strcpy(name,sname);
	Strcpy(id,sid);
	Strcpy(gender,sgender);
}

void Person::inputData(){
	cout<<"������";
	cin>>name;
	cout<<"���֤�ţ�";
	cin>>id;
	cout<<"�Ա�";
	cin>>gender;
	cout<<"�������£�"<<endl;
	birthday.inputData();
}

void Person::displayDetails(){
	cout<<"������"<<name<<endl;
	cout<<"���֤�ţ�"<<id<<endl;
	cout<<"�Ա�"<<gender<<endl;
	cout<<"�������ڣ�";
	birthday.displayDetails();
}

#endif