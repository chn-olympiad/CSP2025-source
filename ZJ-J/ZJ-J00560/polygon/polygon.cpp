#include<bits/stdc++.h>
using namespace std;
const int N=5e3+7;
const int mod=998244353;
int n,m,ans;
int a[N],f[2][3][2*N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
	int mx=5e3+1;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	f[0][0][0]=1;int fl=0;
	for(int i=1;i<=n;i++){
		fl^=1;
		for(int j=a[i]+1;j<=mx;j++)ans=(ans+f[fl^1][2][j])%mod;
		for(int j=0;j<=mx;j++)for(int k=0;k<=2;k++)f[fl][k][j]=f[fl^1][k][j];
		for(int j=mx+a[i];j>=a[i];--j){
			for(int k=3;k;k--){
				f[fl][min(k,2)][min(j,mx)]=(f[fl][min(k,2)][min(j,mx)]+f[fl^1][k-1][j-a[i]])%mod;
			}
		}
	}
	cout<<ans;
}