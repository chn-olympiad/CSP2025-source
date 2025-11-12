#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 2e5 + 5;
int n, q;
string a[N], b[N], s, t;
int f[N];
int main (){
	freopen ("replace.in", "r", stdin);
	freopen ("replace.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0), cout.tie (0);
	cin >> n >> q;
	for (int i = 1; i <= n; i ++)
		cin >> a[i] >> b[i];
	for (int i = 1; i <= q; i ++){
		memset (f, 0, sizeof f);
		cin >> s >> t;
		int l = s.size ();
		ll ans = 0;
		for (int i = 0; i < l; i ++){
			for (int j = i + 1; j < l; j ++){
				string x1, y1, z1, x2, y2, z2;
				for (int k = 0; k < l; k ++){
					if (k < i)
						x1 += s[k], x2 += t[k];
					else if (k >= i && k <= j)
						y1 += s[k], y2 += t[k];
					else
						z1 += s[k], z2 += t[k];
				}
				for (int k = 1; k <= n; k ++)
					if (y1 == a[k] && y2 == b[k] && f[k] == 0 && x1 == x2 && z1 == z2){
						f[k] = 1;
						ans ++;
					}
			}
		}
		cout << ans << "\n"; 
	}
	return 0;
} 