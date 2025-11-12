#include<iostream>
#include<queue>
#include<algorithm>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e4+100;
const int M=1e6+10;
const int K=15;
ll read()
{
	int s=0,w=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch==-1) w=-1; ch=getchar();}
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;
}
void print(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>=10) print(x/10);
	putchar(x%10+'0');
}
int n,m,k,ce,f[N],s[N],pos[K]; ll res,cur;
priority_queue <pii> q;
struct edg{int u,v,w;}e[M],g[N];
bool cme(edg A,edg B) {return A.w<B.w;}
int finds(int x) {return f[x]==x?x:f[x]=finds(f[x]);}
bool mg(int x,int y)
{
	x=finds(x),y=finds(y);
	if(x==y) return false;
	if(s[x]>s[y]) swap(x,y);
	s[y]+=s[x],f[x]=y; return true;
}
void MST(bool tf)
{
	cur=0;
	for(int i=1;i<=n+k;i++) f[i]=i,s[i]=1;
	for(int i=1;i<=m;i++) if(mg(e[i].u,e[i].v))
	{
		cur+=e[i].w;
		if(tf) g[++ce]=e[i];
	}
}
struct nod
{
	int c; pii a[N];
	bool cmp(int i,int j) {return a[i]<a[j];}
	void ini()
	{
		c=read();
		for(int i=1;i<=n;i++) a[i].fi=read(),a[i].se=i;
		sort(a+1,a+1+n);
	}
}T[K];
int main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++) e[i].u=read(),e[i].v=read(),e[i].w=read();
	sort(e+1,e+1+m,cme),MST(1),res=cur;
	for(int i=0;i<k;i++) T[i].ini();
	for(int S=1;S<(1<<k);S++)
	{
		ll ts=0; m=0,q.push({-g[1].w,k}),pos[k]=1;
		for(int i=0;i<k;i++) if((S>>i)&1)
			ts+=T[i].c,q.push({-T[i].a[1].fi,i}),pos[i]=1;
		while(q.size())
		{
			int u=q.top().se,lim=n-(u==k); q.pop();
			if(u==k) e[++m]=g[pos[u]];
			else e[++m]={n+u+1,T[u].a[pos[u]].se,T[u].a[pos[u]].fi};
			pos[u]++;
			if(pos[u]<=lim) q.push({-(u==k?g[pos[u]].w:T[u].a[pos[u]].fi),u});
		}
		MST(0),res=min(res,ts+cur);
	}
	print(res);
	return 0;
}
