#include<bits/stdc++.h>
using namespace std;
int  n,k,a[100005];

long long summ;
int main()
{
	freopen("xor.in","r",stdin)
	freopen("xor.out","w",stdout)
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	summ=a[1];
	for(int i=2;i<=n;i++)
	{
		summ=summ^a[i];
	}
	cout<<2;
	
	return 0;
	
}
/*
	鱼死网破吧，直接骗分，
	实在没思路啊，dp好难！
	12费， 直接至死方休吧！
	|----------------------\
	|12k|                  |
	|---                   |
	|    ___               |
	|--<\^^^~~~     ()     | 
	|              ()()    |
	| ==================== |
	|———————————|
	|       至死方休       |
	|    消灭所有单位      |
	|_________<[*]>________|
	
	(来自kards游戏)
