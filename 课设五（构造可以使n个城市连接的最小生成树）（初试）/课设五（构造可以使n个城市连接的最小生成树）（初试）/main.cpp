/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.26
Description:   Ӧ�ó��������� 
*************************************************/

/*
2018-6-26

�������ʹn���������ӵ���С��������

ʹ��Prim�㷨��������С������
ʹ�ö�ά����洢ͼ����Ϣ
��ע�⣺Ϊ�˷�����ȥ�����±�Ϊ0��Ԫ�أ��������±��1��ʼ��

�ο�����������ƿγ���ơ�ָ���飨2018�棩

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define INT_MAX 0x7FFFFFFF

//Prim�㷨 nΪ������ startΪ��ʼ�����ţ���1��ʼ��
int Prim(int** arr,int n,int start){
	std::cout<<"�ӳ���"<<start<<"����"<<std::endl;

	//����ռ�
	int** cost=(int**)malloc((n+1)*sizeof(int*));

	for(int i=0;i<n+1;i++){
		cost[i]=(int*)malloc((n+1)*sizeof(int));
	}

	//���ݶ���
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=arr[i][j];
		}
	}

	//��ʼ��
	bool* IsChoosed=(bool*)malloc((n+1)*sizeof(bool));
	for(int i=1;i<=n;i++){
		IsChoosed[i]=false;
	}
	IsChoosed[start]=true;

	int complete=false;   //��С���Ƿ��������

	int sumCost=0;   //��С�������Ĵ���

	//����
	while(!complete){
		int minCost=INT_MAX;   //��ʼ��

		int record1=0;   //��¼����
		int record2=0;

		//��Ѱ����
		for(int i=1;i<=n;i++){
			if(IsChoosed[i]){
				for(int j=0;j<=n;j++){
					if(!IsChoosed[j]){
						if(cost[i][j]<minCost){
							minCost=cost[i][j];
							record1=i;   //���
							record2=j;   //�յ�
						}
					}
				}
			}
		}

		sumCost+=minCost;

		std::cout<<"����"<<record1<<" �� "<<"����"<<record2<<std::endl;

		//�ı䱻ѡ�񶥵�״̬
		IsChoosed[record2]=true;

		//�����Ƿ�������С������
		complete=true;
		for(int i=1;i<=n;i++){
			if(!IsChoosed[i]){
				complete=false;
				break;
			}
		}
	}

	std::cout<<"��С���������ۣ�"<<sumCost<<std::endl;

	//�ͷſռ�
	free(cost);
	free(IsChoosed);

	return 0;
}

int main(){
	int** arr=(int**)malloc((6+1)*sizeof(int*));
	for(int i=0;i<6+1;i++){
		arr[i]=(int*)malloc((6+1)*sizeof(int));
	}

	//��ʼ��·������
	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			arr[i][j]=INT_MAX;
		}
	}
	arr[1][2]=arr[2][1]=6;
	arr[1][3]=arr[3][1]=1;
	arr[1][4]=arr[4][1]=5;

	arr[2][3]=arr[3][2]=5;
	arr[2][5]=arr[5][2]=3;

	arr[3][4]=arr[4][3]=5;
	arr[3][5]=arr[5][3]=6;
	arr[3][6]=arr[6][3]=4;

	arr[4][6]=arr[6][4]=2;

	arr[5][6]=arr[6][5]=6;

	for(int i=1;i<=6;i++){
		Prim(arr,6,i);
		std::cout<<std::endl;
	}

	free(arr);
	return 0;
}