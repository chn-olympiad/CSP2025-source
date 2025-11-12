#include<bits/stdc++.h>
#define fo(i , x , y) for(int i = x ; i <= y ; i++)
#define go(i , x , y) for(int i = x ; i >= y ; i--)
using namespace std;
const int maxn = 200005;
const int maxl = 5000005;
const int mod = 1000000009;
const int base = 114;
int n , q , pw[maxl];
struct Mystring{
	string s;
	int len;
	vector<int> hsh;
	void gethash(){
		len = s.size();
		hsh.clear();
		fo(i , 1 , len)
			hsh.push_back(0);
		hsh[0] = s[0];
		fo(i , 1 , len - 1)
			hsh[i] = (1ll * hsh[i - 1] * base % mod + s[i]) % mod;
	}
	int query(int l , int r){
		if(l == 0) return hsh[r];
		long long ans = hsh[r];
		ans = ans - 1ll * hsh[l - 1] * pw[r - l + 1] % mod;
		ans = (ans % mod + mod) % mod;
		return ans;
	}
}s[maxn][2] , t0 , t1;
int main(){
	freopen("replace.in" , "r" , stdin);
	freopen("replace.out" , "w" , stdout);
	ios :: sync_with_stdio(0) , cin.tie(0) , cout.tie(0);
	pw[0] = 1;
	fo(i , 1 , maxl - 5)
		pw[i] = 1ll * pw[i - 1] * base % mod;
	cin >> n >> q;
	fo(i , 1 , n){
		cin >> s[i][0].s >> s[i][1].s;
		s[i][0].gethash() , s[i][1].gethash();
	}
	while(q--){
		cin >> t0.s >> t1.s;
		t0.gethash() , t1.gethash();
		int len = t0.s.size();
		if(len != (int)t1.s.size()){
			cout << "0\n";
			continue;
		}
		int l = 0 , r = 0 , ans = 0;
		fo(i , 0 , len - 1)
			if(t0.s[i] != t1.s[i]){
				l = i;
				break;
			}
		fo(i , 0 , len - 1)
			if(t0.s[i] != t1.s[i])
				r = i;
		fo(i , 0 , l){
			int minlen = r - i + 1;
			fo(j , 1 , n){
				int llen = s[j][0].len;
				if(llen < minlen) continue;
				if(i + llen - 1 > len - 1) continue;
				if(s[j][0].query(0 , llen - 1) != t0.query(i , i + llen - 1))
					continue;
				if(s[j][1].query(0 , llen - 1) != t1.query(i , i + llen - 1))
					continue;
				ans++;
			}
		}
		cout << ans << '\n';
	}
}