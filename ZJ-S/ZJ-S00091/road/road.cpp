#include<bits/stdc++.h>
using namespace std;
#define FIO(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define ll long long
const int _=10015,__=1e6+6;
int n,m,al,el,u,v,w,sz[_],Sz[1026],a[12],fa[_],fl[1026],lg[_];
ll g[1026],s[1026],ans=1e18;
struct E
{	int u,v,w;
	E(int _u=0,int _v=0,int _w=0):u(_u),v(_v),w(_w){}
	inline bool operator<(const E o)const
	{	if(w!=o.w)	return w<o.w;
		if(u!=o.u)	return u<o.u;
		return v<o.v;
	}
}	e[__],o[12][_],f[1026][_];
inline int getf(int u){	return fa[u]==u?u:fa[u]=getf(fa[u]);}
inline void U(E e,int w)
{	u=getf(e.u),v=getf(e.v);
	if(u!=v)
	{	if(sz[u]<sz[v])	swap(u,v);
		sz[u]+=sz[v],fa[v]=u,f[w][++fl[w]]=e,s[w]+=e.w;
	}
}
signed main()
{	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	FIO("road");
//	FIO("road1");
	cin>>n>>m>>al,Sz[0]=n-1;
	for(int i=2;i<(1<<al);i++)	lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;i++)	fa[i]=i,sz[i]=1;
	while(m--)	cin>>u>>v>>w,e[++el]=E(u,v,w);
	sort(e+1,e+el+1);
	for(int i=1;i<=el;i++)	U(e[i],0);
	ans=s[0];
	for(int i=1;i<=al;i++)
	{	cin>>a[i];
		for(int j=1;j<=n;j++)	cin>>w,o[i][j]=E(i+n,j,w);
		sort(o[i]+1,o[i]+n+1);
	}
	for(int i=1,k,j,I,J;i<(1<<al);i++)
	{	k=(i&-i),j=(i^k),k=lg[k]+1,g[i]=g[j]+a[k],Sz[i]=Sz[j]+1,I=J=1;
		for(int K=1;K<=n+al;K++)	fa[K]=K,sz[K]=1;
		while(I<=fl[j]&&J<=n)
		{	if(f[j][I]<o[k][J])	U(f[j][I],i),I++;
			else	U(o[k][J],i),J++;
		}
		while(I<=fl[j])	U(f[j][I],i),I++;
		while(J<=n)	U(o[k][J],i),J++;
		if(fl[i]==Sz[i])	ans=min(ans,s[i]+g[i]);
	}
	cout<<ans;
	return 0;
}
