#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int N=1e4+50,M=3e6+50;
int h[N],nxt[M],to[M],fl[M],w[M],st,idx,c[N],dist[N],bin[15];
int n,m,k;
void add(int u,int v,int c,int s) {
	nxt[++idx]=h[u];
	h[u]=idx;
	to[idx]=v;
	fl[idx]=s-1;
	w[idx]=c;
}
priority_queue<PII,vector<PII>,greater<PII> >q;
bool vis[N];
ll ans=1e18;
void solve() {
	memset(dist,0x7f,sizeof dist);
	ll res=0;
	for(int i=1; i<=k; ++i) {
		if(st&(1<<(i-1))) {
			res+=c[i];
		}
	}
	if(res>=ans)return;
	memset(vis,0,sizeof vis);
	while(!q.empty())q.pop();
	q.push({0,1});
	while(!q.empty()) {
		int u=q.top().second,v=q.top().first;
		q.pop();
		if(vis[u])continue;
		res+=v;
		if(res>=ans)return;
		vis[u]=1;
		for(int i=h[u]; i; i=nxt[i]) {
			if(((fl[i]!=-1 && st&bin[fl[i]]) || fl[i]==-1)&&!vis[to[i]] && w[i]<dist[to[i]]) {
				q.push({w[i],to[i]});
				dist[to[i]]=w[i];
			}
		}
	}
	ans=res;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	bin[0]=1;
	for(int i=1; i<=10; ++i) {
		bin[i]=bin[i-1]<<1;
	}
	bool flag=1;
	for(int i=1; i<=m; ++i) {
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a,b,c,0);
		add(b,a,c,0);
	}
	for(int i=1; i<=k; ++i) {
		scanf("%d",&c[i]);
		if(c[i]!=0)flag=0;
		for(int j=1; j<=n; ++j) {
			int v;
			scanf("%d",&v);
			add(i+n,j,v,i);
			add(j,i+n,v,i);
		}
	}
	if(k<=5)for(st=0; st<(1<<k); ++st)solve();
	else if(flag)st=(1<<(k+1))-1,solve();
	printf("%lld",ans);
	return 0;
}

