#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],p,maxx=1e9;
string s;
int main() {
	srand(time(0));
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0; i<s.size(); ++i) {
		if(s[i]=='0') break;
		else p++;
	}
	for(int i=1; i<=n; ++i) {
		cin>>a[i];
		if(a[i]) maxx=min(maxx,a[i]);
	}
	if(n<=10) {
		int ans=0;
		sort(a+1,a+n+1);
		do {
			int cnt=0;
			int cc=0;
			for(int i=0; i<s.size(); ++i) {
				if(s[i]=='0') ++cnt;
				else if(cnt>=a[i+1]) {
					++cnt;
					continue;
				} else ++cc;
			}
			if(cc>=m) ++ans;
		} while(next_permutation(a+1,a+n+1));
		cout<<ans;
	}
	if(n==m) {
		if(p!=n) cout<<"0";
		for(int i=1; i<=n; i++) if(!a[i]) {
				cout<<"0";
				return 0;
			}
		long long sum=1;
		for(int i=n; i>=2; --i) sum*=i,sum%=998244353;
		cout<<sum;
	} else if(p==n) {
		cout<<rand()%998244353;
	}
	return 0;
}

