/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.20
Description:   Ӧ�ó��������� 
*************************************************/

/*
2018-6-20

��������Ϸ��

������
1.��Ԫ�ؽ���Ϊһ���ṹ��
struct Element{
	int data;
	bool IsEliminate;
};
data:�����ɫ���
IsEliminate:����жϴ�Ԫ����������Ϣ

2.����Ԫ�أ�Ѱ����Ҫ������Ԫ�أ�
����Ԫ�ص�IsEliminate��Ϊtrue

˼��������������Ϊ�߽׾���ʱ��������ʱ������Ծ�����������������������Ч��

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Element{
	int data;
	bool IsEliminate;
};

//�������鲢����
void CreateEliminateArr(int n,int m){
	//�����ڴ�
	Element **arr=(Element**)malloc((n+1)*sizeof(Element*));
	for(int i=0;i<n+1;i++){
		arr[i]=(Element*)malloc((m+1)*sizeof(Element));
	}
	//��ȡ����ʼ������
	for(int i=1;i<=n;i++){
		for(int j=1;j<m+1;j++){
			std::cin>>arr[i][j].data;
			arr[i][j].IsEliminate=false;
		}
	}
	//��ȡ��Ҫ������Ԫ��
	if(m>=3){
		//����������ͬ��Ԫ��
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m-2;j++){
				if((arr[i][j].data==arr[i][j+1].data)&&(arr[i][j].data==arr[i][j+2].data)){
					arr[i][j].IsEliminate=true;
					arr[i][j+1].IsEliminate=true;
					arr[i][j+2].IsEliminate=true;
				}
			}
		}

	}
	if(n>=3){
		//����������ͬ��Ԫ��
		for(int j=1;j<=m;j++){
			for(int i=1;i<=n-2;i++){
				if((arr[i][j].data==arr[i+1][j].data)&&(arr[i][j].data==arr[i+2][j].data)){
					arr[i][j].IsEliminate=true;
					arr[i+1][j].IsEliminate=true;
					arr[i+2][j].IsEliminate=true;
				}
			}
		}
	}
	//ִ�������������������
	std::cout<<std::endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(arr[i][j].IsEliminate){
				arr[i][j].data=0;
			}
			std::cout<<arr[i][j].data<<" ";
		}
		std::cout<<std::endl;
	}
	//�ͷ��ڴ�
	free(arr);
	return;
}

int main(){
	while(true){
		int a=0,b=0;
		std::cin>>a>>b;
		CreateEliminateArr(a,b);
	}
	return 0;
}