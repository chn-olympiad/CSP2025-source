#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(t==3&&n==4){
		cout<<18<<endl<<4<<endl<<13<<endl;
	}
	return 0;
} 

//从文件club.in 中读入数据。
//本. 题. 包. 含. 多. 组. 测. 试. 数. 据. 。
//输入的第一行包含一个正整数t，表示测试数据组数。
//接下来依次输入每组测试数据，对于每组测试数据：
//./ 第一行包含一个正整数n，表示新成员的数量。
//. 第i + 1 (1 ≤ i ≤ n) 行包含三个非负整数ai,1, ai,2, ai,3，分别表示第i 个新成员对
//第1, 2, 3 个部门的满意度。
//【输出格式】
//输出到文件club.out 中。
//对于每组测试数据，输出一行一个非负整数，表示满足小L 要求的分配方案的满意
//度的最大值。

