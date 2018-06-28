/*************************************************
Copyright (C), 2018, Tyut
File name:     student.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   ѧ���� 
*************************************************/
#ifndef STUDENT_H
#define STUDNET_H

#include <iostream>
#include <string>
#include <cstring>
#include "person.h"
#include "string_1.h"

using namespace std;

class Student:public Person{
protected:
	char studentNo[20];
	char schoolName[20];
	char classIn[20];
public:
	Student();
	Student(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
		char* sstudentNo,char* sschoolName,char* sclassIn);
	~Student(){}

	void setStudentNo(char* sstudentNo){
		Strcpy(studentNo,sstudentNo);
	}
	char* getStudentNo(){
		return studentNo;
	}

	void setSchoolName(char* sschoolName){
		Strcpy(schoolName,sschoolName);
	}
	char* getSchoolName(){
		return schoolName;
	}

	void setClassIn(char* sclassIn){
		Strcpy(classIn,sclassIn);
	}
	char* getClassIn(){
		return classIn;
	}

	virtual void inputData();
	virtual void displayDetails();
};

Student::Student():Person(){
	Strcpy(studentNo,"001");
	Strcpy(schoolName,"defaultSchoolName");
	Strcpy(classIn,"defaultClassIn");
}

Student::Student(char* sname,char* sid,char* sgender,int yy,int mm,int dd,
	char* sstudentNo,char* sschoolName,char* sclassIn)
	:Person(sname,sid,sgender,yy,mm,dd){
		Strcpy(studentNo,sstudentNo);
		Strcpy(schoolName,sschoolName);
		Strcpy(classIn,sclassIn);
}

void Student::inputData(){
	Person::inputData();
	cout<<"ѧ����ţ�";
	cin>>studentNo;
	cout<<"ѧУ��";
	cin>>schoolName;
	cout<<"�༶:";
	cin>>classIn;
}

void Student::displayDetails(){
	Person::displayDetails();
	cout<<"ѧ����ţ�"<<studentNo<<endl;
	cout<<"ѧУ��"<<schoolName<<endl;
	cout<<"�༶��"<<classIn<<endl;
}

#endif