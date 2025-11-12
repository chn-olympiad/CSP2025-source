#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned ll
#define gc getchar()
#define pull pair<ull,ull>
#define pb push_back
#define id second
#define val first
#define mkp makepair
const ll maxn=2e5+1010,mod=998244353,INF=1e18+1010;
inline void read(ll &x) {
	x=0;
	char ch=gc;
	while(ch<'0'||ch>'9')ch=gc;
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=gc;
}
ull f[200],g[200];
ull base1=998244353,base2=1000000007;
map<pull,ll> hsh;
void init() {
	f[0]=11451;
	g[0]=12387;
	for(int i=1; i<=150; i++)f[i]=f[i-1]*5482683+2147641,g[i]=g[i-1]*1247897+342678621;
}
ull qpow(ull a,ll b) {
	ull res=0;
	while(b) {
		if(b&1)res=res*a;
		b>>=1;
		a=a*a;
	}
	return res;
}
ull trans1(string s) {
	ull res=0;
	for(int i=0; i<s.size(); i++) {
		res*=base1;
		res+=f[s[i]];
	}
	return res;
}
ull trans2(string s) {
	ull res=0;
	for(int i=0; i<s.size(); i++) {
		res*=base2;
		res+=g[s[i]];
	}
	return res;
}
ll n,q,l,r,ans;
string s1,s2;
ull w1,w2;
ull fo1,fo2;
pull tmp;
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	init();
	read(n);
	read(q);
	for(int i=1; i<=n; i++) {
		cin>>s1>>s2;

		tmp= {trans1(s1),trans2(s2)};
		hsh[tmp]+=1;
	}
	while(q--)
	{
		cin>>s1>>s2;
		if(s1.size()!=s2.size()){
			printf("0\n");
			continue;
		}
		l=0;
		r=s1.size()-1;
		while(l<s1.size()&&s1[l]==s2[l])l++;
		while(r>=0&&s1[r]==s2[r])r--;
		w1=w2=0;
		for(int i=l+1; i<=r-1; i++) {
			w1*=base1;
			w2*=base2;
			w1=f[s1[i]]+w1;
			w2=g[s2[i]]+w2;
		}
		for(int i=l; i>=0; i--) {
			w1+=qpow(base1,r-i)*f[s1[i]];
			w2+=qpow(base2,r-i)*g[s2[i]];
			fo1=w1;
			fo2=w2;
			for(int j=r; j<s1.size(); j++) {
				fo1*=base1;
				fo2*=base2;
				fo1+=f[s1[j]];
				fo2+=g[s2[j]];
			//	printf("%lld\n",fo1);
				ans+=hsh[{fo1,fo2}];
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
