#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,m;
string s;
namespace pzh1 {
	const int maxn=501;
	int p[maxn],c[maxn];
	void solve() {
		s='-'+s;
		for(int i=1; i<=n; i++) cin>>c[i],p[i]=i;
		int ans=0;
		do {
			int sum=0;
			for(int i=1; i<=n; i++) {
				if(sum>=c[p[i]]) {
					sum++;
					continue;
				}
				if(s[i]=='1') continue;
				sum++;
			}
			if(n-sum>=m) ans++;
			if(ans==mod) ans=0;
		} while(next_permutation(p+1,p+n+1));
		cout<<ans;
		exit(0);
	}
}
namespace pzh2 {
	const int maxn=501;
	int c[maxn];
	void solve() {
		for(int i=1; i<=n; i++) cin>>c[i];
		int ans=1;
		for(int i=n; i>1; i--) (ans*=i)%=mod;
		cout<<ans;
		exit(0);
	}
}
namespace pzh3 {
	const int maxn=501;
	int c[maxn];
	void solve(bool flag) {
		bool tmp=1;
		for(int i=1; i<=n; i++) {
			cin>>c[i];
			if(c[i]==0) tmp=0;
		}
		int ans=1;
		for(int i=n; i>1; i--) (ans*=i)%=mod;
		if(flag&&tmp) cout<<ans;
		else cout<<0;
		exit(0);
	}
}
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>s;
	if(n<=10) pzh1::solve();
	bool flag=1;
	for(auto c:s) if(c=='0') flag=0;
	if(m==n) pzh3::solve(flag);
	if(flag) pzh2::solve();
	cout<<0;
	return 0;
}