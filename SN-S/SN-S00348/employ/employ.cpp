//还剩一个小时整，看一眼T4吧 
//woc刚刚膝盖顶到关机键了幸好手快把关机取消了
//不然E盘以外的东西都得重新配
//现在把应用重新开一下就行
//    :)   还好，还好。
//xt66666 
//CCF give me 149pts please !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
//特殊性质A：至少有m个位置，i<=c[i] 
//一点信心都没有的人tmd报什么面试啊！！！！！影响我n!偏分 
ll n,m,c[510];
ll mod=998244353;
bool f[510];
ll pai[510];
bool v[510];
ll ans=0;
void dfs(ll x)
{
	if(x==n+1)
	{
		ll now=0,ret=0;
		for(int i=1;i<=n;i++)
		{
			if(now>=c[pai[i]])
			{
				now++;
				continue;
			}
			if(!f[i])
			{
				now++;
				continue;
			}
			ret++;
		}
		if(ret>=m)
		{
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i])
		{
			continue;
		}
		v[i]=1;
		pai[x]=i;
		dfs(x+1);
		v[i]=0;
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		char x;
		cin>>x;
		if(x=='1')
		{
			f[i]=1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	if(n<=10)
	{
		dfs(1);
		cout<<ans;
		return 0;
	}
	
	return 0;
}

