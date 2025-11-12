#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
int read()
{
	char c;
	int x=0,f=1;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		{
			f=-1;
		}
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll g[10004];
ll f(ll x)
{
	if(x!=g[x]){
		g[x]=f(g[x]);
		return g[x];
	}
}
struct op
{
	ll u,v,w;
}edge[20000006];
bool cmp(op xxx,op yyy)
{
	return xxx.w <yyy.w;
}
//int cz[10004],c[10004][10004];
int main()
{
	//A:new-->old 
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ll n,m,k;
	n=read();
	m=read();
	k=read();
	for(int i=1;i<=m;i++)
	{
		edge[i].u=read();
		edge[i].v=read();
		edge[i].w=read();
	 } 
	 for(int i=1;i<=n;i++)
	 {
	 	g[i]=i;
	 }
	 ll cnt=m+1;
	 for(int i=1;i<=k;i++)
	 {
	 	ll c;
	 	c=read();//c==0
	 	for(int j=1;j<=n;j++)
	 	{
	 		ll k;
	 		k=read();
	 		edge[cnt].u=i;
	 		edge[cnt].v=j;
	 		edge[cnt].w=k;
	 		cnt++;
		 }
	 }
	 cnt--;
//	 for(int i=1;i<=cnt;i++)
//	 {
//	 	cout<<edge[i].u<<' '<<edge[i].v<<' '<<edge[i].w<<endl;;
//	 }
//	 for(int i=1;i<=k;i++)
//	 {
//	 	
//	 }
	if(k==0)//min maketree//16pts
	{
		 sort(edge+1,edge+1+m,cmp);
		 ll ans=0;
		 for(int i=1;i<=m;i++)
		 {
		 	ll u=edge[i].u ,v=edge[i].v,w=edge[i].w;
		 	if(g[f(v)]!=g[f(u)])
		 	{
		 		g[f(v)]=g[f(u)];
		 		ans+=w;
			 }
		 }
		 cout<<ans;
	}
	else{
		sort(edge+1,edge+1+cnt,cmp);
		 ll ans=0;
		 for(int i=1;i<=cnt;i++)
		 {
		 	ll u=edge[i].u ,v=edge[i].v,w=edge[i].w;
		 	if(f(u)!=f(v))
		 	{
		 		g[f(v)]=g[f(u)];
		 		ans+=w;
//		 		cout<<u<<' '<<v<<' '<<w<<'\n';
			 }
		 }
		 cout<<ans;
	}
	cout<<endl;
	return 0;
 } 
 /*
 4 4 2
 1 4 6
 2 3 7
 4 2 5
 4 3 4
 0 1 8 2 4
 0 1 3 2 4
 
 */
