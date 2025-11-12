#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 10;
ll maxn;
int t, n;
int su[10], g[N], a[N][10];
void dfs(int d, ll sum){
	if(d > n){
		maxn = max(sum, maxn);
		return ;
	}
	for(int j = 1; j <= 3; j++){
		if(su[j] < n / 2){
			su[j]++;
			dfs(d + 1, sum + a[d][j]);
			su[j]--;
		}
	}
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> t;
	while(t--){
		int f = 1;
		maxn = -1;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				su[j] = 0;
				a[i][j] = 0;
			}
		}
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++){
				cin >> a[i][j];
				if(j == 2 || j == 3){
					if(a[i][j] != 0) f = 0;
				}
			}
		}
		if(f == 0){
			dfs(0, 0);
			cout << maxn << "\n";
		}
		else if(f == 1){
			ll ans = 0;
			for(int i = 1; i <= n; i++){
				g[i] = a[i][1];
			}
			sort(g + 1, g + 1 + n);
			for(int i = n; i > n / 2; i--){
				ans += g[i];
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
