/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.19
Description:   Ӧ�ó��������� 
*************************************************/

/*
2018-6-19

��������:

����ֻ������nΪ����(nΪ����ʱ��ѭ�������Ի�����)

�ɽ�����������γɹ��̷�Ϊһ��һ�ֵ�ѭ��
ÿ��ѭ���γ�δ���������������
����k��ѭ���γ���������

�����������з�����֪����ѧ���ɣ�
��nΪż������k=n/2
��nΪ��������k=(n+1)/2
Ϊ����߱���ı�ݣ����ǽ�nΪż��ʱ��k�ֺ�nΪ����ʱ��k-1�ֺϲ���nΪ����ʱ�����ϵ�k��

��ע��Ϊ�˷������ۣ����ɹ����е������±��Ǵӡ�1����ʼ�������ǡ�0����
��k��ʱ��δ�������������ܵ����ɹ������£�
�����Ԫ��Ϊarr[i][j]
i=k         j=k     to  n+1-k
j=n+1-k     i=k+1   to  n+1-k
i=n+1-k     j=n-k   to  k
j=k         i=n-k   to  k+1
*/
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>

void Create(int m){
	//��ʼ������
	int n=0;
	bool IsPositiveNum=false;
	if(m>0){
		IsPositiveNum=true;
		n=m;
	}
	else{
		n=-m;
	}
	//�����ڴ�
	int **arr=(int**)malloc((n+1)*sizeof(int*));
	for(int i=0;i<n+1;i++){
		arr[i]=(int*)malloc((n+1)*sizeof(int));
	}
	//�������
	int k=0;
	bool IsOddNum=false;
	if(n%2==0){
		k=n/2;
	}
	else{
		k=(n-1)/2;
		IsOddNum=true;
	}
	//��������
	int num=0;
	for(int a=1;a<=k;a++){
		for(int b=a;b<=n+1-a;b++){
			arr[a][b]=++num;
		}
		for(int b=a+1;b<=n+1-a;b++){
			arr[b][n+1-a]=++num;
		}
		for(int b=n-a;b>=a;b--){
			arr[n+1-a][b]=++num;
		}
		for(int b=n-a;b>=a+1;b--){
			arr[b][a]=++num;
		}
	}
	if(IsOddNum){
		arr[(n+1)/2][(n+1)/2]=++num;
	}
	//�������
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(IsPositiveNum){
				std::cout<<std::setiosflags(std::ios::left)<<std::setw(6)<<arr[i][j];
			}
			else{
				std::cout<<std::setiosflags(std::ios::left)<<std::setw(6)<<arr[j][i];
			}
		}
		std::cout<<std::endl<<std::endl;
	}
	//�ͷ��ڴ�
	free(arr);
	return;
}

int main(){
	while(true){
		int c=0;
		std::cin>>c;
		std::cout<<std::endl;
		Create(c);
	}
	return 0;
}