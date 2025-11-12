#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,k;
int a[N],sum[N],dp[N][N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		sum[i]=sum[i-1]^a[i]; 
		if(a[i]==k) dp[i][i]=1;
	}
	int ans=0;
	if(mx==1){
		if(k==1){
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
		}else if(k==0){
			int la=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
				if(la==1&&a[i]==1){
					ans++;
					a[i]=0;
				}
				la=a[i];
			}
		}
	}else{
		for(int len=1;len<=n;len++){
			for(int l=1;l+len-1<=n;l++){
				int r=l+len-1;
				for(int k=l;k<r;k++){
					dp[l][r]=max(dp[l][r],dp[l][k]+dp[k+1][r]);
				}
				if(!dp[l][r]) dp[l][r]=((sum[r]^sum[l-1])==k);
				ans=max(ans,dp[l][r]);
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
