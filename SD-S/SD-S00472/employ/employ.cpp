#include <bits/stdc++.h>
using namespace std;
const int N=507;
const long long mo=998244353;
int n,m;
int s[N];
int c[N];
bool bj[N];
long long ans;
void dfs(int x,int gt,int fir)
{
	if(x==n+1)
	{
		//cout<<ans<<'\n';
		if(gt>=m)
		{
			ans=(ans+1)%mo;
		}
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(bj[i])continue;
		if(s[x]==0||c[i]<=fir)
		{
			bj[i]=1;
			fir++;
			dfs(x+1,gt,fir);
			fir--;
			bj[i]=0;
			continue;
		}
		if(s[x]==1&&c[i]>fir)
		{
			bj[i]=1;
			gt++;
			dfs(x+1,gt,fir);
			gt--;
			bj[i]=0;
			continue;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		char x;cin>>x;s[i]=x-'0';
		if(s[i]==0)sum++;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	} 
	if(n-sum<m)
	{
		cout<<0;
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		if(s[1]==0)
		{
			bj[i]=1;
			dfs(2,0,1);
			bj[i]=0;
		}
		if(s[1]==1)
		{
			bj[i]=1;
			dfs(2,1,0);
			bj[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
/*
[²»ÉÙÓÚ] <=> [>=]
10 5
1101111011
6 0 4 2 1 2 5 4 3 3
*/
