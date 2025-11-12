#include <bits/stdc++.h>
using namespace std;
int n;
long long k;
long long a[500005];
int res[500005], dp[500005];
int check(int cour){
	long long ans = 0;
	for(int i=cour; i<=n; i++){
		ans ^= a[i];
		if(ans==k) return i;
	}
	return 0;
}
void dfs(int step){
	int min_ = 5*1e5+2;
	for(int j=step; j<=n; j++){
		if(res[j]>0) min_ = min(res[j], min_);
	}
	if(min_!=(5*1e5+2)){
		dp[min_] += dp[step];
		dfs(min_+1);
	}
	return;
}
int main(){
	freopen("xor.in", "r", stdin);
	freopen("xor.out", "w", stdout);
	bool is_b=1;
	cin >> n >> k;
	if(k>1) is_b = 0;
	for(int i=1; i<=n; i++){
		cin >> a[i];
		if(a[i]>1) is_b=0;
	}
	if(is_b){
		if(k==0){
			int cnt=0;
			for(int i=1; i<=n; i++){
				if(a[i]==0) cnt++;
				else if(a[i-1]==1){
					a[i] = 0;
					cnt++;
				}
			}
			cout << cnt;
		}
		else{
			int cnt = 0;
			for(int i=1; i<=n; i++) cnt += a[i];
			cout << cnt;
		}
		return 0;
	}
	for(int i=1; i<=n; i++){
	    res[i] = check(i);
	    dp[i] = res[i]>0;
	}
	dfs(1);
	int max_ = 0;
	for(int i=1; i<=n; i++) max_ = max(max_, dp[i]);
	cout << max_;
	return 0;
} 
