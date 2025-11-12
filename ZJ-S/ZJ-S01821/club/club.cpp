#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T, cl[4], a[4][100005], n, lim, maxn, b[100005];
void dfs(ll x, ll ci){
	if(ci>n){
		maxn=max(maxn, x);
		return;
	}
	for(ll i=1; i<=3; i++){
		if(cl[i]>=lim)continue;
		cl[i]++;
		dfs(x+a[i][ci], ci+1);
		cl[i]--;
	}
	return;
}

void solve(){
	ll sum=0;cin >> n;lim=n/2;maxn=0;bool flag=0;
	for(ll i=1; i<=n; i++)cin >> a[1][i] >> a[2][i] >> a[3][i];
	for(ll i=1; i<=n; i++)flag|=(a[2][i]|a[3][i]);
	if(flag)dfs(0, 1);
	else {
		for(ll i=1; i<=n; i++){
			b[i]=a[1][i];
		}
		sort(b+1, b+1+n);
		for(ll i=1; i<=lim; i++)maxn+=b[i];
	}
	cout<<maxn<<'\n';
	return;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	cin >> T;
	while(T--){
		solve();
	}
	return 0;
}
//25·Ö 
