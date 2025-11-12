#include<bits/stdc++.h>
using namespace std;

const int mod=998244353;
int n,m,ct1,c0;
string s;
int c[505],a[505],cnt,fq;
long long ans=0;
signed main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>s;
	for(int i=1; i<=n; i++) {
		cin>>c[i];
		if(c[i]==0)c0++;
		a[i]=i;
	}
	for(int i=0; i<n; i++) {
		if(s[i]=='1')ct1++;
	}
	if(n==m) {
		if(c0||ct1!=n) {
			cout<<0;
			return 0;
		} else {
			ans=1;
			for(int i=1; i<=n; i++) {
				ans=(ans*i)%mod;
			}
			cout<<ans;
			return 0;
		}
	}
	if(n<=10) {
		do {
			cnt=0;
			fq=0;//fangqi||beiju
			for(int i=1; i<=n; i++) {
				if(fq>=c[a[i]]||s[i-1]=='0') {
					fq++;
				} else cnt++;
			}
			if(cnt>=m)ans=(ans+1)%mod;
		} while(next_permutation(a+1,a+n+1));
		cout<<ans;
		return 0;
	}
	//down
	if(ct1==n) {
		int l=n-c0;
		if(l<m) {
			cout<<0;
			return 0;
		} else {
			sort(c+1,c+n+1);
			ans=1;
			for(int i=1; i<=n; i++) {
				ans=(ans*i)%mod;
			}
			cout<<ans;
		}
	} else cout<<0;
	return 0;
}


