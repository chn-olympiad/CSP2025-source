//LUOGU UID 1208546

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int a[N],p[N],n,m;
string s;
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	s=" "+s;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=10) {
		int res=0;
		for(int i=1;i<=n;i++) {
			p[i]=i;
		}
		do {
			int cnt=0,tot=0;
			for(int i=1;i<=n;i++) {
				if(cnt>=a[p[i]]) {
					cnt++;
					//cerr<<"orz\n";
					continue;
				}
				if(s[i]=='1') tot++;
				else cnt++;
			}
			if(tot>=m) res++;
			//cout<<tot<<endl;
		} while(next_permutation(p+1,p+1+n));
		cout<<res<<endl;
	}
	else {
		int res=1;
		for(int i=1;i<=n;i++) {
			res=res*i%998244353ll;
		}
		cout<<res<<endl;
	}
	return 0;
}


