#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 1e5 + 10;
ll a[N][4];
ll t, n, ans;
bool is_A = 1, is_B = 1;
ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+(c-'0');
		c=getchar();
	}
	return f*x;
}
void dfs(ll x, ll sum, ll num1, ll num2, ll num3) {
	if (num1 > n / 2 || num2 > n / 2 || num3 > n / 2) return;
	if (x > n) {
		ans = max(ans, sum);
		return;
	}
	dfs(x + 1, sum + a[x][1], num1 + 1, num2, num3);
	dfs(x + 1, sum + a[x][2], num1, num2 + 1, num3);
	dfs(x + 1, sum + a[x][3], num1, num2, num3 + 1);
	return;
}
void dfs2(ll x, ll sum, ll num1, ll num2) {
	if (num1 > n / 2 || num2 > n / 2) return;
	if (x > n) {
		if (num1 != n / 2 || num2 != n / 2) return;
		ans = max(ans, sum);
		return;
	}
	dfs2(x + 1, sum + a[x][1], num1 + 1, num2);
	dfs2(x + 1, sum + a[x][2], num1, num2 + 1);
	return;
}
ll b[N];
int main() {
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	t=read();
	while (t--) {
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);
		ans = 0;
		n=read();
		is_A = is_B = 1;
		for (ll i = 1; i <= n; i++) {
			a[i][1]=read(),a[i][2]=read(),a[i][3]=read();
			if (a[i][2] != 0 || a[i][3] != 0) is_A = 0;
			if (a[i][3] != 0) is_B = 0;
		}
		if (is_A) {
			for (ll i = 1; i <= n; i++) b[i] = a[i][1];
			sort(b + 1, b + n + 1);
			ll sum = 0;
			for (ll i = n; i > n / 2; i++) sum += b[i];
			cout << sum << "\n";
		} else if (is_B) {
			dfs2(1, 0, 0, 0);
			cout << ans << "\n";
		} else {
			dfs(1, 0, 0, 0, 0);
			cout << ans << "\n";
		}

	}
	return 0;
}