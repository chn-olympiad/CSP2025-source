#include <bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
const int mod = 998244353;
vector<int> dp;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	scanf("%d", &n);
	for (int i = 1;i <= n;i++)
		scanf("%d", &a[i]);
	sort(a + 1,a + n + 1);
	dp.push_back(1);
	int sum = 0;
	for (int i = 1;i <= n;i++){
		for (int j = a[i] + 1;j <= sum;j++)
			ans = (ans + dp[j]) % mod;
		sum += a[i];
		for (int j = 1;j <= a[i];j++) dp.push_back(0);
		for (int j = sum;j >= a[i];j--)
			dp[j] = (dp[j] + dp[j - a[i]]) % mod;
	}
	printf("%d", ans);
	return 0;
}
