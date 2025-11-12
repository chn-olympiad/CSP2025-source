#include<bits/stdc++.h>
using namespace std;
int n,a[5010],t,ans,c[5005],d;
bool b[5010];
bool cmp(int x,int y)
{
	if(x!=y) return x<y;
	else return 0;
}
void dfs(int x,int y,int j)
{
	if(y>t) return;
	if(y==t) 
	{
		d=0;
		for(int k=1;k<=t-1;k++)
		{
			d+=c[k];
			if(d>c[t]) {ans++,ans%=998244353;return;}
		}
		return;
	}
	for(int i=j;i<=n;i++)
		if(!b[i])
		{
			b[i]=1;
			c[x]=a[i];
			dfs(x+1,y+1,i+1);
			b[i]=0;
		}
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	for(int i=3;i<=n;i++)
	{
		t=i;
		dfs(1,0,1);
	}
	cout<<ans;
	return 0;
}
