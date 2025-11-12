#include <bits/stdc++.h>
#define int long long
using namespace std;
struct edge{
	int u,v,w;
}p[1500000],bp[1500000];
bool cmp(edge q,edge h){
	return q.w<h.w;
}
int n,m,k,bcnt,cnt,cw,ans,fa[10100],w[16],cost[16],a[16][10005];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int a,int b){
	int sa=find(a),sb=find(b);
	fa[sa]=sb;
}
int check(int S){
	memcpy(p,bp,sizeof(p));
	cnt=bcnt;
	int cw=0;
	for(int i=1;i<=k;i++)
		if(S&(1ll<<(i-1))) w[++cw]=i;
	for(int i=1;i<=cw;i++)
		for(int j=1;j<=n;j++)
			p[++cnt]=edge{i+n,j,a[w[i]][j]};
	for(int i=1;i<=n+cw;i++) fa[i]=i;
	sort(p+1,p+cnt+1,cmp);
	int ans=0,gs=0;
	for(int i=1;i<=cnt;i++)
		if(find(p[i].u)!=find(p[i].v)){
			merge(p[i].u,p[i].v);
			ans+=p[i].w;
			if(gs==n+cw-1) break;
		}
	for(int i=1;i<=cw;i++) ans+=cost[w[i]];
	return ans;
}
signed main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	//LL!
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		bp[++bcnt]=edge{u,v,w};
	}
	for(int i=1;i<=k;i++){
		cin>>cost[i];
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	}
	ans=1e18;
	for(int S=0;S<(1ll<<k);S++){
		ans=min(ans,check(S));
	}
	cout<<ans;
	return 0;
}
/*
O(2^k m log m) 
*/