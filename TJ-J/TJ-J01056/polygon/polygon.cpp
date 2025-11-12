#include<bits/stdc++.h>
using namespace std;
int a[5010],b[5010];
bool v[5010];
int n;
long long ans;
void dfs(int s,int u,int t)
{
	if(u>s)
	{
		for(int l=1;l<=s;l++)
		{
			int sum=0,maxn=0;
			for(int j=0;j<s;j++)
			{
				sum+=b[l+j];
				maxn=max(b[l+j],maxn);
			}
			if(sum>maxn*2)
				ans++;
		}
		return;
	}
	for(int i=t;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=1;
			b[u]=a[i];
			dfs(s,u+1,i+1);
			v[i]=0;
			u--;
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=3;i<=n;i++)
	{
		dfs(i,1,1);
	}
	cout<<ans%998%244%353;
	return 0;
}
