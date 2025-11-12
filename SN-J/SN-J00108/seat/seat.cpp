#include <bits/stdc++.h>//执行定义头文件的库的操作 
using namespace std;//执行定义命名空间操作 
bool cmp(int a,int b){//定义布尔值变量cmp，确定地址，对应下面的sort排序操作 
	if(a!=b)return a<b; //compare（cmp函数，与下方的是同样的意思）函数排序比大小，返回a<b的对应值，保证cmp可以在排序时中和排序的地址的值 
	else return a<b; //compare函数排序比大小，返回a>b的对应值，保证cmp可以在排序时中和排序的地址的值 
}
int main(){//执行定义主函数的操作 
	freopen("seat.in".r,seat.cpp);//执行读入文件操作 
	freopen("seat.out".w,seat.cpp);//执行输出文件操作 
	int n,m;//执行定义整型数组变量的项n和m的操作 
	cin>>n>>m>>endl;//执行输入n和m（座位行和列）的操作 
	int a[n][m];////定义二维数组（表示座位的行数与列数）数组本身，使其中的项的值为n和m 
	long long score;//定义名为score的变量，表示CSP-J第一轮各考生的成绩 
	for(int i=1;i<=a.size();i++){//开始循环（循环输入考生成绩），其中起点为1，终点为a的长度，相当于从1跑到a的任意位置 
		cin>>a[i];//循环输入a的各项（其他选手的成绩） 
	}
	sort(a+1,a+n+1,cmp);//执行成绩高低的排序操作，用cmp函数确定各个项之间的地址 
	int R_score;//执行定义代表小R同学的成绩的整型变量的操作 
	for(int i=1;i<=a.size();i++){//用循环打擂台（比较各个项的大小的方法，可以两两一比较，从而确定大小以及排序）的方式，比较小R同学的成绩与其他选手的成绩的大小关系 
		if(R_score<=a[i]){//比较小R同学的成绩，如果比其他选手成绩低，执行循环嵌套，继续比大小 
			if(R_score>=a[i]){//对应上一层代码，如果小R同学的成绩比其他选手高，则进行内部操作 （输出小R同学的座位编号） 
				cout<<a[n][m];//循环内部操作，输出小R同学按照题目中给出的方式应坐的座位的编号（使用二维数组a中的n和m的变量输出座位编号） 
			}
		}
	}
	return 0;//返回值为0 
}
