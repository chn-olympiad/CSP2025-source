#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

namespace PTqwq {
	
int readqwq() {
	int x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

ll readllqwq() {
	ll x = 0;
	bool f = false;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar()) f |= (c == '-');
	for (; c >= '0' && c <= '9'; c = getchar()) x = (x << 1) + (x << 3) + (c - '0');
	if (f) {
		x = -x;
	}
	return x;
}

const int N = 1e5 + 50;

ll a[N][3], curD[N];
int n, cnt[3], ord[32], curA[N], curB[N];
ll st[N];

void solveQ() {
	n = readqwq();
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j < 3; ++ j) {
			a[i][j] = readllqwq();
		}
	}
	for (int i = 1; i <= n; ++ i) {
		ord[1] = 0;
		ord[2] = 1;
		ord[3] = 2;
		sort(ord + 1, ord + 1 + 3, [&](int u, int v) {
			return a[i][u] > a[i][v];
		});
		curD[i] = a[i][ord[1]] - a[i][ord[2]];
		curA[i] = ord[1];
		curB[i] = ord[2];
	}
	
	for (int i = 0; i < 3; ++ i) {
		cnt[i] = 0;
	}
	ll ans = 0;
	for (int i = 1; i <= n; ++ i) {
		cnt[curA[i]] ++;
		ans += a[i][curA[i]];
	}
	for (int i = 0; i < 3; ++ i) {
		if (cnt[i] > n / 2) {
			int siz = 0;
			for (int j = 1; j <= n; ++ j) {
				if (curA[j] == i) {
					st[++ siz] = curD[j];
				}
			}
			int curC = cnt[i] - n / 2;
			if (siz >= 1) {
				sort(st + 1, st + 1 + siz);
				for (int j = 1; j <= siz && j <= curC; ++ j) {
					ans -= st[j];
				}
			}
			break;
		}
	}
	printf("%lld\n", ans);
}

void Solve() {
	int T = readqwq();
	for (int i = 1; i <= T; ++ i) {
		solveQ();
	}
}

}

int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	PTqwq::Solve();

	return 0;
}
