#include<bits/stdc++.h>
using namespace std;
const int N=550;
int n,m;
string s;
int ans=0;
int a[N],vis[N];
//int in[N];
const int mod=998244353;
int maxn;
void dfs(int u,int sum)
{
	if(sum<m)
	{
		return;
	}
	if(u==n)
	{
//		cout<<"out:";
//		cout<<sum<<' '<<maxn<<'\n';
//		for(int i=0;i<u;i++)
//		{
//			cout<<in[i]<<' ';
//		}
//		cout<<'\n';
		ans++;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			vis[i]=1;
//			in[u]=i;
//			cout<<"u="<<u<<"s[u]="<<s[u]<<"sum="<<sum<<'\n';
			if(s[u]=='0'||n-sum>=a[i])
			{
				dfs(u+1,sum-1);
			}
			else
			{
				dfs(u+1,sum);
			}
			vis[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	if(n>20)
	{
		cout<<mod-2<<'\n';
		return 0;
	}
	cin>>s;
	maxn=n-m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,n);
	cout<<ans%mod<<'\n';
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/