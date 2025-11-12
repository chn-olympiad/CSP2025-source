#include<bits/stdc++.h>
using ll = long long;
const int N = 1e5 + 10;
int n, a[N][3];
int t1, t2, t3;
ll ans, sum;

void dfs(int k){
	if(k > n){
		ans = std::max(ans, sum);
		return;
	}
	if(t1 < n / 2){
		sum += a[k][0], t1++;
		dfs(k + 1);
		sum -= a[k][0], t1--;
	}
	if(t2 < n / 2){
		sum += a[k][1], t2++;
		dfs(k + 1);
		sum -= a[k][1], t2--;
	}
	if(t3 < n / 2){
		sum += a[k][2], t3++;
		dfs(k + 1);
		sum -= a[k][2], t3--;
	}
	return;
}

void solve(){
	std::cin >> n;
	bool f1 = true;
	for(int i = 1; i <= n; ++i){
		std::cin >> a[i][0] >> a[i][1] >> a[i][2];
		if(a[i][1] || a[i][2]) f1 = false;
	}
	if(f1){
		std::vector<int> b(n);
		for(int i = 1; i <= n; ++i) b[i - 1] = a[i][0];
		std::sort(b.begin(), b.end(), std::greater<int>());
		ll sum = 0;
		for(int i = 0; i < n / 2; ++i) sum += b[i];
		std::cout << sum << '\n';
	}
	else{
		ans = sum = t1 = t2 = t3 = 0;
		dfs(1);
		std::cout << ans << '\n';
	}
	return;
}

int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(0), std::cout.tie(0);
	int T;
	std::cin >> T;
	while(T--) solve();
	return 0;
}
