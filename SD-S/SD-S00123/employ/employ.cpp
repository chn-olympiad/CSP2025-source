#include <bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 510;
const int Mod = 998244353;

int n, m, ans;
string s;
int c[N], a[N];

int main() {
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m >> s;
	s = " " + s;
	for(int i = 1; i <= n; ++ i) {
		cin >> c[i];
		a[i] = i;	
	}
	if(m == n) {
		for(int i = 1; i <= n; ++ i) {
			if(c[i] == 0 || s[i] == '0') {
				cout << 0;
				return 0;
			}
		}
	}
	if(n <= 18) {
		do {
			int now = 0;
			for(int i = 1; i <= n; ++ i) {
				if(c[a[i]] <= now || s[i] == '0') {
					++ now; continue;
				}
			}
			if(n - now >= m) ++ ans;
		} while(next_permutation(a + 1, a + n + 1));
		cout << ans;
		return 0;
	}
	cout << 0;
	return 0;
}
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3


*/
