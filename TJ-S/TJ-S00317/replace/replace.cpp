#include<bits/stdc++.h>
using namespace std;

namespace z {
#define int long long
const int N = 5e5 + 5;
int n, q;
int hsh[N][2];
int bs = 131, pw[N];
const int mod = 924844033;
int gethash(string s) {
	int res = 0;
	for(char i : s) res = (1ll * res * 131 + i - 'a' + 1)%mod;
	return res;
} 
unsigned long long cal(int x, int y) {
	unsigned long long tx = x;
	return (tx << 32 | (unsigned long long)y);
}
unordered_map<unsigned long long, int> mp;
void main() {
	freopen("replace.in", "r", stdin);
	freopen("replace.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < N; i++) pw[i] = pw[i - 1] * bs;
	cin >> n >> q;
	for(int i = 1; i <= n; i++) {
		string s1, s2; cin >> s1 >> s2;
		hsh[i][0] = gethash(s1);
		hsh[i][1] = gethash(s2);
		mp[cal(hsh[i][0], hsh[i][1])]++;
//		cerr << i <<" "<<cal(hsh[i][0], hsh[i][1])<<' '<<hsh[i][0]<<" "<<hsh[i][1]<<'\n';
	}
	while(q--) {
		string t1, t2; cin >> t1 >> t2;
		int L = 0, R = t1.size() + 1, len = t1.size();
		t1 = " " + t1, t2 = " " + t2;
		while(t1[L + 1] == t2[L + 1]) L++;
		while(t1[R - 1] == t2[R - 1]) R--;
		vector<int> h1(len + 1, 0), h2(len + 1, 0);
		for(int i = 1; i <= len; i++) h1[i] = (1ll * h1[i - 1] * bs + (t1[i] - 'a' + 1)) % mod; 
		for(int i = 1; i <= len; i++) h2[i] = (1ll * h2[i - 1] * bs + (t2[i] - 'a' + 1)) % mod; 
		int ans = 0;
//		cerr<<L<<" "<<R<<'\n';
		for(int l = 1; l <= L + 1; l++)
			for(int r = R - 1; r <= len; r++) {
				if(l > r) continue;
				int hsh1 = (h1[r] - h1[l - 1] * pw[r - l + 1] %mod + mod) % mod;
				int hsh2 = (h2[r] - h2[l - 1] * pw[r - l + 1]%mod+mod) % mod;
				ans += mp[cal(hsh1, hsh2)];
//				cerr<<l<<" "<<r<<" "<<hsh1<<" "<<hsh2<<'\n';
//				if(mp[cal(hsh1, hsh2)])cerr<<"add "<<l<<" "<<r<<'\n';
			}
		cout << ans << '\n';
	}
}
	
#undef int
	
} 

int main() {
	z::main();
	return 0;
}
