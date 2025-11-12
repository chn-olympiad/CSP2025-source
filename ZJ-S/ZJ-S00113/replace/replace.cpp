#include <bits/stdc++.h>

#define int long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))

constexpr int N = 2e5 + 10, M = 5e6 + 10, maxn = 5e6, m1 = 998244853, m2 = 1e9 + 7;
int n, q; 
std::string s1[N], s2[N]; 
int p1[M], p2[M], lenl[N], lenr[N], lenmid[N]; 
void init() {
	p1[0] = p2[0] = 1ll;
	for (int i = 1; i <= maxn; ++i) {
		p1[i] = p1[i - 1] * 27ll % m1;
		p2[i] = p2[i - 1] * 27ll % m2; 
	}
}
int hl1[N], hl2[N], hr1[N], hr2[N];
int hfi1[M], hfi2[M], hse1[M], hse2[M]; 
int t11[M], t12[M], t21[M], t22[M]; 

signed main() {
	freopen("replace.in", "r", stdin), freopen("replace.out", "w", stdout);
	std::ios::sync_with_stdio(false), std::cin.tie(nullptr), std::cout.tie(nullptr);

	std::cin >> n >> q;
	init(); 
	for (int i = 1; i <= n; ++i) {
		std::cin >> s1[i] >> s2[i];
		int l = 0; // the last same bit
		for (int j = 0; j < (int)s1[i].length(); ++j)	
			if (s1[i][j] != s2[i][j]) break ;
			else ++l;
		int r = 0; 
		for (int j = (int)s1[i].length() - 1; j >= 0; --j)
			if (s1[i][j] != s2[i][j]) break ; 
			else ++r; 
		lenl[i] = l, lenr[i] = r;
		int h1 = 0, h2 = 0;
		// same [0, l - 1]
		for (int j = 0; j < l; ++j)	h1 = (h1 * 27ll + s1[i][j] - 'a' + 1) % m1, h2 = (h2 * 27ll + s1[i][j] - 'a' + 1) % m2;
		hl1[i] = h1, hl2[i] = h2;
		h1 = h2 = 0; 
		// same [len - r, len - 1]
		for (int j = (int)s1[i].length() - r; j < (int)s1[i].length(); ++j) 
			h1 = (h1 * 27ll + s1[i][j] - 'a' + 1) % m1, h2 = (h2 * 27ll + s1[i][j] - 'a' + 1) % m2;
		hr1[i] = h1, hr2[i] = h2;
		lenmid[i] = (int)s1[i].length() - l - r;
		int h_1_1 = 0, h_1_2 = 0;
		int h_2_1 = 0, h_2_2 = 0; 
		for (int j = l; j < (int)s1[i].length() - r; ++j) {
			h_1_1 = (h_1_1 * 27ll + s1[i][j] - 'a' + 1) % m1;
			h_1_2 = (h_1_2 * 27ll + s1[i][j] - 'a' + 1) % m2;
			h_2_1 = (h_2_1 * 27ll + s2[i][j] - 'a' + 1) % m1;
			h_2_2 = (h_2_2 * 27ll + s2[i][j] - 'a' + 1) % m2;
		}
		hfi1[i] = h_1_1, hfi2[i] = h_1_2; // hash of mid fi
		hse1[i] = h_2_1, hse2[i] = h_2_2; // hash of mid se
	}
	while (q --> 0) {
		std::string t1, t2; std::cin >> t1 >> t2;
		t11[0] = t12[0] = t21[0] = t22[0] = 0;
		for (int i = 0; i < (int)t1.length(); ++i) {
			t11[i] = (t11[max(0, i - 1)] * 27ll + t1[i] - 'a' + 1) % m1;
			t12[i] = (t12[max(0, i - 1)] * 27ll + t1[i] - 'a' + 1) % m2;
			t21[i] = (t21[max(0, i - 1)] * 27ll + t2[i] - 'a' + 1) % m1;
			t22[i] = (t22[max(0, i - 1)] * 27ll + t2[i] - 'a' + 1) % m2;
		}
		int l = 0, r = 0;
		for (int i = 0; i < (int)t1.length(); ++i)
			if (t1[i] == t2[i]) ++l;
			else break ;
		for (int i = (int)t1.length() - 1; i >= 0; --i)
			if (t1[i] == t2[i]) ++r;
			else break ;
		// same [0, l - 1] [len - r, len - 1]
		int L = l, R = (int)t1.length() - r - 1; // [L, R] means the different
		int hfi_1 = 0, hfi_2 = 0, hse_1 = 0, hse_2 = 0;
		if (L == 0) { // the left is empty
			hfi_1 = t11[R], hfi_2 = t12[R], hse_1 = t21[R], hse_2 = t22[R]; 
		}
		else {
			hfi_1 = (t11[R] - 1ll * t11[L - 1] * p1[R - L + 1] % m1 + m1) % m1;
			hfi_2 = (t12[R] - 1ll * t12[L - 1] * p2[R - L + 1] % m2 + m2) % m2;
			hse_1 = (t21[R] - 1ll * t21[L - 1] * p1[R - L + 1] % m1 + m1) % m1;
			hse_2 = (t22[R] - 1ll * t22[L - 1] * p2[R - L + 1] % m2 + m2) % m2;
		}
		int ans = 0;
		for (int i = 1; i <= n; ++i) {
			// for mid
			if (lenmid[i] != R - L + 1 || hfi_1 != hfi1[i] || hfi_2 != hfi2[i] || hse_1 != hse1[i] || hse_2 != hse2[i]) continue ; 
			int H1, H2; 
			if (lenl[i] > L || lenr[i] > (int)t1.length() - 1 - ((int)t1.length() - r) + 1) continue ; 
			// for L
			if (l <= 0) H1 = H2 = 0; 
			else {
				int len = lenl[i];
				H1 = (t11[L - 1] - 1ll * t11[L - len - 1] * p1[len] % m1 + m1) % m1; 
				H2 = (t12[L - 1] - 1ll * t12[L - len - 1] * p2[len] % m2 + m2) % m2; 
			}
			if (H1 != hl1[i] || H2 != hl2[i]) continue ; 
			// for R
			if (r <= 0) H1 = H2 = 0;
			else {
				int len = lenr[i], ed = (int)t1.length() - 1; 
				H1 = (t11[ed] - t11[ed - len] * p1[len] % m1 + m1) % m1;
				H2 = (t12[ed] - t12[ed - len] * p2[len] % m2 + m2) % m2; 	
			}
			if (H1 != hr1[i] || H2 != hr2[i]) continue ;
			++ans; 
//			std::cout << i << "debug\n"; 
		}
		std::cout << ans << "\n"; 
	}
	return 0;
}

