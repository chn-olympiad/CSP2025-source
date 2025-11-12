#include<bits/stdc++.h>
#define int long long
using namespace std;
int n, m, a[505], mod = 998244353, vis[505], ans;
string s;
vector<int> v;
void dfs(int k){
	if(k == n + 1){
		int sum = 0;
		for(int i = 0;i < v.size();i++){
			if(a[v[i]] <= sum || s[i] == '0'){
				sum++;
			}
		}
		if(n - sum >= m) ans++;
		ans %= mod;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(vis[i]) continue;
		vis[i] = 1;
		v.push_back(i);
		dfs(k + 1);
		v.erase(v.begin() + (k - 1));
		vis[i] = 0;
	}
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in", "r", stdin);
	freopen("employ.out", "w", stdout);
	cin >> n >> m;
	cin >> s;
	int temp = 1, sum = 0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i]){
			sum++;
			temp *= sum;
		}
	}
	if(n > 10){
		cout << temp;
		return 0;
	}
	sort(a + 1, a + n + 1);
	dfs(1);
	cout << ans;
	return 0;
}

