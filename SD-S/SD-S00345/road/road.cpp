/*
弄不死就往死里弄！
不要放弃任何一点分！
先写暴力！发掘特殊性质！
读题读题读题！
int <-> long long 数组大小！ MLE?RE?
图论？DP？
优化一下？
*/

#include <bits/stdc++.h>

#define int long long 

using namespace std;

const int N=1e4+10;
const int M=1e6+10;
const int K=20;

struct Edge{
	int u,v,w;
};

int n,m,k;
int fa[N+K];
bool chosen;
Edge e[M+K*N];//注意边数，可能不是k 
int cnt;//注意要把m算上
int ans=0; 
int c[K];
int a[K][N];
int node_cnt;

int findgen(int p) {
	return (fa[p]==p)?p:fa[p]=findgen(fa[p]);
}

bool cmp(const Edge& ed1,const Edge& ed2) {
	return ed1.w<ed2.w;
}
 
void dfs(int chosen,int stp,int res) {//res是目前的基准边 
	if(chosen==k+1) {
		return;
	}
	if(stp==n+1) return;
	//剩下的挨个跑kruscal
	//先考虑有没有新的连边，如果有的话再次连，否则就什么都不用算，减少枚举量
	if(stp<=k) {
		if(chosen+1>k);
		else {	//前k个可以选
			if(k==0) {
				cout<<ans<<"\n";
				exit(0);
			}
			res+=c[stp];//算上 
			node_cnt++;
			for(int i=1;i<=n;++i) fa[i]=i; 
			//加边，算上基准量
			int rcnt=cnt;
			for(int i=1;i<=n;++i) {
				e[++cnt].u=node_cnt;e[cnt].v=i;e[cnt].w=a[stp][i];
			} 
			int tmp=0;
			sort(e+1,e+cnt+1,cmp);
			for(int i=1;i<=cnt;++i) {
				int u=findgen(e[i].u),v=findgen(e[i].v);
				//if(e[i].u==e[i].v) tmp+=e[i].w;
				if(u==v) continue;
				fa[u]=v;
				tmp+=e[i].w;
				if(tmp+res>ans) break;
			}
	//		cout<<tmp+res<<" "<<stp<<"\n";
			ans=min(ans,tmp+res);
			dfs(chosen+1,stp+1,res);
			res-=c[stp];
			cnt=rcnt;
			node_cnt--;
		}
	}
	dfs(chosen,stp+1,res);
}

void readin() {
	cin>>n>>m>>k;
	for(int i=1;i<=m;++i) {
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	cnt=m;
	node_cnt=n;
	for(int i=1;i<=k;++i) {
		cin>>c[i];
		for(int j=1;j<=n;++j) {
			cin>>a[i][j];
		}
	}
}

void preprocess() {
	//先来一遍kruscal
	for(int i=1;i<=n;++i) {
		fa[i]=i;
	}
	sort(e+1,e+cnt+1,cmp);
	for(int i=1;i<=cnt;++i) {
		int u=findgen(e[i].u),v=findgen(e[i].v);
		if(u==v) continue;
		fa[u]=v;
		ans+=e[i].w;
	}
}

void output() {
	cout<<ans<<"\n";
}

signed main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	readin();
	preprocess();
	dfs(1,1,0);
	output();
	return 0;
}
