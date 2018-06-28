/*************************************************
Copyright (C), 2018, Tyut
File name:     main.cpp
Author: fengjiawei    Version: 1.0     Date: 2018.6.19
Description:   应用程序主函数 
*************************************************/

/*
2018-6-19

螺旋矩阵:

我们只分析当n为正数(n为负数时将循环变量对换即可)

可将螺旋矩阵的形成过程分为一轮一轮的循环
每轮循环形成未填充矩阵区域的四周
设有k轮循环形成螺旋矩阵

从螺旋矩阵中分析可知其数学规律：
若n为偶数，则k=n/2
若n为奇数，则k=(n+1)/2
为了提高编码的便捷，我们将n为偶数时的k轮和n为奇数时的k-1轮合并，n为奇数时最后加上第k轮

（注：为了方便讨论，生成规则中的数组下标是从【1】开始，而不是【0】）
第k轮时，未填充矩阵区域四周的生成规则如下：
设矩阵元素为arr[i][j]
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
	//初始化处理
	int n=0;
	bool IsPositiveNum=false;
	if(m>0){
		IsPositiveNum=true;
		n=m;
	}
	else{
		n=-m;
	}
	//申请内存
	int **arr=(int**)malloc((n+1)*sizeof(int*));
	for(int i=0;i<n+1;i++){
		arr[i]=(int*)malloc((n+1)*sizeof(int));
	}
	//计算参数
	int k=0;
	bool IsOddNum=false;
	if(n%2==0){
		k=n/2;
	}
	else{
		k=(n-1)/2;
		IsOddNum=true;
	}
	//生成数据
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
	//输出数据
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
	//释放内存
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