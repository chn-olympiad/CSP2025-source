#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;
const ll N=1e5;
ll T,n;
ll a[N],b[N],c[N];
ll maxn;
ll cnt[3],cnt2,cnt3;
ll ans1,ans2,ans3;
ll dp[1000][1000];
ll ans[N][3];
ll num[N][3];
void dfs(ll x,ll sum,ll cnt[]){
	if(x==n+1){
		if(sum>maxn){
			maxn=sum;
		}
		return;
	}
	for(ll i=1;i<=3;i++){
		if(cnt[i]<n/2){
			cnt[i]++;
			dfs(x+1,sum+ans[x][i],cnt);
		}
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--){
		cin>>n;
		maxn=0;
		memset(dp,0,sizeof dp);
		for(ll i=1;i<=n;i++){
			for(ll j=1;j<=3;j++){
				cin>>num[i][j];
			}
		}
		for(ll i=1;i<=3;i++){
			dp[1][i]=num[1][i]; 
		}
		for(ll i=2;i<=n;i++){
			for(ll j=1;j<=3;j++){
				if(cnt[j]<n/2){
					cnt[j]++;
					ll k=dp[i][j];
				 	dp[i][j]=max(dp[i-1][1],max(dp[i-1][2],dp[i-1][3]));
					dp[i][j]+=k;
				}else{
					if(j==1){
						ll k=dp[i][j];
				 		dp[i][j]=max(dp[i-1][2],dp[i-1][3]);
						dp[i][j]+=k;
					}
					if(j==2){
						ll k=dp[i][j];
				 		dp[i][j]=max(dp[i-1][1],dp[i-1][3]);
						dp[i][j]+=k;
					}
					if(j==3){
						ll k=dp[i][j];
				 		dp[i][j]=max(dp[i-1][1],dp[i-1][2]);
						dp[i][j]+=k;
					}
				}
				
			}
		}
		maxn=max(dp[n][1],max(dp[n][2],dp[n][3]));
		cout<<maxn<<endl;
	}
	return 0;
}
