#include<bits/stdc++.h>
#define max(x, y) (x > y ? x : y)

int N, K;
int a[500005];
int T[2000000];
int l[500005];
int dp[500005];
int Ans;

int main() {
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	std::cin >> N >> K;
	for(int i = 1; i <= 1500000; i ++) T[i] = -1;
	for(int i = 1; i <= N; i ++) std::cin >> a[i], a[i] ^= a[i - 1], l[i] = T[a[i] ^ K], T[a[i]] = i;
	
	for(int i = 1; i <= N; i ++) 
		if(l[i] != -1) 
			dp[i] = max(dp[l[i]] + 1, dp[i - 1]);
		else 
			dp[i] = dp[i - 1];
	for(int i = 1; i <= N; i ++) Ans = max(dp[i], Ans);
	
	std::cout << Ans;
	return 0;
}
