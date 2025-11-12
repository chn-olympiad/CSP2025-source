#include <bits/stdc++.h>
using namespace std;
#define int long long
#define i128 __int128
#define endl '\n'
mt19937 Rand(time(0));

const int N = 2e5 + 10;
const int M = 5e6 + 10;
const i128 mod = 1e12 + 998244353 + 1334925 + 1;

int n,q;
i128 base;
i128 pw[M];
i128 hh1[M],hh2[M];
map <i128,int> to;

int g1 (int l,int r){
	if (l > r) return 0;
	return (hh1[r] - hh1[l - 1] * pw[r - l + 1] % mod) % mod;
}
int g2 (int l,int r){
	if (l > r) return 0;
	return (hh2[r] - hh2[l - 1] * pw[r - l + 1] % mod) % mod;
}
void solve(){
	base = 233333;
	pw[0] = 1;
	for (int i = 1 ; i <= 5e6 ; i++) pw[i] = pw[i - 1] * base % mod;
	cin >> n >> q;
	for (int i = 1 ; i <= n ; i++){
		string s1,s2;
		cin >> s1 >> s2;
		i128 h1 = 0,h2 = 0;
		int len = s1.size();
		for (int i = 0 ; i < len ; i++){
			h1 = (h1 * base + s1[i]) % mod;
			h2 = (h2 * base + s2[i]) % mod;
		}
		to[h1 * base + h2]++;
	}
	while (q--){
		string t1,t2;
		cin >> t1 >> t2;
		if (t1.size() != t2.size()){
			cout << "0\n";
			continue;
		}
		int m = t1.size();
		for (int i = 1 ; i <= m ; i++){
			hh1[i] = (hh1[i - 1] * base + t1[i - 1]) % mod;
			hh2[i] = (hh2[i - 1] * base + t2[i - 1]) % mod;
		}
		int ans = 0;
		int l = 1,r = m;
		while (l <= m && g1(1,l) == g2(1,l)) l++;
		while (r >= 1 && g1(r,m) == g2(r,m)) r--;
		for (int i = 0 ; i <= l - 1 ; i++)
			for (int j = max(i + 2,r + 1) ; j <= m + 1 ; j++)
				ans += to[g1(i + 1,j - 1) * base + g2(i + 1,j - 1)];
		cout << ans << endl;
		for (int i = 1 ; i <= m ; i++) hh1[i] = hh2[i] = 0;
	}
}
signed main(){
	//freopen("replace3.in","r",stdin);
	//freopen("my.txt","w",stdout);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T = 1; //cin >> T;
	while (T--) solve();
	return 0;
}
