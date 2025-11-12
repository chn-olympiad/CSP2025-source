#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5001,maxV=5e4+1,mod=998244353;
int n,a[maxn];
int f[maxV];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,ans=0;
	f[0]=1;
	for(int i=1; i<=n; i++) {
		sum+=a[i];
		for(int j=a[i]+1; j<=sum-a[i]; j++) (ans+=f[j])%=mod;
		for(int j=sum; j>=a[i]; j--) (f[j]+=f[j-a[i]])%=mod;
	}
	cout<<ans;
	return 0;
}
