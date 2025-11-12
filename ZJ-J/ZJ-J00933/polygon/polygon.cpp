#include<bits/stdc++.h>//¡È ©P¡ê!
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define OpenFile(_) freopen(#_ ".in","r",stdin);freopen(#_ ".out","w",stdout)
typedef long long Int;
const Int Mod=998244353;

Int n,a[5005],dp[5005],ans=0;

int main(){
	IOS;OpenFile(polygon);

	cin>>n;
	for(Int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	dp[0]=1;
	for(Int i=1;i<=n;i++){
		ans=(ans+dp[a[i]+1])%Mod;
		for(Int j=5001;j>=0;j--)dp[j]=(dp[j]+dp[max(0ll,j-a[i])])%Mod;
	}
	cout<<ans<<endl;

	return 0;
}
