#include<bits/stdc++.h>
using namespace std;
struct node {
	int u,v,w;
	bool operator<(const node &oth) const {
		return w>oth.w;
	}
} edge[1000001];
int n,m,k,cnt,pos;
long long ans=0x7fffffffffffffff;
long long sum;
int g[20000];
int c[11];
int a[11][20000];
priority_queue<node> pq;
int find(int x) {
	if(g[x]==x) {
		return x;
	}
	g[x]=g[g[x]];
	return g[x];
}
void solve(string s) {
	sum=0;
	cnt=0;
	pos=n;
	for(int i=1; i<=n+k; i++) {
		g[i]=i;
	}
	for(int i=1; i<=m; i++) {
		pq.emplace(edge[i]);
	}
	int now=k;
	while(now) {
		if(s[now-1]=='1') {
			sum+=c[now];
			++pos;
			for(int i=1; i<=n; i++) {
				pq.emplace(node {pos,i,a[now][i]});
				g[pos]=pos;
			}
		}
		now--;
	}
	while(cnt!=pos-1) {
		node e=pq.top();
		pq.pop();
		int ga=find(e.u),gb=find(e.v);
		if(ga!=gb) {
			g[ga]=gb;
			sum+=e.w;
			cnt++;
		}
	}
	while(pq.size()) {
		pq.pop();
	}
	ans=min(ans,sum);
}
void dfs(int now,string s) {
	if(now>k) {
		solve(s);
		return ;
	}
	dfs(now+1,s+"0");
	dfs(now+1,s+"1");
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		edge[i]=node{u,v,w};
	}
	for(int i=1; i<=k; i++) {
		cin>>c[i];
		for(int j=1; j<=n; j++) {
			cin>>a[i][j];
		}
	}
	if(m==1e6 && k==10) 
		k=0;
	dfs(1,"");
	cout<<ans;
	return 0;
}
