#include<bits/stdc++.h>
#define rep(a, b, c) for(int a = b; a <= c; a++)
#define reps(a, b, c) for(int a = b; a > 0; a--)
#define int long long

using namespace std;

const int N = 1e5 + 7;
int t, n, ans, isf1, isf2 , f[205][205][205];

struct ps{
	int a, b, c;
}p[N];

bool cmp1(ps a, ps b){
	return a.a < b.a;
}

void solve(){
	if (isf1 && isf2){
		sort(p + 1, p + 1 + n, cmp1);
		rep(i, 1, n / 2) ans += p[i].a;
		cout << ans << "\n";
		return;
	}
	
	rep(w, 1, n){
		rep(i, 0, min(w, n / 2)){
			rep(j, 0, min(w - i, n / 2)){
				int k = w - i - j;
				if (k > n / 2) continue;
				if (i > 0) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k] + p[w].a);
				if (j > 0) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k] + p[w].b);
				if (k > 0) f[i][j][k] = max(f[i][j][k], f[i][j][k - 1] + p[w].c);
				ans = max(ans, f[i][j][k]);
			}
		}
	}
	
	cout << ans << "\n";
}

signed main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	freopen("club.in", "r", stdin);
	freopen("club.out", "w", stdout);
	
	cin >> t;
	while (t--){
		cin >> n, ans = 0, isf1 = isf2 = 1;
		rep(i, 1, n) cin >> p[i].a >> p[i].b >> p[i].c, isf1 &= !p[i].b, isf2 &= !p[i].c;
		solve();
		rep(i, 0, n) rep(j, 0, n) rep(k, 0, n) f[i][j][k] = 0;
	}
	
    return 0;
}
