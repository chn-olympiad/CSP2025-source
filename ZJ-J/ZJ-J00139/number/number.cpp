#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define reg(i, x, y, step) for (int i = x; i <= y; i += step)
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e6 + 10;
int a[N];
signed main() {
	File("number");
	int num = 0, p = 0;
	string s;
	cin >> s;
	for (char c : s)
		if (c >= '0' && c <= '9') a[++p] = (c - '0');
	sort(a + 1, a + p + 1);
	reverse(a + 1, a + p + 1);
	reg(i, 1, p, 1) cout << a[i];
	return 0;
}

