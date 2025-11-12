#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=5005, Mod=998244353;
ll n, a[N];
bool cmp(int x, int y) {
	return x>y;
}
int dfs(ll sum, ll maxn, ll k) { // ≤‚ ‘µ„ 1-10
	if(k>n) {
		if(sum>maxn*2) return 1;
		else return 0;
	}
	return (dfs(sum+a[k], a[k], k+1)+dfs(sum, maxn, k+1)) % Mod;
}
int C() { // ≤‚ ‘µ„ 15-17, 18-20
	ll ans=0;
	for(int i=1; i<=n-2; i++) {
		for(int j=i+1; j<=n-1; j++) {
			ll p=pow(2, n-j);
			ans=(ans+p-1) % Mod; 
		}
	} return ans;
}
int dfs2(ll sum, ll maxn, ll k) { // ºÙ»Á÷¶
	if(sum>maxn*2) return pow(2, n-k+1);
	if(k>n) return 0;
	return (dfs2(sum+a[k], max(maxn, a[k]), k+1)+dfs2(sum, maxn, k+1)) % Mod;
}
int main() {
	freopen("polygon.in", "r", stdin);
	freopen("polygon.out", "w", stdout);
	int cnt1=0;
	cin>>n;
	for(ll i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) {
			cnt1++;
		}
	}
	if(n<=26) {
		sort(a+1, a+n+1);
		cout<<dfs(0, 0, 1);
	} else if(cnt1==n) {
		cout<<C();
	} else {
		sort(a+1, a+n+1, cmp);
		cout<<dfs2(0, 0, 1);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
