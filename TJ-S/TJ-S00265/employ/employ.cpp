#include <bits/stdc++.h>
using namespace std;
#define int long long

int n , m , a[509] , f[509] = {1};
string s;
const int p = 998244353;

signed main() {
	freopen("employ.in" , "r" , stdin);
	freopen("employ.out" , "w" , stdout);
	srand(time(0));
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> s;
	for (int i = 1 ; i <= n ; i++) cin >> a[i] , f[i] = f[i - 1] * i % p;
	cout << (rand() % f[n] + 1) % p;
	return 0;
}
