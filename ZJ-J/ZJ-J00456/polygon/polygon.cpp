#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long n,a[5005];
long long ans = 0;
void dfs(int t,int cnt,long long sum,long long maxx){
	if(t > n){
		if(cnt >= 3 && sum > maxx * 2){
			ans++;
		}
		return;
	}
	dfs(t+1,cnt,sum,maxx);
	sum += a[t];
	maxx = max(maxx,a[t]);
	dfs(t+1,cnt+1,sum,maxx);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	dfs(1,0,0,-1);
	cout << ans % mod;
	return 0;
}