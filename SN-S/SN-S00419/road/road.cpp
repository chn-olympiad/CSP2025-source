#include <bits/stdc++.h>
#define Maxm 1110005
#define Maxn 11005
#define Maxnum 1030

using namespace std;

int n, m, k, A, B, C, S;
int num, tot, st[Maxnum], top;
int cst[15], a[15][Maxn], fa[Maxn];
long long res = 0, minl, ans[Maxnum];
struct Node {
	int x, y, v;
	bool operator <(const Node &a) const {
		return v < a.v;
	}
} p[Maxm], e[Maxm];

int find(int x) {
	return ((fa[x] == x) ? x : (fa[x] = find(fa[x])));
}

void build(int S) {
	res = 0, num = n;
	for (int i = 1; i <= m; i ++) {
		e[i] = p[i];
	} tot = m;
	for (int i = 1; i <= k; i ++) {
		if (!(S & (1 << (i - 1)))) {
			continue;
		}
		
		res += cst[i], num ++;
		for (int j = 1; j <= n; j ++) {
			tot ++, e[tot].v = a[i][j];
			e[tot].x = num, e[tot].y = j;
		}
	}
	
	sort(e + 1, e + tot + 1);
	for (int i = 1; i <= num; i ++) {
		fa[i] = i;
	} num --;
	int fax = 0, fay = 0;
	for (int i = 1; i <= tot; i ++) {
		fax = find(e[i].x), fay = find(e[i].y);
		if (fax == fay) { continue; }
		res += e[i].v, fa[fax] = fay, num --;
		if (!num) { break; }
	} minl = min(minl, ans[S] = res);
}

int main() {
	freopen("road.in", "r", stdin);
	freopen("road.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 1; i <= m; i ++) {
		cin >> A >> B >> C;
		p[i].x = A, p[i].y = B, p[i].v = C;
	}
	
	for (int i = 1; i <= k; i ++) {
		cin >> cst[i];
		for (int j = 1; j <= n; j ++) {
			cin >> a[i][j];
		}
	}
	
	minl = 1e15;
	for (int S = 0, fl = 0; S <= (1 << k) - 1; S ++) {
		fl = 0;
		for (int i = 1; i <= top; i ++) { if ((S - st[i]) == (S ^ st[i])) { fl = 1; break; } }
		if (fl) { continue; } build(S);
		for (int i = 1; i <= k; i ++) {
			if ((S & (1 << (i - 1))) && ans[S ^ (1 << (i - 1))] <= ans[S]) {
				st[++ top] = S;
				break;
			}
		}
	} cout << minl;
	return 0;
}
