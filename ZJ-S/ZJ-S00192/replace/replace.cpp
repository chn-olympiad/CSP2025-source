#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define repp(i,x,y) for(int i=x;i>=y;--i)
#define ll long long
#define scan scanf
#define prin printf
using namespace std;
const int N=2e5;
int n;
string a[N+100],b[N+100];
void solve() {
	string st,ed;
	cin>>st>>ed;
	int ans=0;
	rep(i,1,n) {
		string s=st;
		rep(j,0,s.size()-1) {
			bool f=1;
			rep(k,0,a[i].size()-1)
				if(s[j+k]!=a[i][k]) {
					f=0;
					break;
				}
			if(f) {
				string s0=s;
				rep(k,0,a[i].size()-1)
					s0[j+k]=b[i][k];
				if(s0==ed) ++ans;
			}
		}
	}
	prin("%d\n",ans);
}
int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int q;
	scan("%d%d",&n,&q);
	rep(i,1,n) cin>>a[i]>>b[i];
	while(q--) solve();
	return 0;
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
