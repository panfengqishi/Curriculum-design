/*************************************************
Copyright (C), 2018, Tyut
File name:     graduateManager.h
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   �о��������� 
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
		cout<<"--------->��ѧ���Ѿ����� !<----------"<<endl<<endl;
		return 0;
	}
}

int GraduateManager::modifyStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else{
		cout << "���������������Ϣ: " << endl<<endl;
		graduates[p].inputData();
		dataSave();
		return 1;
	}
}

int GraduateManager::deleteStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else{
		for(int i=p;i<top;i++){
			graduates[i]=graduates[i+1];
		}
		top--;
		cout << "--------->ɾ�����!<----------" << endl<<endl;
		dataSave();//����       
		return 1;
	}
}

int GraduateManager::queryStudent(string sno){
	int p=queryByNo(sno);
	if(p==-1){
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else{  
		cout<<"--------->��ѧ������:<----------"<<endl<<endl;  
		graduates[p].displayDetails();
		return 1;
	}
}

void GraduateManager::displayAll(){
	for(int i=0;i<=top;i++){
		cout << "--------��"<< i <<"��ѧ�����----------" << endl<<endl;
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
		cout << "\t\t�о���ά��\n";
		cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl; 
		cout << "\n \t\t 1:���� ";
		cout << "\n \t\t 2:�޸� ";
		cout << "\n \t\t 3:ɾ�� ";
		cout << "\n \t\t 4:���� ";
		cout << "\n \t\t 5:��ʾ ";
		cout << "\n \t\t 6:ȫ��ɾ�� "; 
		cout << "\n \t\t 0:�˳� " ;
		cout << endl;
		cout << "*********************************************" << endl;
		cout << "��ѡ��" << endl;
		cin >> choice;
		switch(choice){
		case 1:
			s.inputData();
			addStudent(s);
			break;
		case 2:
			cout << " ������ѧ��:";
			cin >> sstudentNo;        
			modifyStudent(sstudentNo);
			break;
		case 3:
			cout << " ������ѧ��:";
			cin >> sstudentNo;
			deleteStudent(sstudentNo);
			break;
		case 4:
			cout << " ������ѧ��:";
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