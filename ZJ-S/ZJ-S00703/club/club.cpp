#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

const int N = 1e5 + 100;
int n, ans = 0, a[N][5] = {}, dp[N] = {}, vis[N] = {}, b[N] = {};
void dfs(int x, int c1, int c2, int c3){
	if(c1 > n / 2 || c2 > n / 2 || c3 > n / 2) return;
	if(x == n + 1){
		int cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += a[i][b[i]];
		}
		ans = max(ans, cnt);
		return;
	}
	b[x] = 1;
	dfs(x + 1, c1 + 1, c2, c3);
	b[x] = 2;
	dfs(x + 1, c1, c2 + 1, c3);
	b[x] = 3;
	dfs(x + 1, c1, c2, c3 + 1);
}
bool cmp(int x, int y){
	return x > y;
}
bool check(){
	bool flag = false;
	for(int i = 1; i <= n; i++){
		int x = 0;
		bool f = false;
		for(int j = 1; j <= 3; j++) x += a[i][j];
		for(int j = 1; j <= 3; j++){
			if(x == a[i][j]) f = true;
		}
		if(!f){
			flag = true;
			break;
		}
	}
	return flag;
}
bool cmp1(pair<int, int> x, pair<int, int> y){
	if(x.first == y.first) return x.second > y.second;
	return x.first > y.first;
}

int main(){
	
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	int t;
	cin >> t;
	
	while(t--){
		
		ans = 0;
		cin >> n;
		for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) cin >> a[i][j];
			
		if(n <= 30){
			dfs(1, 0, 0, 0);
			cout << ans << "\n";
		}else if(check()){
			for(int i = 1; i <= n; i++) for(int j = 1; j <= 3; j++) vis[i] += a[i][j];
			sort(vis + 1, vis + 1 + n, cmp);
			for(int i = 1; i <= n / 2; i++) ans += vis[i];
			cout << ans << "\n";
		}else{
			vector<pair<int, int> > v1, v2, v3;
			for(int i = 1; i <= n; i++){
				int x = 0, y = 1e9, z = 0;
				for(int j = 1; j <= 3; j++) z += a[i][j], x = max(x, a[i][j]), y = min(y, a[i][j]);
				if(x == a[i][1]) v1.push_back({x, z - x - y});
				else if(x == a[i][2]) v2.push_back({x, z - x - y});
				else v3.push_back({x, z - x - y});
			}
			sort(v1.begin(), v1.end(), cmp1);
			sort(v2.begin(), v2.end(), cmp1);
			sort(v3.begin(), v3.end(), cmp1);
			for(int i = 0; i < n / 2 && i < v1.size(); i++) ans += v1[i].first;
			for(int i = 0; i < n / 2 && i < v2.size(); i++) ans += v2[i].first;
			for(int i = 0; i < n / 2 && i < v3.size(); i++) ans += v3[i].first;
			if(v1.size() > n / 2) for(int i = n / 2; i < v1.size(); i++) ans += v1[i].second;
			if(v2.size() > n / 2) for(int i = n / 2; i < v2.size(); i++) ans += v2[i].second;
			if(v3.size() > n / 2) for(int i = n / 2; i < v3.size(); i++) ans += v3[i].second;
			cout << ans << "\n";
		}
		
	}
	
	return 0;
}
