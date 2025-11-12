#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=998244353;
ll dp[50005][105];bool vis[50005];
int a[5005];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;cin>>n;int sum=0,mx=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dp,-0x3f,sizeof dp);
	dp[0][0]=1;vis[0]=1;
	//set<set<int> >s;
	for(int i=1;i<=n;i++){
		sum+=a[i];mx=max(mx,a[i]);
		for(int j=sum;j>=0;j--){
			if(!vis[j])continue;
			for(int k=0;k<=mx;k++){
				if(dp[j][k]>=0){
					int x=j+a[i],y=max(k,a[i]);
					dp[x][y]=max(dp[x][y],(ll)0);
					dp[x][y]+=dp[j][k];//cout<<j+a[i]<<" "<<max(k,a[i])<<" "<<dp[j+a[i]][max(k,a[i])]<<endl;
					dp[x][y]%=mod;
					vis[j+a[i]]=1;
					//cout<<j<<" "<<k<<endl;
				}
			}
		}
	}
	int ans=0;
	for(int i=0;i<=50000;i++){
		if(!vis[i])continue;
		for(int j=0;j*2<i and j<102;j++)ans+=max((ll)0,dp[i][j]),ans%=mod;
	}
	cout<<ans;
	return 0;
}