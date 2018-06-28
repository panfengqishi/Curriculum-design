/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.20
Description:   应用程序主函数 
*************************************************/

/*
2018-6-20

消除类游戏：

分析：
1.将元素解析为一个结构体
struct Element{
	int data;
	bool IsEliminate;
};
data:存放颜色编号
IsEliminate:存放判断此元素消除的信息

2.遍历元素，寻找需要消除的元素，
并将元素的IsEliminate设为true

思考：若消除矩阵为高阶矩阵时，在消除时可用跳跃消除代替逐步消除，提高消除效率

*/

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

struct Element{
	int data;
	bool IsEliminate;
};

//创建数组并消除
void CreateEliminateArr(int n,int m){
	//申请内存
	Element **arr=(Element**)malloc((n+1)*sizeof(Element*));
	for(int i=0;i<n+1;i++){
		arr[i]=(Element*)malloc((m+1)*sizeof(Element));
	}
	//读取并初始化数据
	for(int i=1;i<=n;i++){
		for(int j=1;j<m+1;j++){
			std::cin>>arr[i][j].data;
			arr[i][j].IsEliminate=false;
		}
	}
	//获取需要消除的元素
	if(m>=3){
		//消除行中相同的元素
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
		//消除列中相同的元素
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
	//执行消除操作并输出矩阵
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
	//释放内存
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