#include <bits/stdc++.h>
using namespace std;
#define For(x,y,z) for(int x = y;x <= z;x++)
using ll = long long;

inline int read() {
	int x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

inline ll readl() {
	ll x = 0, f = 1;char ch;
	while((ch = getchar()) < '0' || ch > '9') if(ch == '-') f = -1;
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x * f;
}

int n,q;
string s[200010][3];
string t[200010][3];

const ll mod = 1e9+7,mod_ = 998244353;
ll sd1,sd2,sd3;

inline ll qp(ll a,ll b,ll md){
	ll ans = 1;
	while(b){
		if(b & 1) ans = (ans * a)%md;
		a *= a,a %= md;
		b >>= 1;
	}
	return ans;
}

struct hash{
	vector<ll> x1,x2,x3;
	int len;
	bool operator==(const hash &rhs) const{
		return len == rhs.len && x1[len-1] == rhs.x1[len-1] && x2[len-1] == rhs.x2[len-1] && x3[len-1] == rhs.x3[len-1];
	}
	void build(string inp){
		len = inp.length();
		ll p1 = 1,p2 = 1,p3 = 1;
		x1.resize(len),x2.resize(len),x3.resize(len);
		x1[0] = x2[0] = x3[0] = inp[0]-'a';
		For(i,1,len-1){
			x1[i] = (x1[i-1]+(i-'a')*(p1)%mod)%mod;
			x2[i] = (x2[i-1]+(i-'a')*(p2)%mod)%mod;
			x3[i] = (x3[i-1]+(i-'a')*(p3)%mod_)%mod_;
			p1 *= sd1,p1 %= mod;
			p2 *= sd2,p2 %= mod;
			p3 *= sd3,p3 %= mod_;
		}
	}
}S[200010][3],T[200010][3];

struct hash_key{
	int x1,x2,x3,len;
	
};

//inline void split(hash x,int l,int r,hash_key &ans){
//	ans.len = (r-l+1);
//	ans.x1 = (()*qp())%mod;
//}

mt19937 rnd(time(0));

void task1(){
	sd1 = rnd(),sd2 = rnd(),sd3 = rnd();
	For(i,1,n){
		S[i][1].build(s[i][1]),S[i][2].build(s[i][2]);
	}
	For(i,1,q){
		T[i][1].build(t[i][1]),T[i][2].build(t[i][2]);
	}
//	For(i,1,q){
//		For(j,0,len-1){
//			
//		}
//	}
}

int main() {
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
//	n=read(),q=read();
//	int L1 = 0,L2 = 0;
//	For(i,1,n){
//		cin >> s[i][1] >> s[i][2];
//		L1 += s[i][1].length();
//	}
//	For(i,1,q){
//		cin >> t[i][1] >> t[i][2];
//		L2 += t[i][1].length();
//	}
//	if(L1 <= 2000 && L2 <= 2000){
//		task1();
//	}
	return 0;
}