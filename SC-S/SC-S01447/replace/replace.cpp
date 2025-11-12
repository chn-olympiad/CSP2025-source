#include <queue>
#include <string>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define fi first
#define se second
#define pii pair<ll , ll>
#define mk make_pair
#define ls x << 1
#define rs x << 1 | 1
#define ull unsigned ll
using namespace std;
ll const N = 2e5 + 10 , M = 5e6 + 10 , p = 131;
ll n , T;
ull sl[M] , sr[M];
struct node{
	ull l , r , s , t;
	ll llen , rlen , len , op;
}a[N];
signed main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> T;
	string s , t;
	for (int i = 1;i <= n;i ++){
		cin >> s >> t;
		a[i].op = (s == t);
		ll len = s.length() , l = -1 , r = len;
		a[i].len = len;
		while (l < len - 1 && s[l + 1] == t[l + 1]){
			l ++;
		}
		for (int j = l;j >= 0;j --) a[i].l *= p , a[i].l += s[j] - 'a' + 1;
		a[i].llen = l + 1;
		while (r > 0 && s[r - 1] == t[r - 1]){
			r --;
		}
		for (int j = r;j < len;j ++) a[i].r *= p , a[i].r += s[j] - 'a' + 1;
		a[i].rlen = len - r;
		if (l <= r){
			for (int j = l + 1;j <= r - 1;j ++) a[i].s *= p , a[i].s += s[j] - 'a' + 1;
			for (int j = l + 1;j <= r - 1;j ++) a[i].t *= p , a[i].t += t[j] - 'a' + 1;
		}
	}
	if (n * T <= 1e8){
		string s , t;
		while (T --){
			cin >> s >> t;
			if (s.length() != t.length()){
				cout << "0\n";
				continue;
			}
			ll len = s.length() , l = -1 , r = len;
			ull smid = 0 , tmid = 0;
			for (int i = 0;i <= len;i ++) sl[i] = sr[i] = 0;
			while (l < len && s[l + 1] == t[l + 1]){
				l ++;
			}
			while (r >= 0 && s[r - 1] == t[r - 1]){
				r --;
			}
			for (int j = l + 1;j <= r - 1;j ++) smid *= p , smid += s[j] - 'a' + 1;
			for (int j = l + 1;j <= r - 1;j ++) tmid *= p , tmid += t[j] - 'a' + 1;
			for (int i = l;i >= 0;i --) sl[i] = sl[i + 1] * p + s[i] - 'a' + 1;
			for (int i = r;i < len;i ++) sr[i] = sr[i - 1] * p + s[i] - 'a' + 1;
			ll ans = 0;
			for (int i = 1;i <= n;i ++){
				if (a[i].s == smid && a[i].t == tmid && !a[i].op){
					if (a[i].llen == a[i].len || a[i].llen > l + 1 || a[i].rlen > len - r) continue;
					if ((a[i].llen == 0 || a[i].l == sl[l - a[i].llen + 1]) && (a[i].rlen == 0 || a[i].r == sr[r + a[i].rlen - 1])) ans ++;
				}
			}
			cout << ans << "\n";
		}
	}
	return 0;
}
/*
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
aaaa bbbb

*/