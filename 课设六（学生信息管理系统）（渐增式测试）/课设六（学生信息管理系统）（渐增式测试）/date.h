/*************************************************
Copyright (C), 2018, Tyut
File name:     date.h
Author: gaobaolu      Version: 1.0     Date: 2010.6.28
Author: fengjiawei    Version: 1.1     Date: 2018.6.28
Description:   日期类 
*************************************************/
#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
private:
	int year;
	int month;
	int day;
public:
	Date(){
		year=0;
		month=0;
		day=0;
	}

	Date(int yy,int mm,int dd){
		year=yy;
		month=mm;
		day=dd;
	}

	Date(Date& d){
		year=d.year;
		month=d.month;
		day=d.day;
	}

	~Date(){}

	void setYear(int yy){
		year=yy;
	}

	void setMonth(int mm){
		month=mm;
	}

	void setDay(int dd){
		day=dd;
	}

	int getYear(){
		return year;
	}

	int getMonth(){
		return month;
	}

	int detDay(){
		return day;
	}

	void inputData(){
		cout<<"年：";
		cin>>year;
		cout<<"月：";
		cin>>month;
		cout<<"日：";
		cin>>day;
	}

	void displayDetails(){
		cout<<year<<"/"<<month<<"/"<<day<<endl;
	}
};


#endif