#include <bits/stdc++.h>
using namespace std;
int n;

struct node {
	int a;
	int b;
	int c;
	bool flag = 0;
} g[100005];

int aa, bb, cc;

bool cmp1(node x, node y) {
	if (x.a != y.a )
		return x.a > y.a ;
}

bool cmp2(node x, node y) {
	if (x.b != y.b )
		return x.b > y.b ;
}

bool cmp3(node x, node y) {
	if (x.c != y.c )
		return x.c > y.c ;
}


int sum = 0, maxx = 0;

void ddfs(int k, int y, int z) {
	if (z == 4) {
		maxx = max(maxx, sum);
		return;
	}
	int cnt = 0;
	for (int i = 1; i <= 3; i++) {
		if (i == k || i == y)
			continue;
		if (i == 1) {
			aa = 0;
			sort(g + 1, g + 1 + n, cmp1);
			for (int j = 1; j <= n ; j++) {
				if (aa <= n / 2 && g[j].flag == 0) {
					cnt += g[j].a ;
					g[j].flag = k;
				}
			}
		}
		if (i == 2) {
			bb = 0;
			sort(g + 1, g + 1 + n, cmp2);
			for (int j = 1; j <= n ; j++) {
				if (bb <= n / 2 && g[j].flag == 0) {
					cnt += g[j].b ;
					g[j].flag = k;
				}
			}
		}
		if (i == 3) {
			cc = 0;
			sort(g + 1, g + 1 + n, cmp3);
			for (int j = 1; j <= n ; j++) {
				if (cc <= n / 2 && g[j].flag == 0) {
					cnt += g[j].c ;
					g[j].flag = k;
				}
			}
		}
		sum += cnt;
		ddfs(i, k, z + 1);
		sum -= cnt;
		for (int j = 1; j <= n ; j++) {
			if (g[j].flag == k) {
				g[j].flag = 0;
			}
		}
	}
}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int b;
		cin >> b;
		for (int j = 1; j <= b; j++) {
			cin >> g[i].a >> g[i].b >> g[i].c ;
		}
		ddfs(0, 0, 1);
		cout << maxx << endl;

	}
	return 0;
}