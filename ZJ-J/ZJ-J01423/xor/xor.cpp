#include <bits/stdc++.h>

#define debug(x) cerr << #x << ": " << x << '\n'

using namespace std;

typedef long long LL;

inline LL read() { LL x = 0, f = 1; char ch; while(!isdigit(ch = getchar())) if (ch == '-') f = -1; do x = (x << 3) + (x << 1) + (ch ^ 48); while(isdigit(ch = getchar())); return x * f; }

const int N = 1e3 + 10;
int f[N][N];

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);

	bool A = true;
	int n = read(), k = read(), ans = 0;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		if (a[i] != 1) A = false;	
	}
	
	if (A) return cout << n << '\n', 0;
	if (k == 0) {
	 	for (int i = 1; i <= n; i++) {
			 ans += (a[i] == 0);
	 	}
		return cout << ans << '\n', 0;
	}
	
		
		
	for (int j = i; j <= n; j ++) {
			
			if (f[i][j] == k) {
				++ ans;
//				cout << i << ' ' << j << '\n';
			}
		}
	}

	cout << ans << '\n';
	
	return 0;
}
//谁可以告诉我怎么去重
// who can tell me how to pop the same point ??????????????????????? cry cry cry