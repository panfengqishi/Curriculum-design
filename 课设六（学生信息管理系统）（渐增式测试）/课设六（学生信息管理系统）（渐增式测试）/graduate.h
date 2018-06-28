/*************************************************
Copyright (C), 2018, Tyut
File name:     graduate.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   研究生类 
*************************************************/
#ifndef GRADUATE_H
#define GRADUATE_H
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <cstring>
#include "student.h"
#include "string_1.h"

using namespace std;

class Graduate:public Student{
protected:
	char direction[20];
	char adviserName[20];
public:
	Graduate();
	Graduate(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
		char* sstudentNo,char* sschoolName,char* sclassIn,
		char* sdirection,char* sadviserName);
	~Graduate(){}

	void setDirection(char *sdirection){
		Strcpy(direction,sdirection);
	}
	char* getDirection(){
		return direction;
	}

	void setAdviserName(char* sadviserName){
		Strcpy(adviserName,sadviserName);
	}
	char* getAdviserName(){
		return adviserName;
	}

	void inputData();
	void displayDetails();
};

Graduate::Graduate():Student(){
	Strcpy(direction,"defaultDirection");
	Strcpy(adviserName,"defaultAdviserName");
}

Graduate::Graduate(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
	char* sstudentNo,char* sschoolName,char* sclassIn,
	char* sdirection,char* sadviserName)
	:Student(sname,sid,sgender,yy,mm,dd,sstudentNo,sschoolName,sclassIn){
		Strcpy(direction,sdirection);
		Strcpy(adviserName,sadviserName);
}

void Graduate::inputData(){
	Student::inputData();
	cout<<"研究方向：";
	cin>>direction;
	cout<<"导师姓名：";
	cin>>adviserName;
}

void Graduate::displayDetails(){
	Student::displayDetails();
	cout<<"研究方向："<<direction<<endl;
	cout<<"导师姓名："<<adviserName<<endl;
}

#endif
#endif