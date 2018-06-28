/*************************************************
Copyright (C), 2018, Tyut
File name:     ta.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   助教博士生类 
*************************************************/
#ifndef TA_H
#define TA_H

#include <iostream>
#include <string>
#include <cstring>
#include "graduate.h"
#include "teacher.h"
#include "string_1.h"

using namespace std;

class TA:public Graduate,public Teacher{
public:
	TA();
	TA(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
		char* sstudentNo,char* sschoolName,char* sclassIn,
		char* sdirection,char* sadviserName,
		char* steacherNo,char* sschool,char* sdepartment);
	~TA(){};
	virtual void inputData();
	virtual void displayDetails();
};

TA::TA():Graduate(){
	Strcpy(teacherNo,"001");
	Strcpy(Student::schoolName,"defaultSchoolName");
	Strcpy(department,"defaultDepartment");
}

TA::TA(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
	char* sstudentNo,char* sschoolName,char* sclassIn,
	char* sdirection,char* sadviserName,
	char* steacherNo,char* sschool,char* sdepartment)
	:Graduate(sname,sid,sgender,yy,mm,dd,
	sstudentNo,sschoolName,sclassIn,
	sdirection,sadviserName)
{
	Strcpy(teacherNo,steacherNo);
	Strcpy(Student::schoolName,sschool);
	Strcpy(department,sdepartment);
}

void TA::inputData(){
	Graduate::inputData();
	cout<<"教师编号：";
	cin>>teacherNo;
	cout<<"部门：";
	cin>>department;
}

void TA::displayDetails(){
	Graduate::displayDetails();
	cout<<"教师编号："<<teacherNo<<endl;
	cout<<"部门："<<department<<endl;
}

#endif