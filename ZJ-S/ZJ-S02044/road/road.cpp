#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int u,v,w;
long long ans=LLONG_MAX;
struct Node
{
	int u,v,w;
	bool operator <(const Node &X) const
	{
		return w<X.w;
	}
};
Node e[4000*4000];
int ma[11][10010];
int c[11];
int f[10010];
int foud(int x)
{
	if(f[x])
	{
		return f[x];
	}
	return f[x]=foud(f[x]);
}
long long kri(int len)
{
	long long ans=0;
	sort(e+1,e+len+1);
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
	}
	int it=1;
	for(int i=1;i<=n-1;i++)
	{
		while(foud(e[it].u)==foud(e[it].v))
		{
			it++;
		}
		f[f[e[it].u]]=f[e[it].v];
		ans=ans+1ll*e[it].w;
		it++;
	}
	return ans;
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		e[i]=(Node){u,v,w};
	}
	if(k==0)
	{
		cout<<kri(m);
		return 0;
	}
	for(int i=0;i<k;i++)
	{
		cin>>c[i];
		for(int j=1;j<=n;j++)
		{
			cin>>ma[i][j];
		}
	}
	int n=pow(2,k);
	for(int i=0;i<n;i++)
	{
		int idx=m;
		long long num=0;
		for(int j=0;j<10;j++)
		{//½¨±ß 
			if((i>>j)%2==1)
			{
				num+=c[j];
				for(int k=1;k<=n;k++)
				{
					for(int l=1;k!=l&&l<=n;l++)
					{
						e[++idx]=(Node){k,l,ma[j][k]+ma[j][l]};
					}
				}
			}
		}
		ans=min(ans,num+kri(idx));
	}
	cout<<ans;
	return 0;
}
