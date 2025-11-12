#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 5, M = 5e6 + 5;

int n, q, Len[N];

char tmp[M];

string s1[N], s2[N], t1[N], t2[N];

vector <unsigned long long> q1[N], q2[N];

unsigned long long c[M], h1[N], h2[N];

inline unsigned long long query1 (const signed at, const signed l, const signed r) {
	return q1[at][r] - q1[at][l - 1] * c[r - l + 1];
}

inline unsigned long long query2 (const signed at, const signed l, const signed r) {
	return q2[at][r] - q2[at][l - 1] * c[r - l + 1];
}

inline unsigned long long que1 (const signed l, const signed r) {
	return h1[r] - h1[l - 1] * c[r - l + 1];
}

inline unsigned long long que2 (const signed l, const signed r) {
	return h2[r] - h2[l - 1] * c[r - l + 1];
}


struct node {
	signed at, l;
};

unordered_map <unsigned long long, vector <node> > t;

int S[N];

signed main() {
//	system("fc replace.out ans.out");
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	c[0] = 1;
	for (int i = 1; i <= 5e6; ++ i ) c[i] = c[i - 1] * 33331;
	scanf("%lld%lld", &n, &q);
	bool is = true;
	for (int i = 1; i <= n; ++ i ) {
		scanf("%s", tmp + 1);
		int len = strlen(tmp + 1);
		Len[i] = len;
		s1[i] = tmp + 1;
		s1[i] = ' ' + s1[i];
		scanf("%s", tmp + 1);
		s2[i] = tmp + 1;
		s2[i] = ' ' + s2[i];
		q1[i].push_back(0);
		q2[i].push_back(0);
		int h1 = 0, h2 = 0;
		bool is1 = true, is2 = true;
		int b1 = 0, b2 = 0;
		for (int j = 1; j <= len; ++ j ) {
			h1 = h1 * 33331 + s1[i][j];
			h2 = h2 * 33331 + s2[i][j];
			q1[i].push_back(h1);
			q2[i].push_back(h2);
			is1 &= s1[i][j] == 'a' || s1[i][j] == 'b';
			is2 &= s2[i][j] == 'a' || s2[i][j] == 'b';
			b1 += s1[i][j] == 'b';
			b2 += s2[i][j] == 'b';
		}
		if (h1 == h2) continue;
		for (int j = 0; j <= len; ++ j ) {
			if (query1 (i, j + 1, len) == query2 (i, j + 1, len)) {
				t[q1[i][j] * c[j] + q2[i][j]].push_back({i, j + 1});
			}
		}
		is &= is1 && is2; 
	}
	for (int i = 1; i <= q; ++ i ) {
		scanf("%s", tmp + 1);
		int len = strlen(tmp + 1);
		t1[i] = tmp + 1;
		t1[i] = ' ' + t1[i];
		scanf("%s", tmp + 1);
		t2[i] = tmp + 1;
		t2[i] = ' ' + t2[i];
		bool is1 = true, is2 = true;
		int b1 = 0, b2 = 0;
		for (int j = 1; j <= len; ++ j ) {
			is1 &= t1[i][j] == 'a' || t1[i][j] == 'b';
			is2 &= t2[i][j] == 'a' || t2[i][j] == 'b';
			b1 += t1[i][j] == 'b';
			b2 += t2[i][j] == 'b';
		}
		is &= is1 && is2;
	}
	is = false;
	if (is) {
//		for (int i = 1; i <= n; ++ i ) {
//			int len = (int)s1[i].size() - 1;
//			for (int j = 0; j <= len; ++ j ) {
//				if (query1 (i, j + 1, len) == query2 (i, j + 1, len)) {
//					su[q1[i][j] * c[j] + q2[i][j]].push_back(len - j);
//				}
//			}
//		}
//		for (auto j : su) {
//			for (int i : j.second) ++ S[i];
//			vector <int> v;
//			v.push_back(S[0]);
//			for (int i = 1; S[i]; ++ i ) S[i] += S[i - 1], v.push_back(S[i]);
//			sum[j.first] = v;
//			for (int i = (int)v.size(); i >= 0; -- i ) S[i] = 0;
//		}
//		for (int i = 1; i <= q; ++ i ) {
//			int len = (int)t1[i].size() - 1, ans = 0;
//			int l = 0, r = 0;
//			for (int j = 1; j <= len; ++ j ) {
//				h1[j] = h1[j - 1] * 33331 + t1[i][j];
//				h2[j] = h2[j - 1] * 33331 + t2[i][j];
//			}
//			for (int j = 1; j <= len; ++ j ) {
//				if (t1[i][j] != t2[i][j]) {
//					l = j;
//					break;
//				}
//			}
//			for (int j = len; j >= 1; -- j ) {
//				if (t1[i][j] != t2[i][j]) {
//					r = j;
//					break;
//				}
//			}
//			for (int j = 1; j <= l; ++ j ) {
//				int L = r - j + 1;
//				unsigned long long H = que1 (j, r) * c[L] + que2 (j, r);
//				if (sum.count(H)) ans += sum[H][min((int)sum[H].size() - 1, n - r)];
//			}
//			printf("%lld\n", ans);
//		}
	} else {
		for (int i = 1; i <= q; ++ i ) {
			int len = (int)t1[i].size() - 1, ans = 0;
			int l = 0, r = 0;
			for (int j = 1; j <= len; ++ j ) {
				h1[j] = h1[j - 1] * 33331 + t1[i][j];
				h2[j] = h2[j - 1] * 33331 + t2[i][j];
			}
			for (int j = 1; j <= len; ++ j ) {
				if (t1[i][j] != t2[i][j]) {
					l = j;
					break;
				}
			}
			for (int j = len; j >= 1; -- j ) {
				if (t1[i][j] != t2[i][j]) {
					r = j;
					break;
				}
			}
			for (signed j = 1; j <= l; ++ j ) {
				signed L = r - j + 1;
				unsigned long long H = que1 (j, r) * c[L] + que2 (j, r);
				for (auto k : t[H]) {
					signed at = k.at, L = k.l;
					signed R = Len[at];
					if (R - L + 1 == 0) ++ ans;
					else if (R - L + 1 <= len - r && que1 (r + 1, r + (R - L + 1)) == query1 (at, L, R)) ++ ans;
				}
			}
			printf("%lld\n", ans);
		}
	}
	return 0;
}
