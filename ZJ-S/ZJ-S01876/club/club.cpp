#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define upl(i, s, t, d) for(int i = (s); i <= (t); i += (d))
#define dol(i, s, t, d) for(int i = (s); i >= (t); i -= (d))
//#define int long long
void INIT() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
}

const int MAXN = 1e5 + 10;
int a[MAXN][3], b[MAXN];
int dp1[205][105][105];

signed main() {
	INIT();
	
	int T;
	cin >> T;
	while(T--) {
		int n;
		cin >> n;
		bool tA = 1, tB = 1;
		upl(i, 1, n, 1) {
			cin >> a[i][0] >> a[i][1] >> a[i][2];
			tA &= (a[i][1] == 0 && a[i][2] == 0);
			tB &= a[i][2] == 0;
		}
			
		int ans = 0;
		if(n <= 2e2) {
			upl(i, 1, n, 1) {
				upl(j, 0, i, 1) {
					upl(k, 0, i - j, 1) {
						if(i == n && (j > n / 2 || k > n / 2 || n - i - j > n / 2))
							continue;
						dp1[i][j][k] = 0;
						if(i - j - k > 0)
							dp1[i][j][k] = max(dp1[i][j][k], dp1[i - 1][j][k] + a[i][2]);
						if(j > 0)
							dp1[i][j][k] = max(dp1[i][j][k], dp1[i - 1][j - 1][k] + a[i][0]);
						if(k > 0)
							dp1[i][j][k] = max(dp1[i][j][k], dp1[i - 1][j][k - 1] + a[i][1]);
//						cout << i << " " << j << " " << k << " " << dp1[i][j][k] << "\n";
					}
				}
			}
			upl(i, 1, n / 2, 1) {
				upl(j, 1, n / 2, 1) {
					if(n - i - j <= n / 2)
						ans = max(ans, dp1[n][i][j]);
				}
			}
		} else if(tA) {
			upl(i, 1, n, 1)
				b[i] = a[i][0];
			sort(b + 1, b + 1 + n, greater<int>());
			upl(i, 1, n / 2, 1)
				ans += b[i];
		}
		cout << ans << "\n";
	}	
	return 0;
}
