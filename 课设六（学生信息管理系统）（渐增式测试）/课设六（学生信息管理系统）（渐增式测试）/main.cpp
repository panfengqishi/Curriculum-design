/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   Ӧ�ó��������� 
*************************************************/

/*

2018-6-28

ѧ����Ϣ����ϵͳ��

�ڸ���ʦ�Ĵ����������һЩ��
�����strcpy()������������
��ʹ������system("cls")�����н���������

*/
#include <stdio.h>
#include <iostream>
#include "date.h"
#include "person.h"
#include "teacher.h"
#include "undergraduate.h"
#include "graduate.h"
#include "ta.h"
#include "undergraduateManager.h"
#include "graduateManager.h"
#include "taManager.h"

using namespace std;

int main(){
	int choiceN;
	UndergraduateManager unMan;
	GraduateManager grMan;
	TaManager taMan;
	cout<<"********************************************************"<<endl;
	cout<<"*|*|                                                |*|*"<<endl;    
	cout<<"*|*|              ��ӭ��ʹ��ѧ������ϵͳ            |*|*"<<endl;
	cout<<"*|*|                                                |*|*"<<endl;    
	cout<<"********************************************************"<<endl;
	do{
		cout << "<---------------------------------------------------->" << endl;                                                                  
		cout << " \n \t\t 1:���������� ";
		cout << " \n \t\t 2:�о�������  ";
		cout << " \n \t\t 3.���̲�ʿ������ "; 
		cout << " \n \t\t 0:�뿪    "; 
		cout << endl;        
		cout << "<---------------------------------------------------->" << endl; 
		cout << "��ѡ��" << endl;
		cin >> choiceN;
		switch(choiceN)
		{
		case 1:
			unMan.dataManage();
			break;
		case 2:
			grMan.dataManage();
			break;
		case 3:
			taMan.dataManage();
			break;
		default:
			break;
		}
	}while(choiceN!=0);
	cout<<" **********************************************************"<<endl;
	cout<<"*|*|               ��лʹ��ѧ������ϵͳ                  |*|*"<<endl;
	cout<<" **********************************************************\a"<<endl;

	return 0;
}