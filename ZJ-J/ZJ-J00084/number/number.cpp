#include <bits/stdc++.h>

using namespace std;

int _;
inline int read() {int s = 0, w = 1;char ch = getchar();while (ch < '0' || ch > '9') {if (ch == '-') w *= -1;ch = getchar();}while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + (ch ^ 48);ch = getchar();}return s * w;}
inline void write(int x) {if (x < 0) x = -x, putchar('-');if (x > 9) write(x / 10);putchar(x % 10 + '0');}

vector<int> num;

inline void solve() {
	string s;
	cin >> s;
	s = ' ' + s;
	int n = s.size();
	for (int i = 1; i <= n; ++i) {
		if (s[i] >= '0' && s[i] <= '9') {
			num.push_back(s[i] - '0');
		}
	}
	sort(num.rbegin(), num.rend());
	for (auto& x : num) write(x);
}

int main() {
	freopen("number.in", "r", stdin);
	freopen("number.out", "w", stdout);
//	_ = read();
	_ = 1;
	for (int i = 1; i <= _; ++i) solve();
	return 0;
}
