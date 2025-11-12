#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e3+5;
int n,ans;
int sum[maxn];
int a[maxn];
int f[maxn][maxn];
int mod=998244353;
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sum[0]=1;
	for(int i=1;i<=5000;i++){
		sum[i]=sum[i-1]*2;
		sum[i]%=mod;
	}
	sort(a+1,a+n+1);
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=5000;j>=0;j--){
			f[i][j]+=f[i-1][j];
			if(j>=a[i]) f[i][j]+=f[i-1][j-a[i]];
			f[i][j]%=mod;
		}
	}
	for(int i=3;i<=n;i++){
		ans+=sum[i-1];
		ans%=mod;
		for(int j=a[i];j>=0;j--){
			ans-=f[i-1][j];
			ans=(ans%mod+mod)%mod;
		}
	}
	cout<<ans;
	return 0;
}