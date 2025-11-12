#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1e5 + 10;
int T, n;
int a[N][3];
int f[3][N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	int ans = 0;
	cin >> T;
	while (T -- ) {
		memset(a, 0, sizeof a);
		memset(f, 0, sizeof f);
		cin >> n;
		int ans = 0;
		for (int i = 1; i <= n; i ++ )
			for (int j = 0; j < 3; j ++ )
				cin >> a[i][j];
		for (int i = 0; i < 3  ; i ++ ) {
			for (int j = 1; j <= n; j ++ ) {				
					
			}
		}
		for (int i = 0; i < 3; i ++ )
		ans = max(ans, f[i][n]);
		cout << ans << endl;
	}
	return 0;
}
