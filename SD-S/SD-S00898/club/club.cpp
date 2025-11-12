#include<bits/stdc++.h>//CSP-S2025 RP++
#define int long long
using namespace std;
struct node{
	int dt,id;
}b[100009];
int t,n,a[100009][5],ans,c[100009],dp[209][209][209];
bool cmp(node xxx,node yyy){
	return xxx.dt<yyy.dt; 
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		if(n>200){
			for(int i=1;i<=n;++i){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
				ans+=a[i][1];
				b[i].dt=a[i][1]-a[i][2];
				b[i].id=i;
				c[i]=1;
			}
			sort(b+1,b+n+1,cmp);
			for(int i=1;i+i<=n;++i){
				ans-=b[i].dt;
				c[b[i].id]=2;
			}
			cout<<ans<<'\n';
		}
		else{
			for(int i=1;i<=n;++i){
				cin>>a[i][1]>>a[i][2]>>a[i][3];
			}
			memset(dp,0,sizeof(dp));
			dp[1][0][0]=a[1][3];
			dp[1][1][0]=a[1][1];
			dp[1][0][1]=a[1][2];
			for(int i=2;i<=n;++i){
				for(int j=0;j<=i;++j){
					for(int k=0;k<=i;++k){
						if(j+k>n){
							break;
						}
						if(j){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
						}
						if(k){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
						}
						if(n-j-k>0){
							dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
						}
					}
				}
			}
			for(int i=0;i+i<=n;++i){
				for(int j=0;j+j<=n;++j){
					if(n-i-j<=(n>>1)){
						ans=max(ans,dp[n][i][j]);
					}
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;//NOIP2025 RP++
}
