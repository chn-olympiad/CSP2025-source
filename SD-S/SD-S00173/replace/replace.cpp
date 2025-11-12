#include<bits/stdc++.h>
#define int long long
using namespace std;
const int B=13331,mod=1000000007,N=200005;
int n,q;
string s[2],t[2];
string a[2][N];
int fac[N];
int ha[2][N];
inline int getha(int op,int l,int r) {
	return (ha[op][r]-ha[op][l-1]*fac[r-l+1]%mod+mod)%mod;
}
unordered_map<int,int>mp;
inline int hax(int x,int y) {
	return x*mod+y;
}
signed main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	std::ios::sync_with_stdio(0),cin.tie(0);
	cin>>n>>q;
	if(q==1) {
		int ans=0;
		for(int i=1; i<=n; ++i) {
			cin>>a[0][i]>>a[1][i];
		}
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()) {
			cout<<"0";
			return 0;
		}
		int len=t[0].size();
		t[0]=" "+t[0],t[1]=" "+t[1];
		int pos[2]= {0};
		for(int i=1; i<=len; ++i) {
			for(int x=0; x<2; ++x) if(t[x][i]=='b') pos[x]=i;
		}
		for(int i=1; i<=n; ++i) {
			int m=a[0][i].size();
			a[0][i]=" "+a[0][i],a[1][i]=" "+a[1][i];
			int p[2]= {0};
			for(int j=1; j<=m; ++j) {
				for(int x=0; x<2; ++x) if(a[x][i][j]=='b') p[x]=j;
			}
			if(p[0]-p[1]==pos[0]-pos[1]&&pos[0]>=p[0]&&len-pos[0]>=m-p[0]) ++ans;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1; i<=n; ++i) {
		int ha[2];
		ha[0]=ha[1]=0;
		for(int x=0; x<2; ++x) {
			cin>>s[x];
			int m=s[x].size();
			s[x]=" "+s[x];
			for(int j=1; j<=m; ++j) {
				ha[x]=(ha[x]*B+s[x][j])%mod;
			}
		}
		++mp[hax(ha[0],ha[1])];
	}
	fac[0]=1;
	for(int i=1; i<N; ++i) {
		fac[i]=fac[i-1]*B%mod;
	}
	while(q--) {
		cin>>t[0]>>t[1];
		if(t[0].size()!=t[1].size()) {
			cout<<"0\n";
			continue;
		}
		int m=t[0].size();
		t[0]=" "+t[0],t[1]=" "+t[1];
		int l=0,r=m+1;
		for(int i=1; i<=m; ++i) {
			if(t[0][i]!=t[1][i]) {
				l=i;
				break;
			}
		}
		for(int i=m; i>=1; --i) {
			if(t[0][i]!=t[1][i]) {
				r=i;
				break;
			}
		}
//		cout<<l<<" "<<r<<"\n";
		for(int i=1; i<=m; ++i) {
			for(int x=0; x<2; ++x) {
				ha[x][i]=(ha[x][i-1]*B+t[x][i])%mod;
			}
		}
		//for 25 pts
		int cnt=0;
		for(int i=1; i<=l; ++i) {
			for(int j=r; j<=m; ++j) {
				int h=hax(getha(0,i,j),getha(1,i,j));
				if(mp.find(h)!=mp.end()) cnt+=mp[h];
			}
		}
		cout<<cnt<<"\n";
	}
	return 0;
}

