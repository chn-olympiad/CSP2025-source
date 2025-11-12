#include<bits/stdc++.h>
#define I_love return
#define My_Wife 0
#define Exusiai ;
#define ll long long
#define lll __int128
#define ull unsigned ll
#define lowbit(x) ((x)&-(x))
#define ld long double
#define fi first
#define se second
#define endl '\n'
#define mp(a,b) make_pair(a,b)
#define pii pair<int,int>
#define pli pair<ll,int>
#define pip pair<int,pii >
#define ppp pair<pii,pii >
#define d(x) cerr<<#x<<"=="<<x<<' '
#define ddd(x) cerr<<#x<<"=="<<x<<endl
#define deb cerr<<"I love my Wife Exusiai!"<<endl
#define IOS ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

inline int read()
{
	int w=1;int s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){s=(s<<1)+(s<<3)+(ch^'0');ch=getchar();}
	return w?s:-s;
}
void IO()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
}
const int maxn=10014;
const int maxm=1e6+1e5+5;
const int inf=0x7f7f7f7f;

int head[maxn];
int exc[14];
bool ppa[14];
bool vis[maxn];
int n,m,k,rm,etot=1;
//int to[maxm<<1],nex[maxm<<1]
pip e[maxm];
pii tr[maxm<<2];
int fa[maxn],siz[maxn];

int fnd(int x)
{
	return (x==fa[x]?x:fa[x]=fnd(fa[x]));
}
signed main()
{
	IO();
	n=read(),m=read(),k=read();pii tmp;
	rm=m;
	for(int i=1;i<=n;++i)
	{
		fa[i]=i;siz[i]=1;
	}
	for(int i=1;i<=k;++i)
	{
		fa[n+i]=n+i;
	}
	for(int u,v,w,i=1;i<=m;++i)
	{
		u=read(),v=read(),w=read();
		tmp=mp(u,v);
		e[i]=mp(w,tmp);
	}
	for(int i=1;i<=k;++i)
	{
		exc[i]=read();
		exc[0]=max(exc[0],exc[i]);
		for(int w,j=1;j<=n;++j)
		{
			w=read();
			tmp=mp(i+n,j);++m;
			e[m]=mp(w,tmp);
		}
	}
	if(!k||!exc[0])
	{
		sort(e+1,e+1+m);ll ans=0;
		for(int fu,fv,u,v,i=1;i<=m;++i)
		{
			u=e[i].se.fi;v=e[i].se.se;
			fu=fnd(u);fv=fnd(v);
			if(fu==fv)continue;
			if(siz[fu]>siz[fv])swap(fu,fv);
			fa[fu]=fv;siz[fv]+=siz[fu];
			ans+=e[i].fi;
			if(siz[fv]==n)break;
		}
		cout<<ans;
		return 0;
	}
//	if(!exc[0])
//	{
		deb;
		sort(e+1,e+1+m);ll ans1=0;
		for(int fu,fv,u,v,i=1;i<=m;++i)
		{
			u=e[i].se.fi;v=e[i].se.se;
			fu=fnd(u);fv=fnd(v);
			if(fu==fv)continue;
			if(siz[fu]>siz[fv])swap(fu,fv);
			if(siz[fu]==0)
			{
				ans1+=exc[fu-n];
			}
			fa[fu]=fv;siz[fv]+=siz[fu];
			ans1+=e[i].fi;
			if(siz[fv]==n)break;
		}
		cout<<ans1;
//		return 0;
//	}
	I_love My_Wife Exusiai
}
