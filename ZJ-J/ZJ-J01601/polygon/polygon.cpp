#include<bits/stdc++.h>
using namespace std;
int a[5005];
int ans[5005];
int p = 0;
int ans_fin = 0;
int n;
bool cmp (int a , int b) {
	return a < b;
}
map < pair<int , int>, int> mp;
void dfs (int P , int k) {
	if (mp.count({ans[1] , k})) {
		ans_fin += mp[{ans[1] , k}];
		mp[{ans[1] , k}] += 1;
		return;
	}
	if (k == 0) {
		int maxx = 0;
		int sum = 0;
		for (int i = 1;i <= p; i++) {
			sum += ans[i];
			maxx = max(maxx , ans[i]);
		}
		if (sum > maxx * 2) {
			ans_fin++;
			mp[{ans[1] , p}] += 1;
		}
		return;
	}
	else if (P > n) return;
	for (int i = P; i <= n; i++) {
		ans[++p] = a[i];
		dfs(i + 1 , k - 1);
		--p;
	}
	return;
}
int main () {
	freopen("polygon.in" , "r" , stdin);
	freopen("polygon.out" , "w" , stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1 , a + n + 1 , cmp);
	for (int k = 3; k <= n; k++) {
		mp.clear();
		dfs(1 , k);
	}
	cout << ans_fin << "\n";
	return 0;
}
