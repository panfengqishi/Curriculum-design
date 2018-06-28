/*************************************************
Copyright (C), 2018, Tyut
File name:     student.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   学生类 
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
	cout<<"学生编号：";
	cin>>studentNo;
	cout<<"学校：";
	cin>>schoolName;
	cout<<"班级:";
	cin>>classIn;
}

void Student::displayDetails(){
	Person::displayDetails();
	cout<<"学生编号："<<studentNo<<endl;
	cout<<"学校："<<schoolName<<endl;
	cout<<"班级："<<classIn<<endl;
}

#endif