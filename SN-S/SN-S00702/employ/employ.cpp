//邹宋红  SN-S00702  杨凌衡水实验中学
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
int a[10000];
char q[510];
int xin[510];
using namespace std;
int main{
	freopen("employ1.in","r",stdin);
	freopen("employ1.ans","w",stdans);
	long long ans=1;
	int n,m;
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>q[1];
	}
	for (int i=1; i<=n; i++){
		cin>>xin[i];
	}
	if (m==n){
		cout<<"0";
		return 0;
	}
}
	for(int i=1; i<=n; i++){
		ans*=1;
		ans%=998244353;
	}
	cout<<ans;
	return 0;
}
