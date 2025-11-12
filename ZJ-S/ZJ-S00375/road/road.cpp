#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
struct node {
	int u,v,w;
	bool operator<(const node&a)const {
		return w>a.w;
	}
};
priority_queue<node> q;
priority_queue<node> qtmp;
void add(int u,int v,int w) {	
	node tmp;
	tmp.u=u,tmp.v=v,tmp.w=w;
	q.push(tmp);
}
int cost[15][N];
int cost_p[15];
int fa[N];
int fin(int x) {
	if(x==fa[x]) return x;
	else return fa[x]=fin(fa[x]);
}
int scs(int pcnt) {
	int ret=0;
	for(int j=1; j<=n+k; j++) {
		fa[j]=j;
	}
	int cnt=0;
	while(!q.empty()) {
		if(cnt==pcnt-1) break;
		int u=q.top().u;
		int v=q.top().v;
		int w=q.top().w;
		q.pop();		
		if(fin(u)==fin(v)) continue;
		cnt++;
		fa[fin(u)]=fin(v);
		ret+=w;
	}	
	return ret;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);	
	cin>>n>>m>>k;
	for(int i=1; i<=m; i++) {
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);		
	}

	for(int i=1; i<=k; i++) {
		cin>>cost_p[i];
		for(int j=1; j<=n; j++) {
			cin>>cost[i][j];
		}
	}
	int ans=1e15;
	qtmp=q;
	for(int i=0; i<(1<<(k)); i++) {
		q=qtmp;
		int res=0;
		int pcnt=0;
		for(int j=1; j<=k; j++) {
			if(((i>>(j-1))&1)) {
				pcnt++;
				res+=cost_p[j];
				for(int l=1; l<=n; l++) {
					add(n+j,l,cost[j][l]);
				}
			}
		}
		res+=scs(pcnt+n);		
		ans=min(ans,res);
	}
	cout<<ans;
}
