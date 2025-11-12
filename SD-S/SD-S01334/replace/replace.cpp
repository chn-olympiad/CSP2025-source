#include <bits/stdc++.h>

using namespace std;

#define int long long

constexpr int N = 2e5 + 5,base = 131,mod = 998244353,V = 2e6 + 1;

int n,q,Hash[N],qpow[V + 5],rnd[30],hhash[N],Hash1[N];
std::vector<std::vector<std::string>> s;

struct node{
	int len,id;
}t[N];

inline int ksm(int x,int y){
	int ans = 1;
	while(y){
		if(y & 1) ans = ans * x % mod;
		x = x * x % mod;
		y >>= 1; 
	}
	return ans;
}
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	srand(time(NULL));
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> q;
	s.resize(n + 1);
	for(int i = 0; i <= 27; ++ i) rnd[i] = rand() % mod;
	qpow[0] = 1;
	for(int i = 1; i < V; ++ i) qpow[i] = qpow[i - 1] * base % mod;
	for(int i = 1; i <= n; ++ i){
		s[i].resize(2);
		std::cin >> s[i][0] >> s[i][1];
		t[i] = (node){
			(int)s[i][0].size(),i
		};
	}
	std::sort(t + 1,t + n + 1,[&](const node & a,const node & b){
		return a.len < b.len;
	});
	for(int i = 1; i <= n; ++ i){
		int j = t[i].id;
		int sz = s[j][0].size();
		for(int k = 0; k < sz; ++ k){
			(Hash[i] += (rnd[s[j][1][k] - 'a'] * rnd[s[j][1][k] - 'a'] % mod - rnd[s[j][0][k] - 'a'] * rnd[s[j][0][k] - 'a'] % mod + mod) % mod * qpow[k]) %= mod; 
			(Hash1[i] += rnd[s[j][0][k] - 'a'] * rnd[s[j][0][k] - 'a'] % mod * qpow[k]) %= mod;
		}
	}
//	std::unordered_map<int,int> mp;
	for(int i = 1; i <= q; ++ i){
		std::string S,T;
		std::cin >> S >> T;
		int len = S.size(),len2 = T.size(),hashS = 0,hashT = 0;
		if(len != len2){
			std::cout << 0 << '\n';
			continue;
		}
		for(int k = 0; k < len; ++ k){
			(hashS += rnd[S[k] - 'a'] * rnd[S[k] - 'a'] % mod * qpow[k + 1]) %= mod;
			(hashT += rnd[T[k] - 'a'] * rnd[T[k] - 'a'] % mod * qpow[k + 1]) %= mod;
			hhash[k + 1] = rnd[S[k] - 'a'] * rnd[S[k] - 'a'] % mod * qpow[k + 1] % mod;
			hhash[k + 1] = (hhash[k + 1] + hhash[k]) % mod;
		}
//		mp.clear();
		int ans = 0,j = 1,res = (hashT - hashS + mod) % mod;
//		for(int l = len; l >= 1; -- l){
//			while(j <= n && t[j].len + l - 1 <= len){
//				mp[Hash[j]] ++;
//				++ j;
//			}
//			for(int k = 1; k <= j; ++ k){
//				int nwhash = (hashS + qpow[l] * Hash[k] % mod + mod) % mod;
//				if(nwhash == hashT) ++ ans;
//			}
//			int need = res * ksm(qpow[l],mod - 2) % mod;
//			ans += mp[need];
//			for(int k = 1; k <= j; ++ k){
//				for(int p = 0; p < )
//			}
//		}
//		std::cout << ans << '\n';
		ans = 0;
		for(int l = 1; l <= len; ++ l){
			for(int j = 1; j <= n; ++ j){
				if(t[j].len + l - 1 <= len){
//					bool f = true;
//					for(int p = 0; p < t[j].len; ++ p){
//						if(s[t[j].id][0][p] != S[l + p - 1]){
//							f = 0; break;
//						}
//					}
					int aa = Hash1[j] * qpow[l] % mod;
					int bb = (hhash[l + t[j].len - 1] - hhash[l - 1] + mod) % mod;
					if(aa == bb){
						if((hashS + Hash[j] * qpow[l]) % mod == hashT) ++ ans;
					}
				}else break;
			}
		}
		std::cout << ans << '\n';
	}
	return 0;
}
