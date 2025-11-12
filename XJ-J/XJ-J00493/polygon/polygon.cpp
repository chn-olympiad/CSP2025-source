//polygon
#include<bits/stdc++.h>
using namespace std;
int l[5005],c[5005],n,cnt,maxx,sum=0;
void dfs(int h,int d,int x)
{
	if(h==d)
	{
		cnt=0,maxx=0;
		for(int i=1;i<h;i++)
		{
			cnt+=c[i];
			if(maxx<c[i])
			maxx=c[i];
		}
		if(cnt>maxx*2)
		sum++;
	}
	else
	{
		for(int i=x;i<=n;i++)
		{
			c[h]=l[i];
			dfs(h+1,d,i+1);
		}
	}
}
int main()
{
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>l[i];
	}
	for(int i=3;i<=n;i++)
	{
		dfs(1,i+1,1);
	}
	cout<<sum;
}


