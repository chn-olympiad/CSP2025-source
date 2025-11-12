#include <bits/stdc++.h>
using namespace std;
#define int long long

int n;
int a[5010];
int ma = -1;
int sum = 0;
vector<int> v;
const int mod = 998244353;

int dfs(int j){
	if (j > n){
		if (v.size() >= 3 && sum > 2 * ma){
			return 1;
		}
		return 0;
	}
	int tmp = ma;
	
	ma = max(ma, a[j]);
	sum += a[j];
	v.push_back(a[j]);
	int t = dfs(j + 1);
	
	v.pop_back();
	ma = tmp;
	sum -= a[j];
	t += dfs(j + 1);
	return t % mod;
}

signed main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++){
		cin >> a[i];
	}
	cout << dfs(1);
	return 0;
}
