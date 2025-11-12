#include<iostream>
using namespace std;
int n, k;
int a[500010];
int dp[500010];
int mx[500010];
int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i ++) cin >> a[i];
	for(int i = 1; i <= n; i ++) {
		int sum = 0;
		for(int j = i; j >= 1; j --) {
			sum = sum ^ a[j];
			if(sum == k) {
				//cout << j << " " << i << '\n';
				dp[i] = mx[j - 1] + 1;
				break;
			}
		}
		mx[i] = max(mx[i - 1], dp[i]);
	}
	cout << mx[n] << '\n';
	return 0;
}
//wu wu wu T4 tiao tai jiu le xie bu wan T3 le.
//xor mei zen me zuo guo. liu dian yi han ba.