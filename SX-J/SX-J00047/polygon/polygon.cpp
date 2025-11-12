#include<bits/stdc++.h>
using namespace std;
int b[5010],ans=0,c[5010][5010];
int n;
void dfs(int t,int h,int zd,int l)
{
	if(t==n+1)
	{
		if(zd*2<h&&l>=3) ans++;
		return;
	}

	if(b[t]>zd) dfs(t+1,h+b[t],b[t],l+1);
	else dfs(t+1,h+b[t],zd,l+1);
	dfs(t+1,h,zd,l);
	return;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    c[1][0]=1;
    c[1][1]=1;
    for(int i=1;i<=n;i++)
    {
    	cin>>b[i];
	}
    if(n<=30)
    {
    	dfs(1,0,0,0);
	}
	else
	{
		for(int i=2;i<=n;i++)
		{
          for(int j=0;j<=i;j++)
          {
          	c[i][j]=c[i-1][j-1]+c[i-1][j];
          	c[i][j]=c[i][j]%998244353;
		  }
		}

			for(int j=3;j<=n;j++)
			{
				ans=ans+c[n][j];
				ans=ans%998244353;
			}
	}
	cout<<ans;
	return 0;
}