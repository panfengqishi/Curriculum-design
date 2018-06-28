/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.21
Description:   应用程序主函数 
*************************************************/

/*
2018-6-21

文本文件单词统计；

由于时间关系，代码实现并没有严格参照指导书

处理逻辑：

1 扫描文本文件，将文本文件中的单词依次放入顺序表中
2 将顺序表中的单词按照字典顺序排序
3 去掉重复出现的单词并计数

缺点：不支持实时的表修改

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

//顺序表初始量和增量
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

//顺序表元素
struct Word{
	char arr[21];
	int count;
};

//顺序表基本信息
struct SqList{
	Word *base;
	int length;
	int listSize;
};

//初始化顺序表
int InitList(SqList &L);

//添加元素到顺序表
int InsertList(SqList &L,Word word);

//扫描文章
int Scanning(SqList &L,char *txt);

//顺序表按字典顺序排序
int Sort(SqList &L);

//字符串数组比较
int Strcmp(char* str1,char* str2);

//处理顺序表到指定格式
int HandleList(SqList &L);

//删除顺序表元素(i为下标)
int DeleteList(SqList &L,int i);

//输出顺序表
int PrintList(SqList L);

//按单词出现次排序
bool compare(Word word1,Word word2);

int main(){
	//创建顺序表头
	SqList L;

	//设置文件路径
	char txt[]="tyut.txt";
	//char txt[]="article_2.txt";

	//扫描文章
	Scanning(L,txt);

	//将扫描后填好的顺序表按字典顺序排序
	Sort(L);

	//处理重复的单词并计数
	HandleList(L);

	//输出顺序表中的内容
	PrintList(L);

	//按单词出现次排序
	//std::sort(L.base,L.base+L.length,compare);
	//PrintList(L);

	//释放
	free(L.base);

	return 0;
}

int InitList(SqList &L){
	L.base=(Word*)malloc(LIST_INIT_SIZE*sizeof(Word));
	if(!L.base){
		exit(1);
	}
	L.length=0;
	L.listSize=LIST_INIT_SIZE;
	return 0;
}

int InsertList(SqList &L,Word word){
	if(L.length>=L.listSize){
		//增加顺序表容量
		Word* temp;
		temp=(Word*)realloc(L.base,(L.listSize+LISTINCREMENT)*sizeof(Word));
		if(!temp){
			exit(1);
		}
		L.base=temp;
		L.listSize+=LISTINCREMENT;
	}
	L.base[L.length]=word;
	//初始化计算器
	L.base[L.length++].count=1;
	return 0;
}

int Scanning(SqList &L,char *txt){
	//打开输入文件流
	std::ifstream scan(txt);

	//初始化顺序表
	InitList(L);

	char ch=' ';

	//声明一个单词筐
	Word wordBasket;

	//声明单词筐中的下标索引
	int index=0;

	//sign用来标识上一个字符是否为（字母）
	//上一个字符为字母（sign=true），不为字母（sign=false）
	bool sign=false;

	//循环文件流读取文章
	while(!scan.eof()){
		//从输入流中读取一个字符
		scan.read((char*)&ch,1);

		//判断读出的字符是否为字母
		if(((65<=ch)&&(ch<=90))||((97<=ch)&&(ch<=122))){

			//为了方便处理，统一转换为小写字母
			if((65<=ch)&&(ch<=90)){
				ch+=32;
			}

			if(!sign){

				//若上一个字符不是字母
				//清空单词筐重置索引，并将第一个字符装入单词筐
				memset(&wordBasket,0,sizeof(Word));
				index=0;
				wordBasket.arr[index++]=ch;

				//改变标记
				sign=true;
			}
			else{
				//上一个字符也是字母，则继续将字符装入单词筐
				wordBasket.arr[index++]=ch;
			}
		}
		else{
			if(sign){
				//得到一个新单词
				InsertList(L,wordBasket);
			}

			//改变标记
			sign=false;
		}
	}

	//规范处理
	for(int i=20;i>0;i--){
		if(wordBasket.arr[i]!=0){
			wordBasket.arr[i]=0;
			break;
		}
	}

	//关闭文件流
	scan.close();

	//将最后一个单词放入顺序表
	InsertList(L,wordBasket);

	return 0;
}

int Sort(SqList &L){

	//为了简单使用冒泡排序（可以尝试快排）
	for(int i=0;i<L.length;i++){
		for(int j=0;j<L.length-1;j++){
			if(Strcmp(L.base[j].arr,L.base[j+1].arr)>0){
				Word word;
				word=L.base[j];
				L.base[j]=L.base[j+1];
				L.base[j+1]=word;
			}
		}
	}

	return 0;
}

int Strcmp(char* str1,char* str2){

	while(*str1==*str2){

		//当两个字符串同时结束
		if(*str1=='\0'){
			return 0;
		}

		//指针下移
		str1++;
		str2++;
	}

	return *str1-*str2;
}

int HandleList(SqList &L){
	//删除操作使下标和数据发生映射变化，要注意循环中参数的控制
	for(int i=0;i<L.length-1;i++){
		while((i<L.length-1)&&(Strcmp(L.base[i].arr,L.base[i+1].arr)==0)){
			DeleteList(L,i+1);
			L.base[i].count++;
		}
	}
	return 0;
}

int DeleteList(SqList &L,int i){
	//注意：这里的i表示顺序表的下标
	//这里采用数据结构教科书中的指针操作
	Word* deleteWord=&(L.base[i]);
	Word* tail=L.base+L.length-1;
	for(++deleteWord;deleteWord<=tail;++deleteWord){
		*(deleteWord-1)=*deleteWord;
	}

	--L.length;
	return 0;
}

int PrintList(SqList L){
	for(int i=0;i<L.length;i++){
		std::cout<<"单词:"<<std::setw(20)<<std::setiosflags(std::ios::left)<<L.base[i].arr;
		std::cout<<"出现次数:"<<std::setw(4)<<std::setiosflags(std::ios::left)<<L.base[i].count<<std::endl;
	}
	return 0;
}
