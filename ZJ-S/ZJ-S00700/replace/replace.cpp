#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <cstring>
using namespace std;

using ull = unsigned long long;

const int N = 2e5 + 10, M = 5e6 + 10, K = 26;
const ull base = 13331;

int n, q;
string s1[N], s2[N];
char buf[M], buf1[M];
ull pw[M], ha[M];

inline ull G(ull x) {
	return x * x * x + x * 736 + 520;
}
inline ull F(ull x) {
	x ^= x << 3, x ^= x >> 7;
	return G(x >> 16) + x * G(x ^ x << 17);
}
ull w[K][K], SEED = 736520;

unordered_map<ull, int> ecnt, sum;

inline ull W(char a, char b) {
	return w[a - 'a'][b - 'a']; // b - 'b'......
}

inline ull gethash(int l, int r) {
	return ha[r] - ha[l - 1] * pw[r - l + 1];
}

int main() {
#ifndef XuYueming
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
#endif
	pw[0] = 1;
	for (int i = 1; i < M; ++i) {
		pw[i] = pw[i - 1] * base;
	}
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < K; ++j)
			w[i][j] = SEED = F(SEED);
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; ++i) {
		scanf("%s", buf), s1[i] = string(buf);
		scanf("%s", buf), s2[i] = string(buf);
		int m = s1[i].size();
		ull h = 0;
		for (int j = 1; j <= m; ++j) {
			h = h * base + W(s1[i][j - 1], s2[i][j - 1]);
		}
		++ecnt[h];
	}
	sum[0] = 0;
	for (int i = 1; i <= n; ++i) {
		int m = s1[i].size();
		ull h = 0;
		for (int j = 1; j <= m; ++j) {
			ull th = h * base + W(s1[i][j - 1], s2[i][j - 1]);
			sum[th] = sum[h] + ecnt[th];
			h = th;
//			printf("th = %llu, i = %d, j = %d\n", th, i, j);
		}
	}
	unordered_map<ull, int>().swap(ecnt);
	for (int qi = 1; qi <= q; ++qi) {
		scanf("%s%s", buf + 1, buf1 + 1);
		int m = strlen(buf + 1), m1 = strlen(buf1 + 1);
		if (m != m1) {
			puts("0");
			continue;
		}
		int l = 0, r = 0;
		for (int i = 1; i <= m; ++i) {
			if (buf[i] != buf1[i]) {
				r = i;
				if (l == 0) l = i;
			}
		}
		if (l == 0) {
			puts("ERR");
			exit(1);
		}
		for (int i = 1; i <= m; ++i) {
			ha[i] = ha[i - 1] * base + W(buf[i], buf1[i]);
		}
		long long Ans = 0;
		for (int i = 1; i <= l; ++i) {
			if (sum.count(gethash(i, r - 1))) {
				int L = 1, R = m - r + 1, mid, ans = 0;
				while (L <= R) {
					mid = (L + R) >> 1;
					if (sum.count(gethash(i, r + mid - 1)))
						ans = mid, L = mid + 1;
					else
						R = mid - 1;
				}
//				if (!sum.count(gethash(i, r + ans - 1))) {
//				}
				if (ans) {
					Ans += sum[gethash(i, r + ans - 1)] - sum[gethash(i, r - 1)];
//					printf("i = %d, ans = %d, += %d, %d\n", i, ans, sum[gethash(i, r + ans - 1)] - sum[gethash(i, r - 1)], sum[gethash(2, 4)]);
//					printf("    %llu\n", gethash(2, 4));
				}
			}
		}
//		printf("l = %d, r = %d\n", l, r);
		printf("%lld\n", Ans);
	}
	return 0;
}
