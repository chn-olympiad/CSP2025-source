#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e4+5;
const int M=1e6+5;
int n,m,k;
struct edge {
	int v,w;
};
vector<edge>e[M];
int comp=0;
int rt[N];
vector<vector<int> >cc(N);
ll read() {
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)) {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)) {
		x=(x<<1)+(x<<3)+(ch&15);
		ch=getchar();
	}
	return x*f;
}
void dfs(int x,int root) {
	rt[x]=root;
	cc[root].push_back(x);
	for(int i=0; i<e[x].size(); i++) {
		int j=e[x][i];
		if(rt[j]) continue;
		dfs(j);
	}
}
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	n=read(),m=read(),k=read();
	for(int i=1; i<=m; i++) {
		int u=read(),v=read(),w=read();
		e[u].push_back({v,w});
		e[v].push_back({u,w});
	}

	for(int i=1; i<=n; i++) {
		rt[i]=i;
	}

	for(int i=1; i<=n; i++) {
		if(!rt[i]) {
			dfs(i,++comp);
		}
	}

	if(k==0) {
		//不想玩了。
		//暴力枚举出边
		int totw=0,maxw=-1e9;
		for(int i=1; i<=comp; i++) {
			int from=0,to=0,wgt=INT_MAX;
			for(int j=0; j<cc[comp].size(); j++) {
				int u=cc[comp][j];
				for(int k=0; k<e[u].size(); k++) {
					int v=e[u][k].v,w=e[u][k].w;
					if(w<wgt) {
						wgt=w;
						from=u,to=v;
					}
				}
			}
			tot+=wgt;
			maxw=max(maxw,wgt);
		}
		printf("%d\n",tot-maxw);
	}
	
	
	
	return 0;
}