#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e4+4,maxm=1e6+5;
int n,m,k,ff,tot,cnt,ans,aaa=INT_MAX;
int f[maxn],c[maxn],vis[maxn];
struct node {
	int u,v,w;
} e[maxm*2];
int mp[15][maxn];
bool cmp(node a,node b) {
	return a.w<b.w;
}
int find(int x) {
	return f[x]==x?x:f[x]=find(f[x]);
}
int kru() {
	sort(e+1,e+m+1,cmp);
	for(int i=1; i<=n; i++) {
		f[i]=i;
	}
	int ans=0,sum=0;
	for(int i=1; i<=m; i++) {
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy) {
			f[fx]=fy;
			sum++;
			ans+=e[i].w;
			if(sum==n-1) {
				return ans;
			}
		}
	}
	return 0;
}
void cru() {
	sort(e+1,e+tot+1,cmp);
	for(int i=1; i<=cnt; i++) {
		f[i]=i;
	}
	int sum=0;
	for(int i=1; i<=tot; i++) {
		int fx=find(e[i].u);
		int fy=find(e[i].v);
		if(fx!=fy) {
			f[fx]=fy;
			sum++;
			ans+=e[i].w;
			if(sum==cnt-1) {
				aaa=min(aaa,ans);
				for(int j=1; j<=tot; j++) {
					if(e[j].u>n) {
						e[j].w=1000000007;
					}
				}
				sort(e+1,e+tot+1,cmp);
				return;
			}
		}
	}
}
void dfs(int x) {
	if(x==k+1) {
		tot=m;
		cnt=n;
		ans=0;
		for(int i=1; i<=k; i++) {
			if(vis[i]) {
				cnt++;
				ans+=c[i];
			}
			for(int j=1; j<=n; j++) {
				if(vis[i]) {
					e[++tot]= {cnt,j,mp[i][j]};
				}
			}
		}
		cru();
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL),cout.tie(NULL);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	if(!k) {
		cout<<kru()<<"\n";
		return 0;
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		if(c[i]!=0) {
			ff=1;
		}
		int fff=0;
		for(int j=1; j<=n; j++) {
			cin>>mp[i][j];
			if(!mp[i][j]) {
				fff=1;
			}
		}
		if(!fff) {
			ff=1;
		}
	}
	if(!ff) {
		int q=n;
		for(int i=1; i<=k; i++) {
			q++;
			for(int j=1; j<=n; j++) {
				e[++m]= {q,j,mp[i][j]};
			}
		}
		n=q;
		cout<<kru()<<"\n";
		return 0;
	}
	dfs(1);
	cout<<aaa<<"\n";
}
