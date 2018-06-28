/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.25
Description:   Ӧ�ó��������� 
*************************************************/

/*
2018-6-25

���������룺

���裺
1.�ø��������ݴ�����������
2.����Ҷ�ӽ�㵽������·�����������������

�洢��ʽ��
��������Ϊ�����������ʹ�ô洢�ռ��Сȷ��
ʹ��һ������洢������

�ο���
��ε�������ݽṹ����c���԰棩

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define CODE_NUM    20     //����ַ���

//�������ڵ�ṹ������
typedef struct node_st{
	int w;
	int parent,left,right;
}NODE;

//�����ַ�������ṹ������
typedef struct char_code_st{
	char ch;
	int weight;
	char *huffmancode;   //ָ������������ָ�� 
}HCODE;

//����������뺯��
int CreatHuffmanCode(HCODE node[],int nodenum);

//��Ȩֵ��С��������������
int GetTowNode(NODE huffmantree[],int n,int &s1,int &s2);

int main(){
	//����
	HCODE data[9]={{},{'a',12},{'b',23},{'c',9},{'d',2},{'e',27},{'f',6},{'g',15},{'h',5}};

	CreatHuffmanCode(data,8);

	return 0;
}

int CreatHuffmanCode(HCODE node[],int nodenum){

	if(nodenum<=1){
		return -1;
	}

	//������������ռ�
	//��Ϊ������������������������ԣ�������=Ҷ�ӽ�����*2-1
	int spaceSize=2*nodenum-1;
	NODE* head=(NODE*)malloc((spaceSize+1)*sizeof(NODE));

	//��ʼ����������
	for(int i=1;i<=nodenum;i++){
		head[i].w=node[i].weight;
		head[i].parent=0;
		head[i].left=0;
		head[i].right=0;
	}
	for(int i=nodenum+1;i<=spaceSize;i++){
		head[i].w=0;
		head[i].parent=0;
		head[i].left=0;
		head[i].right=0;
	}

	//����������
	int s1=1,s2=1;
	for(int i=nodenum+1;i<=spaceSize;i++){
		//��ǰi-1�������Ѱ��Ȩֵ��С��parent��Ϊ0�������±�
		GetTowNode(head,i-1,s1,s2);

		head[s1].parent=i;
		head[s2].parent=i;
		head[i].left=s1;
		head[i].right=s2;
		head[i].w=head[s1].w+head[s2].w;
	}

	//�����������
	//for(int i=1;i<=spaceSize;i++){
	//	std::cout<<i<<" "<<head[i].w<<" "<<head[i].parent<<" "<<head[i].left<<" "<<head[i].right<<std::endl;
	//}

	//������ʱ��ŵ������������Ŀռ䲢��ʼ��
	char* temp=(char*)malloc(sizeof((nodenum+1)*sizeof(char)));
	memset(temp,0,sizeof(temp));

	//�����������
	for(int i=1;i<=nodenum;i++){
		//�ַ�������
		int size=0;

		//�������������
		for(int j=i,parent=head[i].parent;
			parent!=0;
			j=parent,parent=head[parent].parent){
				if(head[parent].left==j){
					temp[size++]='0';
				}
				else{
					temp[size++]='1';
				}
		}

		node[i].huffmancode=(char*)malloc((size+1)*sizeof(char));
		
		//��temp�еĵ�������������huffmancode��
		for(int n=0;n<size;n++){
			node[i].huffmancode[n]=temp[size-n-1];
		}

		//����ַ��������ַ�
		node[i].huffmancode[size]='\0';
	}

	//�������������
	for(int i=1;i<=nodenum;i++){
		std::cout<<"�ַ���"<<std::setw(4)<<std::setiosflags(std::ios::left)<<node[i].ch;
		std::cout<<"Ȩֵ��"<<std::setw(4)<<std::setiosflags(std::ios::left)<<node[i].weight;
		std::cout<<"���������룺"<<std::setw(nodenum)<<std::setiosflags(std::ios::left)<<node[i].huffmancode<<std::endl;
	}

	//�ͷŹ��������ռ�
	free(head);

	return 0;
}

int GetTowNode(NODE huffmantree[],int n,int &s1,int &s2){
	for(int i=1;i<=n;i++){
		if(huffmantree[i].parent==0){
			s1=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((huffmantree[i].parent==0)&&(i!=s1)){
			s2=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if((huffmantree[i].parent==0)&&(huffmantree[s1].w>huffmantree[i].w)){
			s1=i;
		}
	}
	for(int i=1;i<=n;i++){
		if((huffmantree[i].parent==0)&&(huffmantree[s2].w>huffmantree[i].w)&&(i!=s1)){
			s2=i;
		}
	}
	return 0;
}

