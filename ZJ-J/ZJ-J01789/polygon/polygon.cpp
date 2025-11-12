#include<bits/stdc++.h>

int N, a[5005];
int dp[25000005];
int Sum;
int Ans;

const int Mod = 998244353;

int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	std::cin >> N;
	for(int i = 1; i <= N; i ++) std::cin >> a[i];
	std::sort(a + 1, a + 1 + N);
	
	dp[0] = 1;
	for(int i = 1; i <= N; i ++) {
		Sum += a[i];
		for(int j = a[i] + 1; j <= Sum; j ++) Ans = (Ans + dp[j]) % Mod;
		for(int j = Sum; j >= a[i]; j --) 
			dp[j] = (dp[j] + dp[j - a[i]]) % Mod;
	}
	
	std::cout << Ans;
	return 0;
}
