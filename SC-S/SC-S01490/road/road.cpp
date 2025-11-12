#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int lowbit(int x) {
	return x&(-x);
}

const int N = 1e4+50;
const int M = 1e6+50;

int n,m,k;
int c[15];
int a[15][N];

struct Edge {
	int a,b,v;
}edge[M*2],edge2[M];
int tot;

int ans = 1e9;

bool cmp(Edge a,Edge b) {
	return a.v < b.v;
}

struct Node {
	int se,fa;
}node[N];

int fd(int p) {
	if(node[p].fa != p) node[p].fa = fd(node[p].fa);
	return node[p].fa;
}

int merge(int a,int b) {
	a = fd(a);
	b = fd(b);
	if(a==b) return 1;
	if(node[a].se < node[b].se) swap(a,b);
	node[b].fa = a;
	node[a].se += node[b].se;
	return 0;
}

int sc(int x) {
	sort(edge+1,edge+1+tot,cmp);
	int cnt = x;
	for(int i = 1;i <= n;++i) {
		node[i].fa = i;
		node[i].se = 1;
	}
	for(int j = 1;j <= tot;++j) {
		int a = edge[j].a;
		int b = edge[j].b;
		int v = edge[j].v;
		if(merge(a,b) == 0) cnt += v;
	}
	return cnt;
}

int main () {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin >> n >> m >> k;
	for(int i = 1;i <= m;++i) cin >> edge2[i].a >> edge2[i].b >> edge2[i].v;
	for(int i = 1;i <= k;++i) {
		cin >> c[i];
		for(int j = 1;j <= n;++j) {
			cin >> a[i][j];
		}
	}
	
	for(int i = 1;i <= m;++i) edge[i] = edge2[i];
	tot = m;
	
	for(int i = 0;i < (1<<(k-1));++i) {
		int j = i;
		int s = n;
		int sum = 0;
		int t = 1;
		while(j) {
			if(j&1) {
				++s;
				for(int p = 1;p <= n;++p) {
					edge[p+tot].a = s;
					edge[p+tot].b = p;
					edge[p+tot].v = a[t][p];
				}
				tot += n;
				sum += c[t];
			}
			j >>= 1;
			++t;
		}
		ans = min(sc(sum),ans);
		for(int i = 1;i <= m;++i) edge[i] = edge2[i];
		tot = m;
	}
	//ans = sc(0);
	cout << ans;
	return 0;
}