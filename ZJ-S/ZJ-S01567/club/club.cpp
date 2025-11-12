#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll t, n, ans, cnt, a[N][10];

void dfs(ll x){
	if(x > n) {
		ans = max(ans, cnt);
	}
	for(int i = 1; i <= 3; i++){
		cnt += a[x][i];
		dfs(x + 1);
		cnt -= a[x][i];
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		ll t1 = 1, t2 = 1;
		//cout << 2;
		for(int i = 1; i <= n; i++)//{
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
			}
			
			//if(a[i][2]) t1 = 0;
			//if(a[i][3]) t2 = 0;
			
		}
		
		if(t1 && t2) {
			int b[N];
			for(int i = 1; i <= n; i++)
				b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			for(int i = n; i > n / 2; i++)
				ans += b[i];
			cout << ans;
		}
		else if(t2) {
			ll b[N];
			for(int i = 1; i <= n; i++){
				ans += a[i][1];
				b[i] = a[i][2] - a[i][1];
			}
			sort(b + 1, b + n + 1);
			for(int i = n ; i > n / 2; i++)
				ans += b[i];
			cout << ans;
		}
		else {
			cnt = 0;
			dfs(1);
			cout << ans;
		}
		cout << "\n";
	}
	
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
