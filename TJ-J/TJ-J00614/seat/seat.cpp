#include<bits/stdc++.h>
using namespace std;
/*
思路：
先把每个人分数排序
再分配座位
并寻找小R的分数
输出坐标 
*/ 
bool cmp(int x,int y) { //从大到小
	return x>y;
}
long long arr[100]= {}; //每一个数
long long a[10][10]= {}; //座位
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	long long n;
	cin>>n;
	long long m;
	cin>>m;
	long long k=n*m;//最后一个数
	for(int i=1; i<=k; i++) {
		cin>>arr[i];
	}
	long long j=arr[1];//自己分数
	long long q=1;//arr下标
	sort(arr+1,arr+k+1,cmp);//排序
	long long x=1,y=1;//坐标
	while(q<=k && y<=m) {
		a[x][y]==arr[q];//对应座位
		if(arr[q]==j) {
			cout<<y<<" "<<x;//输出下标
			break;//终止
		}
		if(y%2==1) { //奇数列时是从小到大
			x++;
			if(x>n) { //如果超出，下一列
				x=n;
				y++;
			}
		} else if(y%2==0) { //偶数列时是从大到小
			x--;
			if(x<1) { //和第30行同理
				x=1;
				y++;
			}
		}
		q++;
	}
	return 0;
}
