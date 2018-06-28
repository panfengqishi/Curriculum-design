/*************************************************
Copyright (C), 2010, Tyut
File name:     undergraduateManager.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Description:   ������������ 
*************************************************/
#ifndef UNDERGRADUATE_MANAGER_H
#define UNDERGRADUATE_MANAGER_H

#include <iostream>
#include <string>
#include <fstream>
#include "undergraduate.h"

using namespace std;

class UndergraduateManager 
{
private:                                      
	int top; //��¼ָ��
	UnderGraduate undergraduates[100]; //��������¼
public:      
	UndergraduateManager();//���캯��,��Undergraduate.txt����undergraduates[]��  
	int queryByNo(string sno);//���������Ų��� //�ҵ������������±�//û�ҵ�������-1
	void clearStudent();  //ɾ�����б�������Ϣ    
	int addStudent(UnderGraduate s); //��ӱ�����,��Ҫ�Ȳ����Ƿ���� 
	int modifyStudent(string sno);  //�޸�ѧ����Ϣ ,��Ҫ�Ȳ����Ƿ����
	int deleteStudent(string sno);//ɾ����������ɾ��ǰ�Ȳ������Ƿ���� 
	int queryStudent(string sno);//���ұ�����,�鵽����ʾ,������ʾδ�鵽   
	void displayAll();//������б�������Ϣ
	void dataManage(); //��������ά��
	void dataSave();
	void dataRead();    
	~UndergraduateManager();//��������,��undergraduates[]д��Undergraduate.txt�ļ���
};
//���캯��,��Undergraduate.txt����undergraduates[]��    
UndergraduateManager::UndergraduateManager() 
{
	dataRead(); 
} 
//���������Ų���
//�ҵ������������±�
//û�ҵ�������-1 
int UndergraduateManager::queryByNo(string sno)
{
	for(int i=0;i<=top;i++)
		if (undergraduates[i].getStudentNo()==sno)
			return i;
	return -1;    
} 
//ɾ�����б�������Ϣ 
void UndergraduateManager::clearStudent() 
{
	top=-1;
}
//��ӱ�����,��Ҫ�Ȳ����Ƿ����
int UndergraduateManager::addStudent(UnderGraduate s) 
{
	int p=queryByNo(s.getStudentNo());
	if (p==-1)
	{
		top++;
		undergraduates[top]= s;
		dataSave();//����       
		return 1;
	}
	else
	{
		cout<<"--------->��ѧ���Ѿ����� !<----------"<<endl<<endl;
		return 0;
	}
}
//�޸Ŀ�����ɾ��ǰ�Ȳ������Ƿ����
int UndergraduateManager::modifyStudent(string  sno) 
{
	int p=queryByNo(sno);
	if (p==-1)
	{
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else
	{
		cout << "���������������Ϣ: " << endl<<endl;  
		undergraduates[p].inputData();
		dataSave();//���� 
		return 1;
	}    

}
//ɾ����������ɾ��ǰ�Ȳ������Ƿ���� 
int UndergraduateManager::deleteStudent(string sno)
{
	int p=queryByNo(sno);
	if (p==-1)
	{
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else
	{
		for(int i = p; i < top ; i++)
			undergraduates[i]=undergraduates[i+1];
		top--;
		cout << "--------->ɾ�����!<----------" << endl<<endl;
		dataSave();//����       
		return 1;
	}        
}
//���ҿ���
int UndergraduateManager::queryStudent(string sno) 
{
	int p=queryByNo(sno);
	if (p==-1)
	{
		cout<<"--------->��ѧ�������� !<----------"<<endl<<endl;
		return 0;
	}
	else
	{  
		cout<<"--------->��ѧ������:<----------"<<endl<<endl;      
		undergraduates[p].displayDetails();      
		return 1;
	}
}
//������б�������Ϣ
void UndergraduateManager::displayAll() 
{
	for (int i=0;i<=top;i++)
	{  
		cout << "--------��"<< i <<"��ѧ�����----------" << endl<<endl;
		undergraduates[i].displayDetails(); 
	}   
}
//��������,��undergraduates[]д��Undergraduate.txt�ļ���
UndergraduateManager::~UndergraduateManager()
{
	dataSave();
}
void UndergraduateManager::dataManage()
{
	int choice=1;
	string sstudentNo;
	UnderGraduate s;

	while (choice!=0)
	{
		cout << "********************************************" << endl;           
		cout << "\t\t������ά��\n";
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
		switch (choice)
		{
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
void UndergraduateManager::dataSave()//�洢���Ϻ���,��read[]д��Undergraduate.txt�ļ���
{
	fstream file("Undergraduate.txt",ios::out);
	for (int i=0;i<=top;i++)
		file.write((char *)&undergraduates[i],sizeof(undergraduates[i]));
	file.close();
}
void UndergraduateManager::dataRead() //���캯��,��Undergraduate.txt����read[]��
{
	UnderGraduate s;
	top=-1;
	fstream file("Undergraduate.txt",ios::in);
	while (1)
	{
		file.read((char *)&s,sizeof(s));
		if (!file) break;
		top++;
		undergraduates[top]=s;
	}
	file.close();
}
#endif //UNDERGRADUATE_MANAGER_H