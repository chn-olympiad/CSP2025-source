#include<bits/stdc++.h>
#define mn 511111
#define mod 998244353
using namespace std;
int n,k,a[5111],p[5111];
int main() {
	freopen("polygon.in","r",stdin),freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],p[i]=p[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++) {
		ans*=2,ans%=mod;
	}
	cout<<ans<<endl;
	fclose(stdin),fclose(stdout);
	return 0;
}