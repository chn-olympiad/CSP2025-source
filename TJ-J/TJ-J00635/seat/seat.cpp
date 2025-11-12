#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[105];//排序后的数组
int a1;//小R的分数 (因为数据互不相同，所以只需要存值就行)
int t=1;//数组下标(判断是否为小R的成绩)
bool cmp(int x,int y){//从大到小排序
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);//神秘小代码(记得检查！！！！！！！！)
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	a1=a[1];//记录小R的分数
	sort(a+1,a+n*m+1,cmp);//排序
	for(int j=1;j<=m;j++){//模拟蛇形座位
		if(j%2==1){
			for(int i=1;i<=n;i++){//初始位置在1 j时
				if(a[t]==a1){//如果小R坐在这里
					cout<<j<<" "<<i<<endl;//输出
					return 0;//结束程序
				}
				t++;
			}
		}
		else{
			for(int i=n;i>=1;i--){//初始位置在n j时
				if(a[t]==a1){//如果小R坐在这里
					cout<<j<<" "<<i<<endl;//输出
					return 0;//结束程序
				}
				t++;
			}
		}
	}
	return 0;
}
