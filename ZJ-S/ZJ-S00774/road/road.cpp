#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
struct node{
	int u,v;
}a[N];
long long n,m,k,ans,father[N];
map<long long,node>mp;
int find(int fa)
{
	if(father[fa]!=fa)
	{
		father[fa]=find(father[fa]);
	}
	return father[fa];
}
void unine(int x,int y,int spend)
{
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy)
	{
		father[fy]=fx;
		ans+=spend;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&k);
	long long maxx=0;
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
        mp[w]={u,v};
	}
	for(int i=1;i<=n;i++)
	{
		father[i]=i;
	}
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			long long w;
			cin>>w;
			maxx=max(maxx,w);
		}
	}
	if(maxx==0)
	{
		cout<<0;
		return 0;
	}
	for(auto i:mp)
	{
		unine(i.second.u,i.second.v,i.first);
	}
	printf("%lld",ans);
	return 0;
}
