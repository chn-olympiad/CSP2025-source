#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N=225;
int a[N][5],f[N],dp[N][N][N],ok1=1,ok2=1;
void XG(){
	ll n;
	cin>>n;
	ll mx=n/2;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
			if(j==2&&a[i][j]!=0) ok1=0;
			if(j==3&&a[i][j]!=0) ok2=0;
		}
	}
	if(ok1&&ok2){
		ll cnt=0;
		for(int i=1;i<=n;i++) f[i]=a[i][1];
		sort(f+1,f+n+1);
		for(int i=n;i>=n-mx+1;i--) cnt+=f[i];
		cout<<cnt<<endl;
	}else{
		memset(dp,0,sizeof(dp));
		for(ll i=1;i<=n;i++){
			for(int j=min(mx,i);j>=0;j--){
				for(int k=min(mx,i);k>=0;k--){
					if(j+k>i) continue;
					for(int l=min(mx,i);l>=0;l--){
						if(j+k+l>i) continue;
						if(j!=0)dp[j][k][l]=max(dp[j-1][k][l]+a[i][1],dp[j][k][l]);
						if(k!=0)dp[j][k][l]=max(dp[j][k-1][l]+a[i][2],dp[j][k][l]);
						if(l!=0)dp[j][k][l]=max(dp[j][k][l-1]+a[i][3],dp[j][k][l]);
					}
				} 
			} 
		}
		int ans=-1e9;
		for(int i=0;i<=mx;i++){
			for(int j=0;j<=mx;j++){
				int k=n-i-j;
				if(k>mx) continue;
				ans=max(ans,dp[i][j][k]);
			}
		}
		cout<<ans<<endl;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		XG();
	}
	return 0;
}