#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1005,logN=15,K=20,M=1e6+6;
int c[K],fa[N],dis[N][N],a[K][N];
priority_queue<pair<int,pair<int,int> > > q;
struct Line {
	int u,v,w;
}l[M];
int find(int x) {
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
LL Tree(int n) {
	LL cnt=0;
	int line=0;
	while(!q.empty()) {
		int u=q.top().second.first,v=q.top().second.second;
		int fu=find(u),fv=find(v);
		if(fu!=fv) {
			line++;
			int w=(-q.top().first);
			cnt+=(LL)w;
			fa[fu]=fv;
		}
		if(line==n-1) break;
		q.pop();
	}
	return cnt;
}
void build(int n,int m) {
	while(!q.empty()) q.pop();
	for(int i=1;i<=m;i++) {
		int u=l[i].u,v=l[i].v,w=l[i].w;
		q.push(make_pair(-w,make_pair(u,v)));
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=1e9;
	return;
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>l[i].u>>l[i].v>>l[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i];
		for(int j=1;j<=n;j++) cin>>a[i][j];
	}
	LL minn=1e18;
	for(int s=0;s<(1<<k);s++) {
		LL ans=0;
		build(n,m);
		for(int i=1;i<=k;i++)
			if((s&(1<<(i-1)))!=0) ans+=c[i];
		if(ans>minn) continue;
		for(int t=1;t<=k;t++)
			if((s&(1<<(t-1)))!=0) {
				for(int i=1;i<=n;i++)
					for(int j=i;j<=n;j++)
						if(i!=j) dis[i][j]=min(dis[i][j],a[t][i]+a[t][j]);
			}
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++)
				if(i!=j) q.push(make_pair(-dis[i][j],make_pair(i,j)));
		minn=min(minn,ans+Tree(n));
	}
	cout<<minn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
