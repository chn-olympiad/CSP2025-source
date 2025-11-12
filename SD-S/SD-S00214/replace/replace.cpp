#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
typedef pair<long long,long long> pll;
const ll mod1=100205023,mod2=114514003,base=701;
//const ll mod1=100000000,mod2=100000000,base=100;
int n,q;
string s[200011],t[200011];
string a,b;
pll gethash(string&x) {
	pll ans= {0,0};
	int len=x.size();
	for(int i=0; i<len; i++) {
		ans= {(ans.fi*base+x[i])%mod1,(ans.se*base+x[i])%mod2};
	}
	return ans;
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>q;
	for(int i=1; i<=n; i++)
		cin>>s[i]>>t[i];
	while(q--) {
		cin>>a>>b;
		int lena=a.size();
		pll ha=gethash(a),hb=gethash(b);
		int ans=0;
		for(int i=1; i<=n; i++) {
			int len=s[i].size();
			pll bbase= {1,1};
			pll x=gethash(s[i]),y=gethash(t[i]),p= {0,0};
			int gder=min(len,lena);
			for(int j=0; j<gder; j++)
				p= {(p.fi*base+a[j])%mod1,(p.se*base+a[j])%mod2};
			for(int j=1; j<gder; j++)bbase= {bbase.fi*base%mod1,bbase.se*base%mod2};
			if(p==x) {
				pll now= {(ha.fi-x.fi+y.fi+mod1)%mod1,(ha.se-x.se+y.se+mod2)%mod2};
				if(now==hb)ans++;
			}
			pll bbbase= {1,1};
			for(int j=len; j<lena; j++) {
				p= {((p.fi-bbase.fi*a[j-len]%mod1+mod1)%mod1*base+a[j])%mod1,
				    ((p.se-bbase.se*a[j-len]%mod2+mod2)%mod2*base+a[j])%mod2
				   };
				if(p==x) {
					pll now= {(ha.fi+bbbase.fi*((mod1+y.fi-p.fi)%mod1)%mod1)%mod1,
					          (ha.se+bbbase.se*((mod2+y.se-p.se)%mod2)%mod2)%mod2
					         };
					if(now==hb)ans++;
				}
				bbbase= {bbbase.fi*base%mod1,bbbase.se*base%mod2};
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
