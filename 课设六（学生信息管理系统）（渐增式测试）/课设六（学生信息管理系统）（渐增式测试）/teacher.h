/*************************************************
Copyright (C), 2018, Tyut
File name:     teacher.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   ��ʦ�� 
*************************************************/
#ifndef TEACHER_H
#define TEACHER_H

#include <iostream>
#include <string>
#include <cstring>
#include "person.h"
#include "string_1.h"

using namespace std;

class Teacher:public Person{
protected:
	char teacherNo[20];
	char schoolName[20];
	char department[20];
public:
	Teacher();
	Teacher(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
		char* steacherNo,char* sschool,char* sdepartment);
	~Teacher(){}

	void setTeacherNo(char* sno){
		Strcpy(teacherNo,sno);
	}
	char* getTeacherNo(){
		return teacherNo;
	}

	void setSchoolName(char* sschool){
		Strcpy(schoolName,sschool);
	}
	char* getSchoolName(){
		return schoolName;
	}

	void setDepartment(char* sdepartment){
		Strcpy(department,sdepartment);
	}
	char* getDepartment(){
		return department;
	}

	virtual void inputData();
	virtual void displayDetails();
};

Teacher::Teacher():Person(){
	Strcpy(teacherNo,"001");
	Strcpy(schoolName,"defaultSchoolName");
	Strcpy(department,"defaultDepartment");
}

Teacher::Teacher(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
	char* steacherNo,char* sschool,char* sdepartment):Person(sname,sid,sgender,yy,mm,dd){
		Strcpy(teacherNo,steacherNo);
		Strcpy(schoolName,sschool);
		Strcpy(department,sdepartment);
}

void Teacher::inputData(){
	Person::inputData();
	cout<<"��ʦ��ţ�";
	cin>>teacherNo;
	cout<<"ѧУ��";
	cin>>schoolName;
	cout<<"���ţ�";
	cin>>department;
}

void Teacher::displayDetails(){
	Person::displayDetails();
	cout<<"��ʦ��ţ�"<<teacherNo<<endl;
	cout<<"ѧУ��"<<schoolName<<endl;
	cout<<"���ţ�"<<department<<endl;
}

#endif