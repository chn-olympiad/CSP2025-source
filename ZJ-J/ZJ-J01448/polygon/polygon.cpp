#include<bits/stdc++.h>
using namespace std;
int js;
int a[5001];
int sum[5001][5001];
int s[5001];
int ans;
int n;
void dfs(int dq,int mx,int sum,int gs,bool sf)
{
	if(sum>mx*2&&gs>=3&&sf)
	{
		js++;
	}
	js%=998244353;
	if(dq==n)
	{
		return;
	}
	dq++;
	dfs(dq,mx,sum,gs,false);
	mx=max(mx,a[dq]);
	sum+=a[dq];
	gs++;
	dfs(dq,mx,sum,gs,true);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+1+n);
	if(n<=20)
	{
		dfs(0,0,0,0,false);
		cout<<js<<endl;
	}
	else
	{
		sum[0][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<=5000;j++)
			{
				if(sum[i-1][j])
				{
					sum[i][j]+=sum[i-1][j];
					sum[i][j]%=998244353;
					sum[i][j+a[i]]+=sum[i-1][j];
					sum[i][j+a[i]]%=998244353;
				}
			}
		}
		for(int i=3;i<=n;i++)
		{
			for(int j=a[i]+1;j<=5000;j++)
			{
				ans+=sum[i-1][j];
				ans%=998244353;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
