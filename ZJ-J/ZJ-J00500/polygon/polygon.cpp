#include<bits/stdc++.h>
using namespace std;
int n;
int l[5005];
int sum[5005];
int dp[5005];
long long ans = 0;
int main(){
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	for(int i = 1; i<= n; i++){
		cin>>l[i];
	}
	sort(l + 1, l + n + 1);
	sum[0] = 0;
	for(int i = 1; i<= n; i++){
		sum[i] = sum[i - 1] + l[i];
	}
	for(int i = 3; i<= n; i++){
		for(int j = 3; j<= i; j++){
			if(sum[j] > l[i])ans += i - j + 1;
		}
	}
	cout<<ans % (998, 244, 353);
	return 0;
}