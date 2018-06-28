/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.25
Description:   应用程序主函数 
*************************************************/

/*
2018-6-25

哈夫曼编码：

步骤：
1.用给出的数据创建哈夫曼树
2.依据叶子结点到根结点的路径，求出哈夫曼编码

存储方式：
哈夫曼树为正则二叉树，使用存储空间大小确定
使用一次数组存储二叉树

参考：
严蔚敏《数据结构》（c语言版）

*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

#define CODE_NUM    20     //最多字符数

//定义树节点结构体类型
typedef struct node_st{
	int w;
	int parent,left,right;
}NODE;

//定义字符，编码结构体类型
typedef struct char_code_st{
	char ch;
	int weight;
	char *huffmancode;   //指向哈夫曼编码的指针 
}HCODE;

//求哈夫曼编码函数
int CreatHuffmanCode(HCODE node[],int nodenum);

//找权值最小的两棵子树函数
int GetTowNode(NODE huffmantree[],int n,int &s1,int &s2);

int main(){
	//数据
	HCODE data[9]={{},{'a',12},{'b',23},{'c',9},{'d',2},{'e',27},{'f',6},{'g',15},{'h',5}};

	CreatHuffmanCode(data,8);

	return 0;
}

int CreatHuffmanCode(HCODE node[],int nodenum){

	if(nodenum<=1){
		return -1;
	}

	//申请哈夫曼树空间
	//以为哈夫曼树是正则二叉树，所以：结点个数=叶子结点个数*2-1
	int spaceSize=2*nodenum-1;
	NODE* head=(NODE*)malloc((spaceSize+1)*sizeof(NODE));

	//初始化哈夫曼树
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

	//填充哈夫曼树
	int s1=1,s2=1;
	for(int i=nodenum+1;i<=spaceSize;i++){
		//在前i-1个结点中寻找权值最小且parent不为0的两个下标
		GetTowNode(head,i-1,s1,s2);

		head[s1].parent=i;
		head[s2].parent=i;
		head[i].left=s1;
		head[i].right=s2;
		head[i].w=head[s1].w+head[s2].w;
	}

	//输出哈夫曼树
	//for(int i=1;i<=spaceSize;i++){
	//	std::cout<<i<<" "<<head[i].w<<" "<<head[i].parent<<" "<<head[i].left<<" "<<head[i].right<<std::endl;
	//}

	//申请暂时存放倒序哈夫曼编码的空间并初始化
	char* temp=(char*)malloc(sizeof((nodenum+1)*sizeof(char)));
	memset(temp,0,sizeof(temp));

	//求哈夫曼编码
	for(int i=1;i<=nodenum;i++){
		//字符串长度
		int size=0;

		//计算哈夫曼编码
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
		
		//将temp中的倒序编码正序放入huffmancode中
		for(int n=0;n<size;n++){
			node[i].huffmancode[n]=temp[size-n-1];
		}

		//填充字符串结束字符
		node[i].huffmancode[size]='\0';
	}

	//输出哈夫曼编码
	for(int i=1;i<=nodenum;i++){
		std::cout<<"字符："<<std::setw(4)<<std::setiosflags(std::ios::left)<<node[i].ch;
		std::cout<<"权值："<<std::setw(4)<<std::setiosflags(std::ios::left)<<node[i].weight;
		std::cout<<"哈夫曼编码："<<std::setw(nodenum)<<std::setiosflags(std::ios::left)<<node[i].huffmancode<<std::endl;
	}

	//释放哈夫曼树空间
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

