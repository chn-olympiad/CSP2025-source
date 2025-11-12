#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define maxn 1000007
const int INF = 1e9 + 7;

signed main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	struct timeb s;
	ftime(&s);
	srand(s.time * 1000 + s.millitm);
	cout << rand() % 998244353;
	return 0;
}

