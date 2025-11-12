#include<bits/stdc++.h>
using namespace std;
int i,j,k,t,w,s=0,a[5005],n,m;
void dfs(int step,int maxx,int now)
{
	if(step>=n)
	{
		if(now>maxx*2)
		{
			s++;
			
		}
		return;
	}
	if(a[step+1]>maxx)
	{
		dfs(step+1,a[step+1],now+a[step+1]);
	}
	else
	{
		dfs(step+1,maxx,now+a[step+1]);
	}
	dfs(step+1,maxx,now);
	return;
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<s%998244353;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
