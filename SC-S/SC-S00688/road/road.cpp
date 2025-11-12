#include<bits/stdc++.h>
#define i128 __int128
#define ll long long
#define db long double
#define Pii pair<int,int>
#define fi first
#define se second

using namespace std;
const int N=1.1e4+10;
const int M=1.1e6+10;
const int K=11;

int m,k,c[N]; short n,f[N],s[N]; ll ans=1e18;
struct node{short u,v,fl; int w;}a[M];

inline bool cmp(node q,node w) {return q.w<w.w;}
inline bool cmp2(node q,node w)
{
	if(q.fl+w.fl<2) return q.fl==1;
	return q.w<w.w;
}

inline short find(short x) {return f[x]==x?x:f[x]=find(f[x]);}

inline void kru(short x)
{
	ll h=0; short v=0,fu,fv;
	for(int i=1;i<=k;++i) if(x&(1<<(i-1))) ++v,h+=c[i];
	for(int i=1;i<=n+k;++i) f[i]=i;
	for(int i=1;i<=n+k;++i) s[i]=1;
	for(int i=1;i<=m;++i)
	{
		if(!a[i].fl) return;
		if(a[i].u>n&&(!(x&(1<<(a[i].u-n-1))))) continue;
		fu=find(a[i].u); fv=find(a[i].v);
		if(fu==fv) continue;
		h+=a[i].w; if(s[fu]>s[fv]) swap(fu,fv);
		f[fu]=fv; s[fv]+=s[fu];
		if(h>ans) return;
		if(s[fv]==n+v) {ans=min(ans,h); return;}
	}
}

inline void kru1()
{
	int cnt=0,fu,fv;
	for(int i=1;i<=n;++i) f[i]=i,s[i]=1;
	for(int i=1;i<=m;++i)
	{
		fu=find(a[i].u); fv=find(a[i].v);
		if(fu==fv) continue; ++cnt; a[i].fl=1;
		if(s[fu]>s[fv]) swap(fu,fv);
		f[fu]=fv; s[fv]+=s[fu];
		if(cnt>=n-1) return;
	}
}

signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m>>k; int u,v,w;
	for(int i=1;i<=m;++i) cin>>a[i].u>>a[i].v>>a[i].w;
	sort(a+1,a+m+1,cmp); kru1();
	for(int i=1;i<=k;++i)
	{
		cin>>c[i];
		for(int j=1;j<=n;++j)
		{
			cin>>a[++m].w;
			a[m].u=n+i; a[m].v=j;
			a[m].fl=1;
		}
	}
	sort(a+1,a+m+1,cmp2);
	for(int i=0;i<(1<<k);++i) kru(i);
	cout<<ans;
	return 0;
}