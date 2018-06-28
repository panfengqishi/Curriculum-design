/*************************************************
Copyright (C), 2018, Tyut
File name:     taManager.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   助教博士生管理类 
*************************************************/
#ifndef TaManager_H
#define TaManager_H

#include <iostream>
#include <string>
#include <fstream>
#include "ta.h"

using namespace std;

class TaManager{
private:
	int top;
	TA tas[100];
public:
	TaManager();
	~TaManager();
	int queryByNo(string sno);
	void clearStudent();
	int addStudent(TA s);
	int modifyStudent(string sno);
	int deleteStudent(string sno);
	int queryStudent(string sno);

	void displayAll();
	void dataManage();
	void dataSave();
	void dataRead();
};

TaManager::TaManager(){
	dataRead();
}

int TaManager::queryByNo(string sno){
	for(int i=0;i<=top;i++){
		if(tas[i].getStudentNo()==sno){
			return i;
		}
	}
	return -1;
}

void TaManager::clearStudent(){
	top=-1;
}

int TaManager::addStudent(TA s){
	int p=queryByNo(s.getStudentNo());
	if(p==-1){
		top++;
		tas[top]=s;
		dataSave();
		return 1;
	}
	else{
		cout<<"--------->此学生已经存在 !<----------"<<endl<<endl;
		return 0;
	}
}

int TaManager::modifyStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{
		cout << "请输入该生的新信息: " << endl<<endl;
		tas[p].inputData();
		dataSave();
		return 1;
	}
}

int TaManager::deleteStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{
		for(int i=p;i<top;i++){
			tas[i]=tas[i+1];
		}
		top--;
		cout << "--------->删除完成!<----------" << endl<<endl;
		dataSave();      
		return 1;
	}
}

int TaManager::queryStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->此学生不存在 !<----------"<<endl<<endl;
		return 0;
	}
	else{  
		cout<<"--------->此学生存在:<----------"<<endl<<endl;  
		tas[p].displayDetails();
		return 1;
	}
}

void TaManager::displayAll(){
	for(int i=0;i<=top;i++){
		cout << "--------第"<< i <<"个学生情况----------" << endl<<endl;
		tas[i].displayDetails();
	}
}

TaManager::~TaManager(){
	dataSave();
}

void TaManager::dataManage(){
	int choice=1;
	string sstudentNo;
	TA s;

	while (choice!=0)
	{
		cout << "********************************************" << endl;           
		cout << "\t\t助教博士生维护\n";
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

void TaManager::dataSave(){
	fstream file("Ta.dat",ios::out);
	for(int i=0;i<=top;i++){
		file.write((char*)&tas[i],sizeof(tas[i]));
	}
	file.close();
}

void TaManager::dataRead(){
	TA s;
	top=-1;
	fstream file("Ta.dat",ios::in);
	while(1){
		file.read((char*)&s,sizeof(s));
		if(!file){
			break;
		}
		top++;
		tas[top]=s;
	}
	file.close();
}

#endif