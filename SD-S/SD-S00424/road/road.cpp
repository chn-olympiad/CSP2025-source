#include<bits/stdc++.h>
#define N 10000005
#define pb push_back
#define ll long long
using namespace std;
int n,m,k,fa[N],p[N],c[11][N];
ll ans=1e18;
vector<int> a[N];
struct node{
	int u,v,w;
	bool operator<(const node& p) {
		return w<p.w;
	}
}he[N],e[N];
int find(int x) {
	return (fa[x]==x?x:fa[x]=find(fa[x]));
}
void solve() {
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++) cin>>e[i].u>>e[i].v>>e[i].w;
	for(int i=1;i<=k;i++) {
		cin>>c[i][0];p[i]=1;
		for(int j=1;j<=n;j++) cin>>c[i][j];
	} sort(e+1,e+m+1);for(int i=1;i<=n;i++) fa[i]=i;
	if(k==0) {
		int s=0;
		for(int i=1;i<=m;i++) {
			int x=find(e[i].u),y=find(e[i].v);
			if(x==y) continue;
			fa[x]=y;
		}
	}
	for(int i=0;i<(1<<k);i++) {
		for(int j=1;j<=m;j++) he[j]=e[j];
		for(int i=1;i<=n+k;i++) fa[i]=i;
		int ct=m;int nn=n;ll s=0;
		for(int j=1;j<=k;j++) {
			if((i>>(j-1))&1) {
				s+=c[j][0];n++;
				for(int x=1;x<=nn;x++) {
					he[++ct]={n,x,c[j][x]};
				}
			} 
		} sort(he+1,he+ct+1); int res=0;
		for(int j=1;j<=ct;j++) {
			int x=find(fa[he[j].u]),y=find(fa[he[j].v]);
			if(x==y) continue;
			s+=he[j].w;fa[x]=fa[y];res++;
			if(res==n-1) break;
		} ans=min(ans,s);n=nn;
	} printf("%lld\n",ans);
}

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);int t=1;
	
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	while(t--) {solve();}
	
	return 0;
} 
