#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define push_back emplace_back
#define int long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 10;
signed main() {
	File("replace");
	iosFast;
	int n, q;
	cin >> n >> q;
	string s1, s2;
	for (int i = 1; i <= n; i++) cin >> s1 >> s2;
	while (q--) {
		cin >> s1 >> s2;
		cout << 0 << endl;
	}
	return 0;
}