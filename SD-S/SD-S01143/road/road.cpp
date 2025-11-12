#include<bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
#define pb push_back
using namespace std;
typedef pair<int, int> pii;
const int N = 1e4 + 29;
const int M = 2e6 + 29;

int n, m, k, ans, tot;
int a[N], fa[N];
struct node {
	int a, b, w;
} e[M];

bool cmp(node x, node y) {
	return x.w < y.w;	
}

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	fa[fy] = fx;
}

void tbcsolve() {
	cin >> n >> m >> k;
//	memset(minn, 0x3f, sizeof minn);
	rep (i, 1, m) cin >> e[i].a >> e[i].b >> e[i].w;	
	int cnt = m;
	rep (i, n + 1, n + k) {
		int c; cin >> c;
		rep (j, 1, n) {
			cin >> e[++cnt].w;
			e[cnt].a = j;
			e[cnt].b = i;
		}
	}
	n += k;
	sort(e + 1, e + 1 + cnt, cmp);
	rep (i, 1, n) fa[i] = i;
	rep (i, 1, cnt) {
		int u = e[i].a, v = e[i].b, w = e[i].w;
		if (find(u) == find(v)) continue;
		merge(u, v);
		ans += w;
		if (++tot >= n - 1) break;
	}
	cout << ans << '\n';
}

signed main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int SHEN = 1;
//	cin >> SHEN;
	while (SHEN--) {
		tbcsolve();
	}
	return 0;
}
/*
15:32 读完题，这不就是 kruskal 板子吗？！！
15:41 写一半了感觉不太对劲。。。决定重构写特殊性质 A，感觉可以用并查集 
15:43 刚删掉代码突然又有了正解思路。。。Ctrl+Z。。。 
16:05 码完了，但 WA 样例 1 
16:09 题面好阴间，发现样例里城市化改造后的 1 还要和自己建设一条道路 
16:12 哦我去理解错题面了。。要重新理解了。。。跟去年的 T2 一样的题面抽象。。
16:26 决定改成朴素的 kruskal 先拿下特殊性质 A 和 k == 0 的 48pts 
16:30 孩子们我没招了我修路花费的比答案少。。。 
16:39 没输出了。。。 
16:44 上了个厕所，吃了个薄荷糖，开始手搓样例 
16:50 下标从 m 往后越界了。。现在应该没什么问题了 
*/ 
