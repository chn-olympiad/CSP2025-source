#include <bits/stdc++.h>
using namespace std;
const int M=1100005,maxn=1e9,N=10005;
long long ans=maxn;
int n,m,k,feiyong;
struct edge{
	int u,v,w;
} e[M];
int bcj[N];
int find(int x)
{
	if(bcj[x]!=x)
	{
		bcj[x]=find(bcj[x]);
	}
	return bcj[x];
} 
bool cmp(edge x,edge y)
{
	return x.w<y.w;
}
int mm;
int choose(int di)//第i个城镇(m+di) 
{
	int ans=0;
	if(di<k)
	{
		choose(di+1);
	}
	
	for(int i=mm+1;i<=mm+n;i++)
	{
		e[i].u=m+di;
		e[i].v=i-mm;
	}
}
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+m+1,cmp);
	for(int i=1;i<=n;i++) bcj[i]=i;
	int lu=1;
	for(int i=1;i<=m;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			bcj[e[i].v]=e[i].u;
			lu++;
			feiyong=feiyong+e[i].w;
		}
		if(lu==n) break;
	}
	
	cout<<feiyong;
//	mm=m;
//	choose(1);
	return 0;
 } 

