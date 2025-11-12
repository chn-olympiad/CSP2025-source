#include <bits/stdc++.h>
#define lb(x) (x&-x)
using namespace std;

/*
T2疑似最小生成树
考虑J=10
于是最多有1024种情况
每种情况跑一遍最小生成树，复杂度（2^10 * M *LOG M）
=2E10似乎卡常也能过?
考虑更好的做法？

一种72分做法：对于性质A，最小生成树，
其他情况，状压后最小生成树

疑似正解：
先将所有乡村和原本的道路花费分别排序

状压枚举状态后维护J个指针，模拟优先队列
时间复杂度O(M * log M + 2^10 * M  *10 * log 10 )
-----------------------------
题目理解错了
对于不用考虑村庄的16分
直接最小生成树
考虑性质A
因为村庄A J I=0，直接相连后，还是最小生成树
于是拿到44分，再考虑怎么讲特殊情况变为性质A
疑似正解:
考虑将所有村庄的最小路加上最小花费视为启用村庄的花费
再将上面看错题目的思路带入

先将所有乡村和原本的道路花费分别排序

状压枚举状态后维护J个指针，模拟优先队列
时间复杂度O(M * log M + 2^10 * M  *10 * log 10 )
CODE TIME ：1H15MIN
流程：
先预处理，将道路排序，再枚举村庄选择状态，更具每个状态跑一遍最小生成树
*/

//struct node {
//	int c, v;
//	friend bool operator<(node a, node b) {
//		return a.v > b.v;
//	}
//};
const int M = 1e6 + 5, N = 1e4 + 15;
int n, m, k, fa[N], cnt, t[15], d[2500], out = INT_MAX, ans, a[15], pf[15], now, num;
pair<int, int>c[15][M];

int find(int a) {
	return fa[a] == a ? a : fa[a] = find(fa[a]);
}

void uni(int a, int b) {
	int x = find(a), y = find(b);
	fa[x] = fa[y];
	return;
}

struct node {
	int p_1, p_2, v;
	friend bool operator<(node a, node b) {
		return a.v < b.v;
	}
} rode[M];

int choose(int op, int &a, int &b) {
	if (op == 0) {
		while (find(rode[pf[0]].p_1) == find(rode[pf[0]].p_2))
			pf[0]++;
		a = rode[pf[0]].p_1;
		b = rode[pf[0]].p_2;
		return rode[pf[0]].v;
	} else {
		while (find(c[t[op]][pf[op]].second) == find(t[op] + n) )
			pf[op]++;
		a = c[t[op]][pf[op]].second;
		b = t[op] + n;
		return c[t[op]][pf[op]].first;
	}
}

void work(int f) {
	num = 0;
//	cout << f << " ";
	ans = 0;
	memset(t, 0, sizeof(t));
	while (f) {
		int l = lb(f);
		t[++num] = d[l];
		f ^= l;
	}
//	cout << num << "'";
	pf[0] = 1;
	for (int i = 1; i <= n + 10; i++)
		fa[i] = i;
	for (int i = 1; i <= num; i++) {
		if (num == 0)
			break;
		pf[t[i]] = 2;
		ans += c[t[i]][1].first + a[t[i]];
		uni(n + t[i], c[t[i]][1].second);
	}
//	cout << "!";
	for (int i = 1, x, y, a, b, res = INT_MAX; i < n; i++) {
		res = choose(0, x, y);
		for (int j = 1; j <= num; j++) {
			if (num == 0)
				break;
			now = choose(j, a, b);
			if (now < res) {
				res = now;
				x = a;
				y = b;
			}
//			cout << j;
		}
		ans += res;
//		cout << "?";
		int aa = x, bb = y;
//		cout << "+" << aa << " " << bb << endl;
		uni(aa, bb);
//		cout << "p";
	}
//	cout << "!";
	out = min(out, ans);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	for (int i = 0; i < 10; i++)
		d[1 << i] = i + 1;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, a, b, c; i <= m; i++) {
		scanf("%d%d%d", &a, &b, &c);
		rode[++cnt].p_1 = a;
		rode[cnt].p_2 = b;
		rode[cnt].v = c;
	}
	sort(rode + 1, rode + 1 + cnt);
//	for (int i = 1; i <= m; i++)
//		cout << rode[i].v << " " << rode[i].p_2 << " " << rode[i].p_1 << endl;
	for (int i = 1; i <= k; i++) {
		scanf("%d", &a[i]);
		for (int j = 1; j <= n; j++) {
			c[i][j].second = j;
			scanf("%d", &c[i][j].first);
		}
		sort(c[i] + 1, c[i] + 1 + n);
//		for (int j = 1; j <= n; j++)
//			cout << c[i][j].first << " " << c[i][j].second << endl;
	}

	for (int i = 0; i < (1 << k); i++)
		work(i);
	printf("%d", out);
	return 0;
}