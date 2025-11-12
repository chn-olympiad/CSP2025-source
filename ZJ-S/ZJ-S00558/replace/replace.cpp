#include <bits/stdc++.h>
using namespace std;
const int N=200025,M=1e6+5,K=12,mod1=1e9+7,mod2=20090723,p=151;
using ll=long long;
using pii=array<int,2>;
using piii=array<int,3>;
using piiii=array<int,4>;
using pll=array<ll,2>;
using plll=array<ll,3>;
//int read() {
//	int res=0,f=1;
//	char ch=getchar();
//	while(!isdigit(ch))f=(ch=='-'?-1:1),ch=getchar();
//	while(isdigit(ch))res=res*10+ch-'0',ch=getchar();
//	return res*f;
//}
int pw1[N],pw2[N];
int n,q,sz[N],C;
string s[N][2],t[2];
struct hsh {
	vector<ll> h1,h2;
	void init(const string &s) {
		h1.resize(s.size());
		h2.resize(s.size());
		for(int i=1; i<s.size(); i++) {
			h1[i]=(h1[i-1]*p+s[i])%mod1;
			h2[i]=(h2[i-1]*p+s[i])%mod2;
		}
	}
	pll get(int l,int r) {
		if(l>r)return {0,0};
		return {(h1[r]-h1[l-1]*pw1[r-l+1]%mod1+mod1)%mod1,(h2[r]-h2[l-1]*pw2[r-l+1]%mod2+mod2)%mod2};
	}
	pll get2() {
		return {h1.back(),h2.back()};
	}
} h[N][2],H[2];
mt19937_64 rnd(time(0));
struct hshf {
	ll operator()(const pll &a) {
		return (a[1]<<32ll)+a[0];
	}
};
unordered_map<pll,int,hshf> mp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>q;
	pw1[0]=pw2[0]=1;
	for(int i=1; i<=n; i++)pw1[i]=pw1[i-1]*p%mod1,pw2[i]=pw2[i-1]*p%mod2;
	for(int i=1; i<=n; i++)cin>>s[i][0]>>s[i][1],sz[i]=s[i][0].size(),s[i][0]='@'+s[i][0],s[i][1]='@'+s[i][1],C+=sz[i];
//	cerr<<"len "<<C<<'\n';
	for(int i=1; i<=n; i++) {
		h[i][0].init(s[i][0]);
		h[i][1].init(s[i][1]);
	}
	for(int i=1,ans=0; i<=q; i++) {
		cin>>t[0]>>t[1];
		int len=t[0].size();
		t[0]='@'+t[0],t[1]='@'+t[1];
		H[0].init(t[0]),H[1].init(t[1]);
		ans=0;
		for(int j=len; j; j--) {
			for(int k=1; k<=n; k++) {
				if(j+sz[k]-1>len)continue;
				if(		H[0].get(1,j-1)==H[1].get(1,j-1)
				  &&	H[0].get(j,j+sz[k]-1)==h[k][0].get2()
				  &&	H[1].get(j,j+sz[k]-1)==h[k][1].get2()
				  &&	H[0].get(j+sz[k],len)==H[1].get(j+sz[k],len))ans++;
			}
		}
		cout<<ans<<'\n';
	}
}