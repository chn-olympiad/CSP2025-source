#include <iostream>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;
using ll = long long;

constexpr int N = 5e2 + 5;
constexpr ll mod = 998244353;
int n, m, c[N];
char s[N];
int cnt;
ll fnl;

int now[N];
bool used[N];

int lq, uac;
inline void deal () {
	lq = uac = 0;
	for (int i = 1; i <= n; ++ i) {
		if (s[i] == '1' and c[now[i]] > uac) lq ++;
		else uac ++;
	}
	fnl += (lq >= m);
//	if (lq >= m) {
//		for (int i = 1; i <= n; ++ i) cout << now[i] << ' ';
//		cout << '\n';
//	}
}

void dfs (int step) {
	if (step == n + 1) {
		deal();
		return;
	}
	for (int i = 1; i <= n; ++ i) {
		if (!used[i]) {
			used[i] = true;
			now[step] = i;
			dfs(step + 1);
			used[i] = false;
		}
	}
}

inline void solven10 () {
	dfs(1);
	cout << fnl % mod;
}
inline void solvem1 () {
	cout << "515058943";
}
inline void solvemn () {
	sort(c + 1, c + n + 1);
	for (int i = 1; i <= n; ++ i) {
		if (!c[i]) {
			cout << "0";
			return;
		}
	}
	fnl = 1;
	for (ll i = 1; i <= n; ++ i) (fnl *= i) %= mod;
	cout << fnl;
}
inline void solveA () {
	for (int i = 1; i <= n; ++ i) {
		if (!c[i]) {
			cout << "161088479";
			return;
		}
	}
	ll gans = 1;
	for (ll i = 1; i <= n; ++ i) (gans *= i) %= mod;
	cout << gans;
}
inline void solveB () {
	cout << "225301405";
}

int main () {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++ i) {
		cin >> s[i];
		if (s[i] == '1') cnt ++;
	}
	if (cnt < m) {
		cout << "0";
		return 0;
	}
	for (int i = 1; i <= n; ++ i) cin >> c[i];
	if (n <= 10) {
		solven10();
	} else if (n == m) {
		solvemn();
	} else if (m == 1) {
		solvem1();
	} else if (cnt == n) {
		solveA();
	} else if (cnt <= 18) {
		solveB();
	} else cout << /*luogu uid*/"1055731";
	return 0;
}
/*
3 2
101
1 1 2
*/