/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   应用程序主函数 
*************************************************/

/*

2018-6-28

学生信息管理系统：

在高老师的代码基础完善一些类
解决了strcpy()函数警告问题
若使用清屏system("cls")，运行界面会更清晰

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
	cout<<"*|*|              欢迎您使用学生管理系统            |*|*"<<endl;
	cout<<"*|*|                                                |*|*"<<endl;    
	cout<<"********************************************************"<<endl;
	do{
		cout << "<---------------------------------------------------->" << endl;                                                                  
		cout << " \n \t\t 1:本科生管理 ";
		cout << " \n \t\t 2:研究生管理  ";
		cout << " \n \t\t 3.助教博士生管理 "; 
		cout << " \n \t\t 0:离开    "; 
		cout << endl;        
		cout << "<---------------------------------------------------->" << endl; 
		cout << "请选择：" << endl;
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
	cout<<"*|*|               感谢使用学生管理系统                  |*|*"<<endl;
	cout<<" **********************************************************\a"<<endl;

	return 0;
}