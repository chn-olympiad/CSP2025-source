#include<bits/stdc++.h>
#include<bits/extc++.h>
//#define int long long 
#define pb push_back
#define eb emplace_back
#define pii pair<int,int>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define Rep(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
using namespace __gnu_pbds;
//typedef long long ll;
const int N=5e6+10;
const int mod=1e9+7;
const int p=13331;

int n,m;
int e[N],cnt;
int hs1[N],hs2[N],fac[N];
gp_hash_table<int,int> a[N];
gp_hash_table<int,int> pos;
inline int gethash(string s) {
	int res=0;
	for (auto ch : s) res=(1ll*res*p%mod+ch)%mod;
	return res;
}
inline int query1(int l,int r) {
	if (l>r) return 0;
	return ((1ll*hs1[r]-1ll*hs1[l-1]*fac[r-l+1]%mod)%mod+mod)%mod;
}
inline int query2(int l,int r) {
	if (l>r) return 0;
	return ((1ll*hs2[r]-1ll*hs2[l-1]*fac[r-l+1]%mod)%mod+mod)%mod;
}
inline void init() {
	const int up=5e6;
	fac[0]=1;
	rep(i,1,up) fac[i]=1ll*fac[i-1]*p%mod;
	return ;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;init();
	rep(i,1,n) {
		string t,b;cin>>t;cin>>b;
		int x=gethash(t);
		if (!pos[x]) pos[x]=++cnt;
		a[pos[x]][gethash(b)]++;
	}
	while (m--) {
		string x,y;cin>>x>>y;
		int len=x.size();
		x=" "+x,y=" "+y;
		rep(i,1,len) hs1[i]=(1ll*hs1[i-1]*p%mod+x[i])%mod;
		rep(i,1,len) hs2[i]=(1ll*hs2[i-1]*p%mod+y[i])%mod;
		int res=0;
		rep(i,1,len) {
			if (query1(i+1,len)!=query2(i+1,len)) continue;
			rep(j,1,i) {
				if (query1(1,j-1)!=query2(1,j-1)) break;
				if (pos.find(query1(j,i))==pos.end()) continue;
				if (a[pos[query1(j,i)]].find(query2(j,i))!=a[pos[query1(j,i)]].end()) res+=a[pos[query1(j,i)]][query2(j,i)]; 
			}
		}
		cout<<res<<endl;
	}
	return 0;
}
/*
查询有多少个子区间的值为 
*/