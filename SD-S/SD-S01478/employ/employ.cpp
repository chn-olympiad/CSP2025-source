#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define N 1000005
#define M 100005
#define mod 998244353
#define ls root<<1
#define rs root<<1|1
#define F first
#define S second
using namespace std;
ll n,m,a[505],b[505],ans;
string s;
ll mpow(ll x,ll y) {
	ll ans=1;
	while(y!=0) {
		if(y&1) ans=ans*x%mod;
		x=x*x%mod;
		y=y/2;
	}
	return ans;
}
int main() {
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=i;
	}
	if(n<=10) {
		do {
			ll cnt=0;
			for(int i=1; i<=n; i++) {
				if(a[b[i]]<=cnt) {
					cnt++;
				} else {
					if(s[i-1]=='0') {
						cnt++;
					}
				}
			}
			if(n-cnt>=m) {
				ans++;
				ans=ans%mod;
			}
		} while(next_permutation(b+1,b+1+n));
		cout<<ans%mod;
		return 0;
	}
	cout<<0;
	return 0;
}

