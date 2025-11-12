#include<bits/stdc++.h>
using namespace std;
int const N=1e6+5;
int t,n,a[N][5],ans=-1e9,d[5];
int read()
{
	char c;
	int x=0,f=1;
	c=getchar();
	if(c=='-')f=-1;
	else while(c>='0'&&c<='9')
	{
		x*=10;
		x+=(int)c-'0';
		c=getchar();
	}
	return f*x;
}
void dfs(int now,int sum)
{
	if(now==n+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int j=1;j<=3;j++)
	{
		if(d[j]+1<=n/2)
		{
			d[j]+=1;
			dfs(now+1,sum+a[now][j]);
			d[j]-=1;
		}
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	t=read();
	for(int x=1;x<=t;x++)
	{
		n=read();
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				a[i][j]=read();
			}
		}
		ans=-1e9;
		memset(d,0,sizeof(d));
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}

