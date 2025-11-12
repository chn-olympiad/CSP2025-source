#include <iostream>
using namespace std;

const int N = 1e7, M = 500001;

int n, k;
int son[N][2], idx = 0;
int ms[N];
int l[M], f[M];

void insert(int x, int id) {
	int p = 0;
	for (int i = 20; i >= 0; i--) {
		int u = x >> i & 1;
		if (!son[p][u]) son[p][u] = ++idx;
		p = son[p][u];
		ms[p] = id;
	}
}

int query(int x) {
	int p = 0;
	for (int i = 20; i >= 0; i--) {
		int u = x >> i & 1, v = k >> i & 1;
		if (!son[p][v ^ u]) return -1;
		p = son[p][v ^ u];
	}
	return ms[p];
}

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	scanf("%d%d", &n, &k);
	int y = 0;
	insert(0, 0);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		y ^= x;
		l[i] = query(y);
		insert(y, i);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1];
		if (l[i] != -1) f[i] = max(f[i], f[l[i]] + 1);
	}
	cout << f[n];
	return 0;
}
