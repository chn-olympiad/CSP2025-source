#include <bits/stdc++.h>
#define int long long
using namespace std;
inline int read() {
	char ch = getchar();
	int f = 1, x = 0;
	while(!isdigit(ch)) {if(ch == '-') f = -f; ch = getchar();}
	while(isdigit(ch)) {x = x * 10 + ch - '0'; ch = getchar();}
	return f * x;
} 
inline void write(int x) {
	if(x < 0) putchar('-'), x = -x;
	if(x >= 10) write(x / 10);
	putchar(x % 10 + '0');
}
const int N = 1e6 + 1e5 + 10;
const int M = 1e4 + 10;
int n, m, k, cnt_edge = 0, w[M], mv = 0, ans = 0, c[M], a[12][M];
struct edge{
	int from, to, w;
	bool operator < (const edge &other) const {
		return w < other.w;
	}
} edges[N];
struct disjset{
	int s[M];
	void init(int n) {for(int i = 1; i <= n; i++) s[i] = i;}
	int find(int x) {return s[x] == x ? x : s[x] = find(s[x]);}
	void merge(int l, int r) {s[find(l)] = find(r);}
} st;
edge edges2[N];
void kruskal(int cse) {
	for(int i = 1; i <= cnt_edge; i++) edges2[i] = edges[i];
	ans = 0;
	sort(edges2 + 1, edges2 + cnt_edge + 1);
	st.init(n + k);
	int cnt = 0;
	for(int i = 1; i <= cnt_edge && cnt < cse - 1; i++) {
		if(st.find(edges2[i].from) != st.find(edges2[i].to)) {
			st.merge(edges2[i].from, edges2[i].to);
			ans += edges2[i].w;
			cnt++;
		}
	}
}
signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	n = read(); m = read(); k = read();
	for(int i = 1; i <= m; i++) {
		cnt_edge++;
		edges[cnt_edge].from = read();
		edges[cnt_edge].to = read();
		edges[cnt_edge].w = read();
	}
	if(k == 0) {//先用板子得16分再说 
		kruskal(n);
		write(ans);
		return 0;
	}
	bool A = true;//是否满足性质A 
	for(int i = 1; i <= k; i++) {
		c[i] = read();
		if(c[i] != 0) A = false;
		for(int j = 1; j <= n; j++) {
			a[i][j] = read();
		}
	}
	if(A) {
		//毕竟建点的花费是0，也有一条0的连边可以通达，索性全建了，全连了 
		for(int i = 1; i <= k; i++) {
			for(int j = 1; j <= n; j++) {
				edges[++cnt_edge] = {n + i, j, a[i][j]};
			}
		}
		kruskal(n + k);
		write(ans);
	} else {//之前得到 48 分了 
		//O(km log m)感觉要T 
		bool build[12];
		memset(build, false, sizeof(build));
		kruskal(n);
		int base = ans, mb = 0;
		cnt_edge += n;
		for(int i = 1; i <= k; i++) {
			//如果加上这个点可以让总和变得更小，就建这个城镇。
			cnt_edge -= n;
			for(int j = 1; j <= n; j++) {
				edges[++cnt_edge] = {n + i, j, a[i][j]};
			}
			kruskal(n + 1);
			int now = ans + c[i];
			if(now < base) {
				build[i] = true;
				mb++;
			}
		}
		cnt_edge -= n;
		int ret = 0;
		for(int i = 1; i <= k; i++) {
			if(build[i]) {
				ret += c[i];
				for(int j = 1; j <= n; j++) edges[++cnt_edge] = {n + i, j, a[i][j]};
			}
		}
		kruskal(n + mb);
		ret += ans;
		write(ret); 
	} 
	return 0;
}
