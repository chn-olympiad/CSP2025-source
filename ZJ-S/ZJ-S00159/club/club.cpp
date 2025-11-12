#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[100005][5];

void dfs(int id, long long cnt, int b1, int b2, int b3){
	if(b1 > n / 2 || b2 > n / 2 || b3 > n / 2) return;
	if(id > n){
		ans = max(ans, cnt);
		return;
	}
	
	dfs(id + 1, cnt + a[id][1], b1 + 1, b2, b3);
	dfs(id + 1, cnt + a[id][2], b1, b2 + 1, b3);
	dfs(id + 1, cnt + a[id][3], b1, b2, b3 + 1);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	while(t--){
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= 3; j++) cin >> a[i][j];
		}
		dfs(1, 0, 0, 0, 0);
		cout << ans << "\n";
	}
	
	return 0;
}
