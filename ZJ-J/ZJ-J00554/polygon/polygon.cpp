//²»ÒªÊä¡£
#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
int n,a[5005];
long long po[5005];
long long dp1[5005][5005],dp2[5005][5005],ans;
void init(){ for(int i=1;i<=n;i++) po[i]=(po[i-1]<<1)%mod; }
void solve(){
	cin>>n;
	po[0]=1,init();
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=0;i<a[1];i++) dp1[i][1]=dp2[i][1]=1;
	for(int j=2;j<=n;j++){
		for(int i=0;i<a[j];i++) dp1[i][j]=po[j-1],dp2[i][j]=(dp2[i][j-1]+po[j-1])%mod;
		for(int i=a[j];i<=a[n];i++) dp1[i][j]=dp2[i-a[j]][j-1],dp2[i][j]=(dp2[i-a[j]][j-1]+dp2[i][j-1])%mod;
	}
	for(int i=3;i<=n;i++) (ans+=dp2[a[i]][i-1])%=mod;
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--) solve();
	return 0;
}
