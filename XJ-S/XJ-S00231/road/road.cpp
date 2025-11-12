#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+6;
int m,n,k,ans=1e8+5;
int u[N],v[N],w[N],h[N];
void d(int x,int p,int f)
{
	p+=w[x];
	h[u[x]]=1,h[v[x]]=1;
	int l=0;
	for(int i=1;i<=n;i++)
	{
//		cout<<h[i]<<' ';
		if(h[i]>0)
		{
			l++;
		}
	}
//	cout<<'\n';
	if(l>=n)
	{
//		cout<<p<<'\n';
		ans=min(ans,p);
		return;
	}
	for(int i=1;i<=m;i++)
	{
		if(f==1&&i!=x)
		{
			if(v[x]==u[i]&&v[i]!=u[x])
			{
				d(i,p,1);
			}
			if(v[x]==v[i]&&u[x]!=u[i])
			{
				d(i,p,2);
			}
		}
		if(f==2&&i!=x)
		{
			if(v[i]==u[x]&&v[x]!=u[i])
			{
				d(i,p,2);
			}
			if(v[i]!=v[x]&&u[x]==u[i])
			{
				d(i,p,1);
			}
		}
	}
	h[u[x]]=0,h[v[x]]=0;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u[i]>>v[i]>>w[i];
	}
	for(int i=1;i<=m;i++)
	{
		memset(h,0,sizeof(h));
		d(i,0,1);
		d(i,0,2);
		memset(h,0,sizeof(h));       
	}
	cout<<ans<<'\n';
	return 0;
}
