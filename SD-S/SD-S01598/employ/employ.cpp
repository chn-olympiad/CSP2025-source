/*
Solution:
发现n<10可以暴力全排列
特殊性质A代表所有人都能过
答案就是随便排 
有没有非指数做法
对于特殊性质B
能录取的人不超过18个
用前缀和求出对于每个能录取的位置，前面有多少人不会被录取
正序寻找对于每个si=1的i，放上>前面不会被录取人数且最小的ci
放到放不下就是答案 
怎么求(a!)%mod 
龟速乘 

我去全假了
只考虑性质AB吧 
只考虑n<10吧 
 
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
怎么不对 破防了 
*/
#include <bits/stdc++.h>
using namespace std;
const int N=514,mod=998244353;
int n,m,cnt;
string s;
int c[N];//i-sumi就是第i+1个位置前面不会被录取的人数 
bool vis[N];
long long ans=0;
int dfs(long long x)
{
	if(x>=pow(10,n-1))
	{
		cnt++;
		int res=0;
		for(int i=1;i<=n;i++)
		{
			int num=(x/(int)pow(10,(i-1)))%10;//该排列第i-1位 
//			cout<<num<<" ";
			if(c[num]>i-1-res&&s[i]=='1') res++;
		}
//		cout<<"*"<<res<<'\n';
		return res>=m;
	} 
    int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
			ans+=dfs(x*10+i);
			ans%=mod;
			vis[i]=0;
		}
	}
	return ans;
}
signed main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;s=' '+s;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
    }
    if(n<=12)
	{
		cout<<dfs(1ll*0);
		return 0;
	}
	cout<<0;
//	cout<<'\n'<<cnt;
	return 0;
}
