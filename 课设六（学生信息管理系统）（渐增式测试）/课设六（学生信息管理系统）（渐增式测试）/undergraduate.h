/*************************************************
Copyright (C), 2018, Tyut
File name:     undergraduate.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   本科生类 
*************************************************/
#ifndef UNDERGRADUATE_H
#define UNDERGRADUATE_H

#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
#include "string_1.h"

using namespace std;

class UnderGraduate:public Student{
protected:
	char major[20];
public:
	UnderGraduate();
	UnderGraduate(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
		char* sstudentNo,char* sschoolName,char* sclassIn,char* smajor);
	~UnderGraduate(){};

	void setMajor(char* smajor){
		Strcpy(major,smajor);
	}
	char* getMajor(){
		return major;
	}

	virtual void inputData();
	virtual void displayDetails();
};

UnderGraduate::UnderGraduate():Student(){
	Strcpy(major,"defaultMajor");
}

UnderGraduate::UnderGraduate(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
	char* sstudentNo,char* sschoolName,char* sclassIn,char* smajor)
	:Student(sname,sid,sgender,yy,mm,dd,sstudentNo,sschoolName,sclassIn){
		Strcpy(major,smajor);
}

void UnderGraduate::inputData(){
	Student::inputData();
	cout<<"专业：";
	cin>>major;
}

void UnderGraduate::displayDetails(){
	Student::displayDetails();
	cout<<"专业："<<major<<endl;
}

#endif