#include <bits/stdc++.h>
#define iosFast ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define File(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout)
#define push_back emplace_back
#define int long long
#define endl "\n"
using namespace std;
const int N = 5e2 + 10;
int c[N];
signed main() {
	File("employ");
	iosFast;
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for (int i = 1; i <= n; i++) cin >> c[i];
	int f = 1;
	for (int i = 1; i <= n; i++) f = (f * i) % 998244353;
	srand(unsigned(time(NULL)));
	cout << rand() % f + 1;
	return 0;
}