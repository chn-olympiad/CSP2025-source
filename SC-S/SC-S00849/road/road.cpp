#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int maxn=1e4+10,mod=1e9+7;
const ll inf=1e18;
char *p1,*p2,buf[100000];
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p2==p1)?EOF:*p1++)
inline int read()
{
	int k=0,f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-') f=-1;c=getchar();}
	while(c>='0' and c<='9') k=k*10+c-'0',c=getchar();
	return k*f;
}
struct edge{
	int u,v,w;
	bool operator < (const edge &X)
	{
		return w<X.w;
	}
} e[1000010];
int n,m,k,cntt,c[11],fa[maxn],a[11][maxn],cnt;
ll ans=inf;
pii t[maxn*11];
void init()
{
	for(int i=1;i<=n+k;i++) fa[i]=i;
}
int find(int x)
{
	if(fa[x]!=x) fa[x]=find(fa[x]);
	return fa[x];
}
bool cmp(pii x,pii y)
{
	int wx,wy;
	if(x.first==0) wx=e[x.second].w;
	else wx=a[x.first][x.second];
	if(y.first==0) wy=e[y.second].w;
	else wy=a[y.first][y.second];
	return wx<wy;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1;i<=m;i++)
	{
		e[++cntt].u=read(),e[cntt].v=read(),e[cntt].w=read();
	}
	for(int i=1;i<=k;i++)
	{
		c[i]=read();
		for(int j=1;j<=n;j++) a[i][j]=read(),t[++cnt].first=i,t[cnt].second=j;
	}
	sort(e+1,e+cntt+1);
	init();
	for(int i=1;i<=cntt;i++)
	{
		if(find(e[i].u)!=find(e[i].v))
		{
			fa[find(e[i].v)]=find(e[i].u);
			t[++cnt].first=0,t[cnt].second=i;
		}
	}
	sort(t+1,t+cnt+1,cmp);
	for(int st=0;st<(1<<k);st++)
	{
		ll sum=0,tot=0,num=0;
		for(int i=0;i<k;i++) sum+=1ll*(st>>i&1)*c[i+1],num+=(st>>i&1);
		if(sum>ans) continue;
		init();
		for(int i=1;i<=cnt;i++)
		{
			if(t[i].first and !(st>>(t[i].first-1)&1)) continue;
			int u,v;
			ll w;
			if(!t[i].first)
			{
				u=e[t[i].second].u,v=e[t[i].second].v,w=e[t[i].second].w;
			}
			else
			{
				u=t[i].first+n,v=t[i].second,w=a[t[i].first][t[i].second];
			}
			if(find(u)!=find(v)) tot++,sum+=w,fa[find(v)]=find(u);
			if(tot==n+num-1 or sum>ans) break;
		}
		ans=min(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
