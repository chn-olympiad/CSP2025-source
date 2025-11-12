#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
const int mod=998244353;
int n,a[N],maxn=INT_MIN,cnt,sum[N];
long long ans;
int main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==1) {
			cnt++;
		}
	}
	for(int i=1; i<=5000; i++) {
		sum[i]=sum[i-1]+i;
	}
	if(n==3) {
		if(a[1]+a[2]>a[3]*2) {
			cout<<1;
		} else {
			cout<<0;
		}
		return 0;
	}
	if(cnt==n) {
		for(int bian=3; bian<=n; bian++) {
			for(int i=1; i<=n-bian+1; i++) {
				ans+=sum[i];
				ans%=mod;
			}
		}
		cout<<ans%mod;
		return 0;
	}
	return 0;
}