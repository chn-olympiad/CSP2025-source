#include<bits/stdc++.h>
#define FOR(i,j,k) for(int i=(j);i<=(k);++i)
#define NFOR(i,j,k) for(int i=(j);i>=(k);--i)
#define fst first
#define sec second
#define pb push_back
#define mkp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const ll infll=0x3f3f3f3f3f3f3f3fll;
ll read()
{
	ll s=0,w=1;char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1,c=getchar();}
	while(c>='0'&&c<='9') {s=(s<<1)+(s<<3)+c-'0';c=getchar();}
	return s*w;
}
void file(string s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int N=1e4+5;

int n,m,k;
ll ans;
ll a[N][N],c[N];

namespace dsu
{
	int fa[N];
	void init()
	{
		FOR(i,1,n) fa[i]=i;
	}
	int find(int x)
	{
		return x==fa[x]?x:fa[x]=find(fa[x]);
	}
	void mrg(int x,int y)
	{
		int fx=find(x),fy=find(y);
		if(fx==fy) return ;
		fa[fx]=fy;
	}
}
using namespace dsu;

priority_queue <pair<ll,pair<pii,pii>>,vector<pair<ll,pair<pii,pii>>>,greater<pair<ll,pair<pii,pii>>>> q;
bool vis[2000005];

int main()
{
	file("road");
	n=read();m=read();k=read();
	init();
	int id=1;
	FOR(i,1,m){ll u=read(),v=read(),w=read();q.push(mkp(w,mkp(mkp(0,id),mkp(u,v)))),id++;}
	FOR(i,1,k){c[i]=read();FOR(j,1,n) a[i][j]=read(),q.push(mkp(a[i][j]+a[i][i],mkp(mkp(1,id),mkp(i,j)))),id++;}
	while(!q.empty())
	{
		pair<ll,pair<pii,pii>> nxt=q.top();
		q.pop();
		int l=nxt.sec.sec.fst,r=nxt.sec.sec.sec;
		if(find(l)==find(r)) continue;
		//printf("%d %d %d %d %d\n",nxt.fst,nxt.sec.fst,nxt.sec.sec.fst,nxt.sec.sec.sec,ans);
		if(nxt.sec.fst.fst==1&&!vis[nxt.sec.fst.sec])
		{
			q.push(mkp(nxt.fst+c[l],mkp(mkp(2,nxt.sec.fst.sec),nxt.sec.sec)));
			continue;
		} 
		if(nxt.sec.fst.fst==1&&vis[nxt.sec.fst.sec])
		{
			ans+=nxt.fst;
			mrg(nxt.sec.sec.fst,nxt.sec.sec.sec);
			continue;
		}
		if(nxt.sec.fst.fst==2)
		{
			ans+=nxt.fst,vis[nxt.sec.fst.sec]=1;
			mrg(nxt.sec.sec.fst,nxt.sec.sec.sec);
			continue;
		} 
		else
		{
			ans+=nxt.fst;
			mrg(nxt.sec.sec.fst,nxt.sec.sec.sec);
			continue;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
1 1 8 2 4
100 1 3 2 4

*/
