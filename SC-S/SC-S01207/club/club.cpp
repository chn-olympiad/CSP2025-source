#include <iostream>

using namespace std;

const int N = 2e5 + 5;

int t, n;
int a[N], b[N], c[N];
int ans;

void dfs(int sum1, int sum2, int sum3, int x, int sum)
{
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	
	if (sum1 < (n / 2)) {
		dfs(sum1 + 1, sum2, sum3, x + 1, sum + a[x]);
	}
	if (sum2 < (n / 2)) {
 		dfs(sum1, sum2 + 1, sum3, x + 1, sum + b[x]);
	}
	if (sum3 < (n / 2)) {
		 dfs(sum1, sum2, sum3 + 1, x + 1, sum + c[x]); 
	}
}

int main()
{
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> t;
	
	while (t--) {
		cin >> n;
		
		for (int i = 1; i <= n; i++) {
			cin >> a[i] >> b[i] >> c[i];
		}
		ans = 0;
		
		dfs(0, 0, 0, 1, 0);
		
		cout << ans << '\n';
	}
	
	return 0;
}