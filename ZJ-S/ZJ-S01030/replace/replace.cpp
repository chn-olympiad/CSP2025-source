#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int N = 5e6 + 10, pp = 13131, M = 2e5 + 10;
ull pps[N], s[N], sto[N];
struct node { ull fr, to; } convt[M];
int n, q;
inline ull BKDRHash(string s) {
	ull val = 0;
	for(char c : s) val = val * pp + c;
	return val;
}
inline ull get(int L, int R) {
	return s[R] - s[L - 1] * pps[R - L + 1];
}
inline ull gett(int L, int R) {
	return sto[R] - sto[L - 1] * pps[R - L + 1];
}
inline bool cmp(const node &x, const node &y) {
	return x.fr < y.fr;
}
inline int bin(ull x) {
	int pl = 1, pr = n, mid, ret = -1;
	while(pl <= pr) {
		mid = (pl + pr) >> 1;
		if(convt[mid].fr >= x) pr = (ret = mid) - 1;
		else pl = mid + 1;
	}
	return ret;
}
inline int binr(ull x) {
	int pl = 1, pr = n, mid, ret = n + 1;
	while(pl <= pr) {
		mid = (pl + pr) >> 1;
		if(convt[mid].fr > x) pr = (ret = mid) - 1;
		else pl = mid + 1;
	}
	return ret;
}
inline void sol() {
	string sa, sb;
	cin >> sa >> sb;
	int len = sa.length();
	if(len != (int)sb.length()) {
		cout << 0 << '\n';
		return;
	}
	int ed, st = -1;
	sa = " " + sa, sb = " " + sb;
	for(int i = 1; i <= len; ++i)
		if(sa[i] != sb[i]) {
			if(st == -1) st = ed = i;
			else if(i != ed + 1) {
				cout << 0 << '\n';
				return;
			} else ed = i;
		}
	for(int i = 1; i <= len; ++i) s[i] = s[i - 1] * pp + sa[i];
	for(int i = 1; i <= len; ++i) sto[i] = sto[i - 1] * pp + sb[i];
	int ans = 0;
	for(int nowl = 1; nowl <= st; ++nowl)
		for(int nowr = ed; nowr <= len; ++nowr) {
			ull gt = get(nowl, nowr);
			int findst = bin(gt), finded = binr(gt);
			if(findst == -1) continue;
			for(int i = findst; i <= finded; ++i)
				if(convt[i].fr != gt) break;
				else if(convt[i].to == gett(nowl, nowr)) ++ans;
		}
	cout << ans << '\n';
}
signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q;
	pps[0] = 1;
	for(int i = 1; i < N; ++i) pps[i] = pps[i - 1] * pp;
	string sa, sb;
	for(int i = 1; i <= n; ++i) {
		cin >> sa >> sb;
		convt[i] = {BKDRHash(sa), BKDRHash(sb)};
	}
	sort(convt + 1, convt + 1 + n, cmp);
	while(q--) sol();
	return 0;
}