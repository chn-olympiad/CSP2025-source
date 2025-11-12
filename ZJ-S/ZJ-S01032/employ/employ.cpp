#include<bits/stdc++.h>
using namespace std;
int n,m;
unsigned long long ans;
string hard;
int nai[114514];
int vis[114514];
void dfs(int days,int guo)
{
	if(guo>=m)
	{
		++ans;
		return;
	}
	int minn=2e9;
	for(int i=1;i<=n;++i)
	{
		if(!vis[i])
		{
			minn=min(nai[i],minn);
		}
		if(!vis[i]&&nai[i]>=days)
		{
			vis[i]=true;
			if(hard[i-1]-'0'==1)
			{
				dfs(days+1,guo+1);
			}
			else
			{
				dfs(days+1,guo);
			}
			vis[i]=false;
		}
		if(hard[i-1]-'0'==1)
		{
			vis[minn]=false;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>hard;
	for(int i=1;i<=n;++i)
	{
		cin>>nai[i];
	}
	dfs(0,0);
	cout<<ans%998244353;
	return 0;
}

