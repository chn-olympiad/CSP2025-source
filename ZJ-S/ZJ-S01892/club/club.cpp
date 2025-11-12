// Homeward you come, distant wind
// Expect: 80pts

#include <bits/stdc++.h>

#define int long long

using namespace std; 

#define pii pair<int, int>
#define x first
#define y second

const int N = 2e2 + 5;  
int T, n, ans, a[N][3], f[N >> 1][N >> 1][N]; 
priority_queue<int> pq; 

void fun1()
{
	memset(f, 0, sizeof f); 

	for(int i = 0; i <= n / 2; i ++)
	for(int j = 0; j <= n / 2; j ++)
	for(int k = 0; k <= min(n - i - j, n / 2); k ++) {
		if(i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + a[i + j + k][0]);  
		if(j) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k] + a[i + j + k][1]); 
		if(k) f[i][j][k] = max(f[i][j][k], f[i][j][k - 1] + a[i + j + k][2]); 
	}

	for(int i = 0; i <= n / 2; i ++) 
	for(int j = 0; j <= n / 2; j ++) 
		ans = max(ans, f[i][j][n - i - j]); 
}

void fun2()
{
	while(not pq.empty()) pq.pop(); 

	for(int i = 1; i <= n; i ++) ans += a[i][0]; 
	for(int i = 1; i <= n; i ++) pq.push(a[i][1] - a[i][0]);

	for(int i = 1; i <= n / 2; i ++) {
		ans += pq.top(); 
		pq.pop(); 
	}
}

signed main()
{
	freopen("club.in", "r", stdin); 
	freopen("club.out", "w", stdout); 

	cin.tie(nullptr) -> sync_with_stdio(false); 

	cin >> T;
	while (T --) {
		cin >> n; 
		for(int i = 1; i <= n; i ++) cin >> a[i][0] >> a[i][1] >> a[i][2];
	
		ans = 0; 

		if(n < N) fun1(); else fun2();

		cout << ans << '\n'; 
	}

	return 0; 
}