#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int N = 2e5+5,M = 5e6+5;const ll mod = 1317119,base1 = 1013;const ull base2 = 998244353;
ll pow1[M];ull pow2[M];
int n,q;
inline pair<ll,ull> operator + (const pair<ll,ull> A,const char B){return make_pair((A.first*base1%mod+B)%mod,A.second*base2+B);}
inline pair<ll,ull> operator + (const pair<ll,ull> A,const pair<ll,ull> B){return make_pair((A.first+B.first)%mod,A.second+B.second);}
inline pair<ll,ull> operator - (const pair<ll,ull> A,const pair<ll,ull> B){return make_pair((A.first+mod-B.first)%mod,A.second-B.second);}
inline pair<ll,ull> operator * (const pair<ll,ull> A,const int B){return make_pair(A.first*pow1[B]%mod,A.second*pow2[B]);}
vector<pair<ll,ull>>S[2][N];
struct Item{
	ull Hash2;vector<pair<pair<pair<pair<ll,ull>,int>,pair<pair<ll,ull>,int>>,pair<pair<pair<ll,ull>,int>,pair<pair<ll,ull>,int>>>>g;
};vector<Item>tong[mod+10];
inline pair<ll,ull> queryS(int op,int id,int l,int r){if(l > r) return make_pair(0ll,0ull);return S[op][id][r]-(l ? S[op][id][l-1] : make_pair(0ll,0ull))*(r-l+1);}
inline void insert(pair<ll,ull> Hash1,pair<ll,ull> Hash2,int L2,pair<ll,ull> Hash3,int L3,pair<ll,ull> Hash4,int L4,pair<ll,ull> Hash5,int L5){
//	cout << "Hash1=" << Hash1.first << ",H2=" << Hash2.first << ",H3=" << Hash3.first << ",L2=" << L2 << ",L3=" << L3 << "\n";
	for(auto &e : tong[Hash1.first]){
		if(e.Hash2 == Hash1.second){
			e.g.emplace_back(make_pair(make_pair(make_pair(Hash2,L2),make_pair(Hash3,L3)),make_pair(make_pair(Hash4,L4),make_pair(Hash5,L5))));
			return;
		}
	}vector<pair<pair<pair<pair<ll,ull>,int>,pair<pair<ll,ull>,int>>,pair<pair<pair<ll,ull>,int>,pair<pair<ll,ull>,int>>>>g;
	g.emplace_back(make_pair(make_pair(make_pair(Hash2,L2),make_pair(Hash3,L3)),make_pair(make_pair(Hash4,L4),make_pair(Hash5,L5))));
	tong[Hash1.first].emplace_back((Item){Hash1.second,g});
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("replace.in","r",stdin);freopen("replace.out","w",stdout);
	pow1[0] = 1;pow2[0] = 1;for(int i = 1;i < M;++i) pow1[i] = pow1[i-1]*base1%mod,pow2[i] = pow2[i-1]*base2%mod;
	cin >> n >> q;
	for(int i = 1;i <= n;++i){
		string s,t;
		cin >> s >> t;
		int len = s.length();
		for(int j = 0;j < len;++j){
			pair<ll,ull> tmpHash = (j ? S[0][i].back() : make_pair(0ll,0ull));
			S[0][i].emplace_back(tmpHash+s[j]);
			tmpHash = (j ? S[1][i].back() : make_pair(0ll,0ull));
			S[1][i].emplace_back(tmpHash+t[j]);
		}int L = -1,R = len;
		while(s[L+1] == t[L+1]) ++L;
		while(s[R-1] == t[R-1]) --R;
		insert(queryS(0,i,L+1,R-1),queryS(0,i,0,L),L+1,queryS(0,i,R,len-1),len-R,queryS(1,i,0,L),L+1,queryS(1,i,R,len-1),len-R);
	}for(int i = 1;i <= q;++i){
		string s,t;
		cin >> s >> t;
		int len = s.length(),ans = 0;
		S[0][n+1].clear();S[1][n+1].clear();
		for(int j = 0;j < len;++j){
			pair<ll,ull> tmpHash = (j ? S[0][n+1].back() : make_pair(0ll,0ull));
			S[0][n+1].emplace_back(tmpHash+s[j]);
			tmpHash = (j ? S[1][n+1].back() : make_pair(0ll,0ull));
			S[1][n+1].emplace_back(tmpHash+t[j]);
		}int L = -1,R = len;
		while(s[L+1] == t[L+1]) ++L;
		while(s[R-1] == t[R-1]) --R;
		pair<ll,ull> Hash1 = queryS(0,n+1,L+1,R-1);
		for(auto &e : tong[Hash1.first]){
			if(e.Hash2 == Hash1.second){
				for(auto &p : e.g){
					auto Q = p.first,H = p.second;
					if(L-Q.first.second+1 >= 0 && queryS(0,n+1,L-Q.first.second+1,L) == Q.first.first && R+Q.second.second-1 < len && queryS(0,n+1,R+Q.second.second-1,len-1) == Q.second.first){
//						cout << "???\n";
						if(L-H.first.second+1 >= 0 && queryS(1,n+1,L-H.first.second+1,L) == H.first.first && R+H.second.second-1 < len && queryS(1,n+1,R+H.second.second-1,len-1) == H.second.first){
							++ans;
						}
					}
				}
			}
		}cout << ans << "\n";
	}
	return 0;
}