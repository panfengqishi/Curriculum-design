/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.26
Description:   应用程序主函数 
*************************************************/

/*
2018-6-26

构造可以使n给城市连接的最小生成树：

使用Prim算法，计算最小生成树
使用二维数组存储图的信息
（注意：为了方便舍去数组下标为0的元素，即数组下标从1开始）

参考：《程序设计课程设计》指导书（2018版）

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define INT_MAX 0x7FFFFFFF

//Prim算法 n为顶点数 start为初始顶点编号（从1开始）
int Prim(int** arr,int n,int start){
	std::cout<<"从城市"<<start<<"出发"<<std::endl;

	//申请空间
	int** cost=(int**)malloc((n+1)*sizeof(int*));

	for(int i=0;i<n+1;i++){
		cost[i]=(int*)malloc((n+1)*sizeof(int));
	}

	//数据读入
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=arr[i][j];
		}
	}

	//初始化
	bool* IsChoosed=(bool*)malloc((n+1)*sizeof(bool));
	for(int i=1;i<=n;i++){
		IsChoosed[i]=false;
	}
	IsChoosed[start]=true;

	int complete=false;   //最小树是否生成完成

	int sumCost=0;   //最小生成树的代价

	//构造
	while(!complete){
		int minCost=INT_MAX;   //初始化

		int record1=0;   //记录顶点
		int record2=0;

		//搜寻顶点
		for(int i=1;i<=n;i++){
			if(IsChoosed[i]){
				for(int j=0;j<=n;j++){
					if(!IsChoosed[j]){
						if(cost[i][j]<minCost){
							minCost=cost[i][j];
							record1=i;   //起点
							record2=j;   //终点
						}
					}
				}
			}
		}

		sumCost+=minCost;

		std::cout<<"城市"<<record1<<" 到 "<<"城市"<<record2<<std::endl;

		//改变被选择顶点状态
		IsChoosed[record2]=true;

		//计算是否生成最小生成树
		complete=true;
		for(int i=1;i<=n;i++){
			if(!IsChoosed[i]){
				complete=false;
				break;
			}
		}
	}

	std::cout<<"最小生成树代价："<<sumCost<<std::endl;

	//释放空间
	free(cost);
	free(IsChoosed);

	return 0;
}

int main(){
	int** arr=(int**)malloc((6+1)*sizeof(int*));
	for(int i=0;i<6+1;i++){
		arr[i]=(int*)malloc((6+1)*sizeof(int));
	}

	//初始化路径代价
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