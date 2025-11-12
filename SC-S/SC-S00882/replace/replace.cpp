#include<bits/stdc++.h>
#define cs const
#define dif(a, b)((a) ^ (b))

using namespace std;

cs int MAXN = 2e5 + 7;

int n;
int len[2][MAXN];
string s[2][MAXN];
vector<int> fail[2][MAXN];
bitset<MAXN> possible;

int q;
int lent[2];
string t[2];

inline void calcFail(cs int& typ, cs int& ind) {
	fail[typ][ind].assign(len[typ][ind] + 1, 0);
	for (int cur = 2; cur <= len[typ][ind]; ++cur) {
		int pre = fail[typ][ind][cur - 1];
		while (pre && dif(s[typ][ind][pre + 1], s[typ][ind][cur]))
			pre = fail[typ][ind][pre];
		fail[typ][ind][cur] = pre + !dif(s[typ][ind][pre + 1], s[typ][ind][cur]);
	}
	return;
}
inline bool KMP(cs int& st, cs int& ed, cs int& ind) {
	int indt = st, indp = 0;
	while (indt <= ed) {
		while (indp && dif(s[0][ind][indp + 1], t[0][indt]))
			indp = fail[0][ind][indp];
		indp += !dif(s[0][ind][indp + 1], t[0][indt]);
		if (!dif(indp, len[0][ind])) {
			string cur;
			cur = " ";
			for (int i = 1; i <= indt - indp; ++i)	cur += t[0][i];
			for (int i = 1; i <= indp; ++i)			cur += s[1][ind][i];
			for (int i = indt + 1; i <= lent[0]; ++i)	cur += t[0][i];
			return cur == t[1];
		}
		indt++;
	}
	return false;
}

int main() {
#ifndef DEBUG
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#endif
//	freopen("replace4.in", "r", stdin);
//	freopen("replace4.out", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//	cout.tie(nullptr);
	cin >> n >> q;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j <= 1; ++j) {
			cin >> s[j][i];
			len[j][i] = s[j][i].size();
			s[j][i] = " " + s[j][i];
			calcFail(j, i);
		}
		possible[i] = (s[0][i] != s[1][i]);
	}
	while (q--) {
		cin >> t[0], lent[0] = t[0].size(), t[0] = " " + t[0];
		cin >> t[1], lent[1] = t[1].size(), t[1] = " " + t[1];
		int key = 1;
		while (t[0][key] == t[1][key])	key++;
		int ans = 0;
		for (int i = 1; i <= n; ++i)
			if (possible[i])
				ans += KMP(max(key - len[0][i] + 1, 1), min(key + len[0][i] - 1, lent[0]), i);
		cout << ans << '\n';
	}
	return 0;
}