#include <bits/stdc++.h>
#define LL long long
#define uLL unsigned long long
using namespace std;

const int N = 2e5 + 10, M = 5e6 + 10, p = 131;
int n, q, len;
string s1[N], s2[N];
char t1[M], t2[M];
uLL f[M], h[M], hs1[N], hs2[N], ht;
LL ans;

uLL cal(int l, int r) {
	return f[r] - f[l - 1] * h[r - l + 1];
}

bool chk(int l, int r, int k) {
	if(r - l + 1 != s1[k].size()) return 0;
	if(cal(l, r) != hs1[k]) return 0;
	//cout << "l r k " << l << " " << r << " " << " " << k << "\n";
 	for(int i = l, j = 0;i <= r;++ i, ++ j){
		if(s1[k][j] != t1[i]) return 0;
	}
	string s = "";
	for(int i = 1;i < l;++ i) s += t1[i];
	s += s2[k];
	for(int i = r + 1;i <= len;++ i) s += t1[i];
	for(int i = 1;i <= len;++ i){
		if(s[i - 1] != t2[i]) return 0;
	}
	return 1;
//	uLL s = cal(1, l - 1) * h[len - l + 2] + hs2[k] * h[len - r] + cal(r + 1, len);
//	cout << "l r k " << l << " " << r << " " << k << " " << s << ' ' << ht << '\n';
//	return s == ht;
}

signed main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> n >> q;
	for(int i = 1;i <= n;++ i){
		cin >> s1[i] >> s2[i];
		for(char c : s1[i]) hs1[i] = hs1[i] * p + c;
		for(char c : s2[i]) hs2[i] = hs2[i] * p + c;
	}
	h[0] = 1;
	for(int i = 1;i <= 5e6;++ i) h[i] = h[i - 1] * p;
	while(q--) {
		ans = ht = 0;
		cin >> (t1 + 1) >> (t2 + 1);
		if(strlen(t1 + 1) != strlen(t2 + 1)) {
			cout << "0\n";
			continue;
		}
		len = strlen(t1 + 1);
		for(int i = 1;i <= len;++ i) f[i] = f[i - 1] * p + t1[i], ht = ht * p + t2[i];
		for(int i = 1;i <= len;++ i){
			for(int j = i;j <= len;++ j){
				for(int k = 1;k <= n;++ k){
					if(chk(i, j, k)) {
						//cout << "1l r k " << i << " " << j << " " << " " << k << "\n";
						ans++;
					}
				}
			}
		}
		cout << ans << '\n';
	}
 	return 0;
}