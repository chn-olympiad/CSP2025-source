#include<bits/stdc++.h>
using namespace std;
int x,n,v;
int a[100005][5],d[100005],maxn;
void dfs(int step,int a1,int b1,int c1)
{
	if(step>n)
	{
		int s=0;
		for(int i=1;i<=n;i++)
		{
			s+=a[i][d[i]];
		}
		maxn=max(maxn,s);
		return;
	}
	if(a1+1<=v)
	{
		d[step]=1;
		dfs(step+1,a1+1,b1,c1);
	}
	if(b1+1<=v)
	{
		d[step]=2;
		dfs(step+1,a1,b1+1,c1);
	}
	if(c1+1<=v)
	{
		d[step]=3;
		dfs(step+1,a1,b1,c1+1);
	}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>x;
	while(x--)
	{
		cin>>n;
		maxn=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=3;j++)
			{
				cin>>a[i][j];
			}
		}
		v=n/2;
		dfs(1,0,0,0);
		cout<<maxn<<endl;
	}
	return 0;
}
	
 