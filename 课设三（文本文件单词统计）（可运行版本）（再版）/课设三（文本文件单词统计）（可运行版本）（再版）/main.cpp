/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.21
Description:   Ӧ�ó��������� 
*************************************************/

/*
2018-6-21

�ı��ļ�����ͳ�ƣ�

����ʱ���ϵ������ʵ�ֲ�û���ϸ����ָ����

�����߼���

1 ɨ���ı��ļ������ı��ļ��еĵ������η���˳�����
2 ��˳����еĵ��ʰ����ֵ�˳������
3 ȥ���ظ����ֵĵ��ʲ�����

ȱ�㣺��֧��ʵʱ�ı��޸�

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>

//˳����ʼ��������
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

//˳���Ԫ��
struct Word{
	char arr[21];
	int count;
};

//˳��������Ϣ
struct SqList{
	Word *base;
	int length;
	int listSize;
};

//��ʼ��˳���
int InitList(SqList &L);

//���Ԫ�ص�˳���
int InsertList(SqList &L,Word word);

//ɨ������
int Scanning(SqList &L,char *txt);

//˳����ֵ�˳������
int Sort(SqList &L);

//�ַ�������Ƚ�
int Strcmp(char* str1,char* str2);

//����˳���ָ����ʽ
int HandleList(SqList &L);

//ɾ��˳���Ԫ��(iΪ�±�)
int DeleteList(SqList &L,int i);

//���˳���
int PrintList(SqList L);

//�����ʳ��ִ�����
bool compare(Word word1,Word word2);

int main(){
	//����˳���ͷ
	SqList L;

	//�����ļ�·��
	char txt[]="tyut.txt";
	//char txt[]="article_2.txt";

	//ɨ������
	Scanning(L,txt);

	//��ɨ�����õ�˳����ֵ�˳������
	Sort(L);

	//�����ظ��ĵ��ʲ�����
	HandleList(L);

	//���˳����е�����
	PrintList(L);

	//�����ʳ��ִ�����
	//std::sort(L.base,L.base+L.length,compare);
	//PrintList(L);

	//�ͷ�
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
		//����˳�������
		Word* temp;
		temp=(Word*)realloc(L.base,(L.listSize+LISTINCREMENT)*sizeof(Word));
		if(!temp){
			exit(1);
		}
		L.base=temp;
		L.listSize+=LISTINCREMENT;
	}
	L.base[L.length]=word;
	//��ʼ��������
	L.base[L.length++].count=1;
	return 0;
}

int Scanning(SqList &L,char *txt){
	//�������ļ���
	std::ifstream scan(txt);

	//��ʼ��˳���
	InitList(L);

	char ch=' ';

	//����һ�����ʿ�
	Word wordBasket;

	//�������ʿ��е��±�����
	int index=0;

	//sign������ʶ��һ���ַ��Ƿ�Ϊ����ĸ��
	//��һ���ַ�Ϊ��ĸ��sign=true������Ϊ��ĸ��sign=false��
	bool sign=false;

	//ѭ���ļ�����ȡ����
	while(!scan.eof()){
		//���������ж�ȡһ���ַ�
		scan.read((char*)&ch,1);

		//�ж϶������ַ��Ƿ�Ϊ��ĸ
		if(((65<=ch)&&(ch<=90))||((97<=ch)&&(ch<=122))){

			//Ϊ�˷��㴦��ͳһת��ΪСд��ĸ
			if((65<=ch)&&(ch<=90)){
				ch+=32;
			}

			if(!sign){

				//����һ���ַ�������ĸ
				//��յ��ʿ�����������������һ���ַ�װ�뵥�ʿ�
				memset(&wordBasket,0,sizeof(Word));
				index=0;
				wordBasket.arr[index++]=ch;

				//�ı���
				sign=true;
			}
			else{
				//��һ���ַ�Ҳ����ĸ����������ַ�װ�뵥�ʿ�
				wordBasket.arr[index++]=ch;
			}
		}
		else{
			if(sign){
				//�õ�һ���µ���
				InsertList(L,wordBasket);
			}

			//�ı���
			sign=false;
		}
	}

	//�淶����
	for(int i=20;i>0;i--){
		if(wordBasket.arr[i]!=0){
			wordBasket.arr[i]=0;
			break;
		}
	}

	//�ر��ļ���
	scan.close();

	//�����һ�����ʷ���˳���
	InsertList(L,wordBasket);

	return 0;
}

int Sort(SqList &L){

	//Ϊ�˼�ʹ��ð�����򣨿��Գ��Կ��ţ�
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

		//�������ַ���ͬʱ����
		if(*str1=='\0'){
			return 0;
		}

		//ָ������
		str1++;
		str2++;
	}

	return *str1-*str2;
}

int HandleList(SqList &L){
	//ɾ������ʹ�±�����ݷ���ӳ��仯��Ҫע��ѭ���в����Ŀ���
	for(int i=0;i<L.length-1;i++){
		while((i<L.length-1)&&(Strcmp(L.base[i].arr,L.base[i+1].arr)==0)){
			DeleteList(L,i+1);
			L.base[i].count++;
		}
	}
	return 0;
}

int DeleteList(SqList &L,int i){
	//ע�⣺�����i��ʾ˳�����±�
	//����������ݽṹ�̿����е�ָ�����
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
		std::cout<<"����:"<<std::setw(20)<<std::setiosflags(std::ios::left)<<L.base[i].arr;
		std::cout<<"���ִ���:"<<std::setw(4)<<std::setiosflags(std::ios::left)<<L.base[i].count<<std::endl;
	}
	return 0;
}
