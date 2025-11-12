#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define pii pair<int,int>
#define fs first
#define sc second
#define il inline
#define re register
using namespace std;
il int read()
{
	re int x=0;
	re int ff=1;
	re char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')
			ff=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*ff;
}
const int N=1e6+6;
const int M=1e4+16;
struct qwq_{
	int u,v,w;
};
qwq_ e[N<<1],a[M];
int n,m,k,fa[M],ptr[16];
pii b[16][M];
il int find(re int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
il void kruskal()
{
	sort(e+1,e+1+m,[](re qwq_ x,re qwq_ y){return x.w<y.w;});
	for(re int i=1;i<=n;i++)fa[i]=i;
	for(re int i=1,cnt=1;i<=m&&cnt<n;i++){
		re int u=find(e[i].u),v=find(e[i].v);
		if(u^v)a[++cnt]=e[i],fa[u]=v;
	}return;
}
signed main()
{
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read();
	m=read();
	k=read();
	for(re int i=1;i<=m;i++)
		e[i].u=read(),e[i].v=read(),e[i].w=read();
	for(re int i=0;i<k;i++){
		for(re int j=0;j<=n;j++)
			b[i][j]={read(),j};
		sort(b[i]+1,b[i]+1+n,[](re pii x,re pii y){return x.fs<y.fs;});
	}
	kruskal();re ll awa=1e18;
	for(re int i=0;i<(1<<k);i++){
		re int sum=n,cnt=1;re ll qwq=0;
		priority_queue<pii,vector<pii>,greater<pii> > q;
		for(re int j=0;j<k;j++)
			if(i>>j&1)q.push({b[j][1].fs,j}),qwq+=b[j][0].fs,ptr[j]=1,sum++;
		q.push({a[2].w,k}),ptr[k]=2,m=0;
		while(!q.empty()){
			re int u=q.top().sc,w=q.top().fs;q.pop();
			if(u<k)e[++m]={n+u+1,b[u][ptr[u]].sc,w},(ptr[u]<n?q.push({b[u][++ptr[u]].fs,u}),0:0);
			else e[++m]=a[ptr[k]],(ptr[k]<n?q.push({a[++ptr[k]].w,k}),0:0);
		}sort(e+1,e+1+m,[](re qwq_ x,re qwq_ y){return x.w<y.w;});
		for(re int i=1;i<=n+k;i++)fa[i]=i;
		for(re int i=1;i<=m&&cnt<sum;i++){
			re int u=find(e[i].u),v=find(e[i].v);
			if(u^v)cnt++,qwq+=e[i].w,fa[u]=v;
		}awa=min(awa,qwq);
	}
	printf("%lld\n",awa);
	return 0;
}