#include <bits/stdc++.h>
using namespace std;

const int M = 500010;
int n, m;
int a[M];
int dp[M] = {0}, h = 1;
int cnt = 0;

int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = n; i > 0; i--){
		dp[h] = a[i];
		if(dp[h] == m){
			cnt++;
			h = 1;
			continue;
		}
		for(int j = h-1; j > 0; j--){
			dp[j] = (dp[j] ^ a[i]);
			if(dp[j] == m){
				cnt++;
				h = 0;
				break;
			}
		}
		h++;
	}
	cout << cnt;
	return 0;
}
