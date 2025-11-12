#include<bits/stdc++.h>
using namespace std;
const int N=1e4+16;
int father[N];
int find(int x) {
	if (father[x]==x) return x;
	return father[x]=find(father[x]);
}
bool unionset(int x,int y) {
	int fx=find(x),fy=find(y);
	if (fx!=fy) {
		father[fx]=fy;
		return 1;
	}
	return 0;
}
struct Node {
	int u,v;
	long long w;
	bool operator<(const Node& other) const {
		return w>other.w;
	}
};
priority_queue<Node> q;
long long vis[16];
long long c[16],a[16][N];
bool visited[N];
int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for (long long i=1,u,v,w; i<=m; i++) {
		scanf("%d%d%lld",&u,&v,&w);
		q.push(Node {u,v,w});
	}
	for (long long i=1; i<=k; i++) {
		scanf("%lld",&c[i]);
		for (int j=1; j<=n; j++) {
			scanf("%lld",&a[i][j]);
			q.push(Node {n+i,j,c[i]+a[i][j]});
		}
	}
	for (int i=1; i<=n+k; i++) father[i]=i;
	long long res=0;
	int cnt=0;
	while (q.size()) {
		Node t=q.top();
		q.pop();
		if (unionset(t.u,t.v)) {
			res+=t.w;
			if (t.u<=n) {
				if (!visited[t.u]) {
					visited[t.u]=1;
					cnt++;
				}
				if (t.v<=n) {
					if (!visited[t.v]) {
						visited[t.v]=1;
						cnt++;
					}
				} else {
					if (vis[t.v-n]) visited[t.v]=1;
					else {
						vis[t.v-n]=t.w;
						if (c[t.v-n]) {
							for (int i=1; i<=n; i++) {
								if (!visited[i]) {
									q.push(Node {t.v,i,a[t.v-n][i]});
								}
							}
						}
					}
				}
			} else {
				if (vis[t.u-n]) visited[t.u]=1;
				else {
					vis[t.u-n]=t.w;
					if (c[t.u-n]) {
						for (int i=1; i<=n; i++) {
							if (!visited[i]) {
								q.push(Node {t.u,i,a[t.u-n][i]});
							}
						}
					}
				}
			}
			if (cnt==n) break;
		}
	}
	for (int i=1; i<=k; i++) {
		if (!visited[n+i]) res-=vis[i];
	}
	printf("%lld",res);
	return 0;
}

