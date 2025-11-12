#include <bits/stdc++.h>

#define ll long long
#define ull unsigned long long
#define endl '\n'

using namespace std;

const int maxn = 2e5 + 7;
const int maxl = 5e6 + 7;
const int inf  = 0x3f3f3f3f;
const ull P    = 13131;

int n, m;
ull pw[5000007];
struct Str {
	int len1, len2, pos1, pos2;
	vector<ull> h1, h2;
	Str() {}
	Str(string s1, string s2) {
		len1 = s1.size(), len2 = s2.size();
		h1.assign(len1 + 10, 0ll), h2.assign(len2 + 10, 0ll);
		for (int i = 1; i <= len1; ++i)
			h1[i] = h1[i - 1] * P + s1[i - 1] - '0';
		for (int i = 1; i <= len2; ++i)
			h2[i] = h2[i - 1] * P + s2[i - 1] - '0';
	}
	ull get1(int l, int r) {return h1[r] - h1[l - 1] * pw[r - l + 1];}
	ull get2(int l, int r) {return h2[r] - h2[l - 1] * pw[r - l + 1];}
} s[maxn], q[maxn];
ll rep(Str a, Str b) {
	ll res = 0;
	for (int i = 1; i + b.len1 - 1 <= a.len1; ++i) {
		if (a.get1(i, i + b.len1 - 1) != b.get1(1, b.len1)) continue;
		res += (a.get1(1, i - 1) * pw[a.len1 - i + 1] +
			    b.get2(1, b.len2) * pw[a.len1 - i + 1 - b.len1] + 
			    a.get1(i + b.len1, a.len1) == a.get2(1, a.len2));
	}
	return res;
}
string s1, s2;
bool B = 1; int bcnt = 0;
namespace SubB {
	vector<int> S[maxl << 1];
	void Main() {
		int mx = -inf, mn = inf;
		for (int i = 1; i <= n; ++i) {
			int idx = maxl + s[i].pos2 - s[i].pos1;
			S[idx].push_back(s[i].len1 - s[i].pos1);
			mx = max(mx, idx), mn = min(mn, idx);
		}
		
		for (int i = mn; i <= mx; ++i) {
			if (S[i].size() <= 1) continue;
			sort(S[i].begin(), S[i].end());
		}
		
//		for (int i = 1; i <= n; ++i) {
//			printf("i:%d, pos1:%d, pos2:%d, dif:%d\n", i, s[i].pos1, s[i].pos2, s[i].pos2 - s[i].pos1);
//		}
//		for (int i = 1; i <= m; ++i) {
//			printf("i:%d, pos1:%d, pos2:%d, dif:%d\n", i, q[i].pos1, q[i].pos2, q[i].pos2 - q[i].pos1);
//		}
//		cout << "mx:" << mx << ", mn:" << mn << endl;
//		for (int i = mn; i <= mx; ++i) {
//			printf("i:%d\n", i);
//			for (int d : S[i]) printf("%d ", d);
//			puts("");
//		}
		for (int i = 1; i <= m; ++i) {
//			puts("===================================");
			if (q[i].len1 != q[i].len2)
				{cout << 0 << endl; continue;}
			int idx = maxl + q[i].pos2 - q[i].pos1;
			if (!S[idx].size()) {
				cout << 0 << endl;
				continue;
			}
//			printf("dis:%d, idx:%d\n", q[i].len1 - q[i].pos1, idx);
//			auto it = upper_bound(S[idx].begin(), S[idx].end(), q[i].len1 - q[i].pos1);
//			printf("d:%d\n", *it);
			ll cnt = upper_bound(S[idx].begin(), S[idx].end(), q[i].len1 - q[i].pos1) - S[idx].begin();
			cout << cnt << endl;
		}
	}
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
//	freopen("replace4.in", "r", stdin);
//	freopen("my.out", "w", stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0), cout.tie(0);
	pw[0] = 1;
	for (int i = 1; i <= 5e6; ++i) pw[i] = pw[i - 1] * P;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) {
		cin >> s1 >> s2, s[i] = Str(s1, s2);
		bcnt = 0;
		for (int j = 0; j < (int)s1.size(); ++j) {
			B &= (s1[j] == 'a' || s1[j] == 'b');
			if(s1[j] == 'b') s[i].pos1 = j + 1, ++bcnt;
		}
		B &= (bcnt == 1), bcnt = 0;
		for (int j = 0; j < (int)s2.size(); ++j) {
			B &= (s2[j] == 'a' || s2[j] == 'b');
			if(s2[j] == 'b') s[i].pos2 = j + 1, ++bcnt;
		}
		B &= (bcnt == 1);
	}
	
	for (int i = 1; i <= m; ++i) {
		cin >> s1 >> s2, q[i] = Str(s1, s2);
		bcnt = 0;
		for (int j = 0; j < (int)s1.size(); ++j) {
			B &= (s1[j] == 'a' || s1[j] == 'b');
			if(s1[j] == 'b') q[i].pos1 = j + 1, ++bcnt;
		}
		B &= (bcnt == 1), bcnt = 0;
		for (int j = 0; j < (int)s2.size(); ++j) {
			B &= (s2[j] == 'a' || s2[j] == 'b');
			if(s2[j] == 'b') q[i].pos2 = j + 1, ++bcnt;
		}
		B &= (bcnt == 1);
	}
	
//	if (B) {
//		SubB::Main();
//		return 0;
//	}
	ll ans = 0;
	for (int i = 1; i <= m; ++i) {
//		puts("==========================================");
//		printf("query %d\n", i);
		if (q[i].len1 != q[i].len2)
			{cout << 0 << endl; continue;}
		ans = 0;
		for (int j = 1; j <= n; ++j) {
//			puts("--------------------------------------------");
//			printf("j:%d\n", j);
			ans += rep(q[i], s[j]);
		}
		printf("%lld\n", ans);
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

3 4
a b
b c
c d
aa bb
aa b
a c
b a

4 5
aaab aaba
ab ab
ab ba
aba baa
aaaaab aaaaba
aabaaa aaaaab
abaaaa baaaaa
aaaaba abaaaa
baaaaa abaaaa
*/
