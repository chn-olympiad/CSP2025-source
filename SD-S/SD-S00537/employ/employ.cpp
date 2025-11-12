#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int p[505],c[505];
string s;
bool bo=true;
const int mod=998244353;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++)cin>>c[i];
	int ans=0;
	s=" "+s;
	for(int i=1; i<=n; i++)p[i]=i;
	do {
		int cnt=0,lq=0;
		for(int i=1; i<=n; i++) {
			if(cnt>=c[p[i]])cnt++;
			else if(s[i]=='0')cnt++;
			else lq++;
		}
		if(lq>=m)ans=(ans+1)%mod;
	} while(next_permutation(p+1,p+1+n));
	cout<<ans;
	return 0;
}
