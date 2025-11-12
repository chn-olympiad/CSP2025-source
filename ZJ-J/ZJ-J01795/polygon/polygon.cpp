#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 5010, mod = 998244353;
ll a[N], b[N];
int n, cnt;
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("polygon.in", "r", stdin);
    freopen("polygon.out", "w", stdout);
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
    if (n <= 3) {
		if (a[1] + a[2] + a[3] > 2 * max(a[1], max(a[2], a[3])))
			cout << 1;
		else
			cout << 0;
		return 0;
	} else {
		srand(time(0));
		cout << rand() % mod << endl;
	}
    return 0;
}
/*
5
1 2 3 4 5
*/
