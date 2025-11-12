#include<iostream>
#include<climits>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
char buf[1<<20],*p1,*p2;
#define pb push_back
#define gc() (p2==p1&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin)),*p1++)
template<typename T>
void read(T &v){
	T x=0,f=1;char ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-f;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc();}
	v=x*f;
}
template<typename T,typename ...Args>
void read(T &tmp,Args &...tmps){read(tmp);read(tmps...);}
using ll=long long;
using namespace std;
const ll inf=LLONG_MAX;
int c[15];
vector<int>D[15];
ll d[1010][1010],nw[1010][1010];
int fa[10010];
int find(int u){
	if(u==fa[u])return u;
	return fa[u]=find(fa[u]);
}
void unite(int u,int v){
	u=find(u);v=find(v);
	fa[u]=v;
}
struct Edge{
	int u,v;
	ll w;
	friend bool operator <(Edge p1,Edge p2){
		return p1.w>p2.w;
	}
};
priority_queue<Edge>q;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;read(n,m,k);
	for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)d[i][j]=inf;
	for(int i=1,u,v,w;i<=m;++i){
		read(u,v,w);
		d[u][v]=d[v][u]=min(d[v][u],(ll)w);
	}
	for(int i=1,x;i<=k;++i){
		read(c[i]);
		for(int j=1;j<=n;++j){
			read(x);D[i].pb(x);
		}
	}
	ll ans=inf;
	for(int S=0;S<(1<<k);++S){
		ll sum=0;
		for(int i=1;i<=n;++i)fa[i]=i;
		while(!q.empty())q.pop();
		Edge cur;
		for(int i=1;i<=k;++i)if(S&(1<<i-1))sum+=c[i];
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				nw[i][j]=nw[j][i]=d[i][j];
				for(int l=1;l<=k;++l){
					if(S&(1<<l-1))nw[i][j]=nw[j][i]=min(nw[i][j],(ll)(D[l][i-1]+D[l][j-1]));
				}
				cur.u=i;cur.v=j;cur.w=nw[i][j];
				q.push(cur);
			}
		}
		int cnt=0;
		while(cnt!=n-1){
			cur=q.top();q.pop();
			if(find(cur.u)==find(cur.v))continue;
			sum+=cur.w;++cnt;
			unite(cur.u,cur.v);
		}
		ans=min(ans,sum);
	}
	printf("%lld",ans);
	return 0;
}
