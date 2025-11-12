#include <bits/stdc++.h>
using namespace std;

const int M = 5010;
const int MA = M * M;
int n;
int a[M];
int dp[MA][2] = {0};
long long h = 0;
long long cnt = 0;

int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a+n);
	for(int i = 0; i < n - 2; i++){
		dp[h][0] = a[i];
		dp[h][1] = i;
		h++;
	}
	for(int i = 0; i < h; i++){
		for(int j = dp[i][1] + 1; j < n - 1; j++){
			dp[h][0] = dp[i][0] + a[j];
			dp[h][1] = j;
			h++;
			for(int k = j + 1; k < n; k++){
				if(dp[i][0] + a[j] > a[k]){
					cnt++;
					cnt %= 998244353;
				}
				else break;
			}
		}
	}
	cout << cnt;
	return 0;
}
