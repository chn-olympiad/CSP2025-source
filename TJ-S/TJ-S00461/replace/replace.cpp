#include<bits/stdc++.h>
#define f(i , x , y) for(int i = (x); i <= (y); ++ i)
#define int long long
using namespace std;
inline int read(){
	int x = 0 , f = 1;
	char c = getchar();
	while(c > '9' || c < '0') {
		if(c == '-') f = -f;
		c = getchar();
	}
	while(c <= '9' && c >= '0'){
		x = (x << 1) + (x << 3) + c - 48;
		c = getchar();
	}
	return x * f;
}
inline string readS(){
	string s = "";
	char c = getchar();
	while(c > 'z' || c < 'a') {
		c = getchar();
	}
	while(c <= 'z' && c >= 'a'){
		s . push_back(c);
		c = getchar();
	}
	return s;
}
const int N = 1e6 + 7;
string s[N] , t[N];
string x[N] , y[N];
inline bool chk(string & str){
	int x = 0;
	for(auto i : str){
		if(i != 'a' && i != 'b') return false;
		if(i == 'b') ++ x;
		if(x >= 2) return false; 
	} 
	if(!x) return false;
	return true;
}
inline int pos(string & str){
	int x = 0;
	for(auto i : str){
		if(i == 'b') {
			return x;
		}
		++ x;
	} 
	return 0;
}
struct Hash{
	int p1[N] , p2[N] , inv1[N] , inv2[N];
	const int P1 = 998244853, P2 = 1e9 + 7;
	const int base1 = 13331 , base2 = 37 , ib1 = 54214183 , ib2 = 621621626;
	inline void init(string &s){
		p1[0] = p2[0] = 0; inv1[0] = inv2[0] = 1;
		for(int i = 1; i <= (int)s . size(); ++ i){
			p1[i] = p1[i - 1] * base1 + s[i - 1] - 'a' + 1;
			p1[i] %= P1;
			p2[i] = p2[i - 1] * base2 + s[i - 1] - 'a' + 1;
			p2[i] %= P2;
			inv1[i] = inv1[i - 1] * base1; inv1[i] %= P1;
			inv2[i] = inv2[i - 1] * base2; inv2[i] %= P2;
			//cout << p1[i] << ' ' << p2[i] << ' ' << s[i - 1] << '\n';
		}
	}
	inline int calc(int l , int r){
		if(r < l) return -1;
		int cc = (p1[l - 1] * inv1[r - l + 1]) % P1;
		int ccc = (p2[l - 1] * inv2[r - l + 1]) % P2;
		int x = ((p1[r] - cc) % P1 + P1) % P1; x %= P1;
		int y = ((p2[r] - ccc) % P2 + P2) % P2; y %= P1;
		return x * y; 
	}
}A , B;
int n , m;
map<pair<int , int>  , int> sum;
inline int ok(int x , int y){
	if(x == -1 || y == -1) return 0;
	//cout << x << ' ' << y << '\n';
	return sum[{x, y}];
}
inline int query(string &x , string &y){
	A . init(x); B . init(y);
	int l = 0 , r = (int)x . size() - 1;
	while(l < x . size() && x[l] == y[l]) ++ l;
	while(r && x[r] == y[r]) -- r;
	-- l , ++ r; 
	int ans = 0;
	f(i , -1 , l){
		f(j , r , (int)x . size()){
 			ans += ok(A . calc(i + 1 + 1 , j) , B . calc(i + 1 + 1 , (int)y . size() - (int)x . size() + j)); 
		} 
	}
	return ans;
} 

namespace Solution{
	inline void solve(){
		n = read() , m = read();
		bool flg = 1;
		f(i , 1, n){
			string s = readS() , t = readS();
			flg &= chk(s) && chk(t);
			:: s[i] = s , :: t[i] = t;
		}
		f(i , 1, m){
			x[i] = readS() , y[i] = readS();
			flg &= chk(x[i]) && chk(y[i]);
		}
		if(flg){
			map<pair<int , int> , vector<pair<int , int> > > ty;
			f(i , 1, n){ 
				int px = pos(s[i]) , py = pos(t[i]);
				ty[{t[i] . size() - s[i] . size() , py - px}] . push_back({px , s[i] . size() - px});		
			}
			for(auto &tmp : ty){
				sort(tmp . second . begin() , tmp . second . end());
			}
			f(i , 1, m){
				int ans = 0;
				int px = pos(x[i]) , py = pos(y[i]);
				for(auto k : ty[{y[i] . size() - x[i] . size() , py - px}]){
					if(px < k . first) break;
					if(k . second <= x[i] . size() - px) ++ ans;
				}
				cout << ans << '\n';		
			}
		}
		else{
			f(i , 1, n){
				A . init(s[i]); B . init(t[i]);
			//	cerr << A . calc(1 , s[i] . size()) << ' ' << B . calc(1 , t[i] . size()) << ' '<< A . p1[s[i] . size()] * A .p2[s[i] . size()] << '\n';
				sum[make_pair(A . calc(1 , s[i] . size()) , B . calc(1 , t[i] . size()))] ++; 
			}
			f(i , 1, m){
				cout << query(x[i] , y[i]) << '\n';
			}
		} 
	}
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
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int T = 1;
	while(T --) Solution :: solve();
	return 0;
}

