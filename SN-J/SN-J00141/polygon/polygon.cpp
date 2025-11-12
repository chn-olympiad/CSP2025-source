//SN-J00141 刘益铭 西安高新第一中学 
#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long

const int N = 5e3 + 5;

ll n,a[N],ans;

bool f = true;

ll C(int n,int m) {
	ll cnt = 1;
	for(int i = n;i>=n-m+1;i--) cnt = cnt * i;
	for(int i = m;i>=1;i--) cnt = cnt / i;
	return cnt;
}

void dfs(ll x,ll cnt,ll sum,ll maxn) {
	if(x > n) {
		if(cnt < 3) return;
		if(sum > maxn * 2) ans++;
		return;
	}
	dfs(x+1,cnt+1,sum+a[x],max(maxn,a[x]));
	dfs(x+1,cnt,sum,maxn);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin >> n;
	for(int i = 1;i<=n;i++) {
		cin >> a[i];
		if(a[i] != 1) f = false;
	}
	if(f) {
		int ans = 0;
		for(int i = 3;i<=n;i++) ans = (ans + C(n,i));
		cout << ans;
		return 0;
	}
	dfs(1,0,0,0);
	cout << ans;
	return 0;
}
