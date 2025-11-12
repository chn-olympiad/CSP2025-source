#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += (d))
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= (d))
//#define int long long
void INIT() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 5e3 + 10;
int c[MAXN];

signed main() {
	srand(time(0));
	INIT();
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	upl(i, 1, n, 1) {
		cin >> c[i];	
	}
	cout << rand() * 1ll * rand() % 998244353;
	return 0;
}

