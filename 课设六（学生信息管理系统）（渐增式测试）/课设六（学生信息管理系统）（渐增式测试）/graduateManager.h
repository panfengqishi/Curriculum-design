/*************************************************
Copyright (C), 2018, Tyut
File name:     graduateManager.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   研究生管理类 
*************************************************/
#ifndef GRADUATEMANAGER_H
#define GRADUATEMANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "graduate.h"

using namespace std;

class GraduateManager{
private:
	int top;
	Graduate graduates[100];
public:
	GraduateManager();
	~GraduateManager();
	int queryByNo(string sno);
	void clearStudent();
	int addStudent(Graduate s);
	int modifyStudent(string sno);
	int deleteStudent(string sno);
	int queryStudent(string sno);

	void displayAll();
	void dataManage();
	void dataSave();
	void dataRead();
};

GraduateManager::GraduateManager(){
	dataRead();
}

int GraduateManager::queryByNo(string sno){
	for(int i=0;i<=top;i++){
		if(graduates[i].getStudentNo()==sno){
			return i;
		}
	}
	return -1;
}

void GraduateManager::clearStudent(){
	top=-1;
}

int GraduateManager::addStudent(Graduate s){
	int p=queryByNo(s.getStudentNo());
	if(p==-1){
		top++;
		graduates[top]=s;
		dataSave();
		return 1;
	}
	else{
		cout<<"--------->此学生已经存在 !<----------"<<endl<<endl;
		return 0;
	}
}

int GraduateManager::modifyStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{
		cout << "请输入该生的新信息: " << endl<<endl;
		graduates[p].inputData();
		dataSave();
		return 1;
	}
}

int GraduateManager::deleteStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{
		for(int i=p;i<top;i++){
			graduates[i]=graduates[i+1];
		}
		top--;
		cout << "--------->删除完成!<----------" << endl<<endl;
		dataSave();//保存       
		return 1;
	}
}

int GraduateManager::queryStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{  
		cout<<"--------->此学生存在:<----------"<<endl<<endl;  
		graduates[p].displayDetails();
		return 1;
	}
}

void GraduateManager::displayAll(){
	for(int i=0;i<=top;i++){
		cout << "--------第"<< i <<"个学生情况----------" << endl<<endl;
		graduates[i].displayDetails();
	}
}

GraduateManager::~GraduateManager(){
	dataSave();
}

void GraduateManager::dataManage(){
	int choice=1;
	string sstudentNo;
	Graduate s;

	while (choice!=0)
	{
		cout << "********************************************" << endl;           
		cout << "\t\t研究生维护\n";
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl; 
		cout << "\n \t\t 1:新增 ";
		cout << "\n \t\t 2:修改 ";
		cout << "\n \t\t 3:删除 ";
		cout << "\n \t\t 4:查找 ";
		cout << "\n \t\t 5:显示 ";
		cout << "\n \t\t 6:全部删除 "; 
		cout << "\n \t\t 0:退出 " ;
		cout << endl;
		cout << "*********************************************" << endl;
		cout << "请选择：" << endl;
		cin >> choice;
		switch(choice){
		case 1:
			s.inputData();
			addStudent(s);
			break;
		case 2:
			cout << " 请输入学号:";
			cin >> sstudentNo;        
			modifyStudent(sstudentNo);
			break;
		case 3:
			cout << " 请输入学号:";
			cin >> sstudentNo;
			deleteStudent(sstudentNo);
			break;
		case 4:
			cout << " 请输入学号:";
			cin >> sstudentNo;
			queryStudent(sstudentNo); 
			break;
		case 5:
			displayAll();
			break;
		case 6:
			clearStudent();
			break;
		default:
			break;
		}
	}
}

void GraduateManager::dataSave(){
	fstream file("Graduate.dat",ios::out);
	for(int i=0;i<=top;i++){
		file.write((char*)&graduates[i],sizeof(graduates[i]));
	}
	file.close();
}

void GraduateManager::dataRead(){
	Graduate s;
	top=-1;
	fstream file("Graduate.dat",ios::in);
	while(1){
		file.read((char*)&s,sizeof(s));
		if(!file){
			break;
		}
		top++;
		graduates[top]=s;
	}
	file.close();
}

#endif