#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int N=5010;
int n,a[N],dp[N][N],mx,ans,d[N],c;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
		for(int j=0;j<a[i];j++){
			dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=mx;j++){
			if(j-a[i]<0){
				dp[i][j]=(dp[i][j]+c)%mod;
			}else
			dp[i][j]=(dp[i][j]+d[j-a[i]])%mod;
		}for(int j=0;j<=mx;j++){
			d[j]+=dp[i][j];
			d[j]%=mod;
		}
		c+=dp[i][0];
		c%=mod;
	}for(int i=3;i<=n;i++){
		for(int j=0;j<i;j++){
			ans+=dp[j][a[i]];
			ans%=mod;
		}
	}cout<<ans;
	return 0;
}
