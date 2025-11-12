#include<bits/stdc++.h>
using namespace std;
#define N 10005
#define fi first
#define se second
#define ll long long
#define inf 0x3f3f3f3f
#define pii pair<int,int>
int t;
int n;
int flo;
int peo[N][4];
int dp[N][4][N/2];
int maxn[N][4];
int ans;
int vis[4];
int sum;
//20
void dfs(int x){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(vis[i]>=flo){
			continue;
		}
		sum+=peo[x][i];
		vis[i]++;
		dfs(x+1);
		vis[i]--;
		sum-=peo[x][i];
	}
}

void slove();

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>peo[i][1]>>peo[i][2]>>peo[i][3];
		}
		flo=n/2;
		if(n<=20){
			ans=0;
			sum=0;
			dfs(1);
			cout<<ans<<"\n";
			continue;
		}
		slove();
		cout<<max({maxn[n][1],maxn[n][2],maxn[n][3]})<<"\n";
	}
	return 0;
}

void slove(){
	memset(maxn,0,sizeof maxn);
	memset(dp,0,sizeof dp);
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			dp[i][j][0]=peo[i][j];
			maxn[i][j]=max(maxn[i][j],dp[i][j][0]);
		}
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			for(int k=1;k<flo;k++){
				if(j==1){
					dp[i][j][k]=max({dp[i-1][j][k-1],maxn[i-1][2],maxn[i-1][3]})+peo[i][j];
				}
				if(j==2){
					dp[i][j][k]=max({dp[i-1][j][k-1],maxn[i-1][1],maxn[i-1][3]})+peo[i][j];
				}
				if(j==3){
					dp[i][j][k]=max({dp[i-1][j][k-1],maxn[i-1][2],maxn[i-1][1]})+peo[i][j];
				}
			}
			for(int k=1;k<flo;k++){
				maxn[i][j]=max(maxn[i][j],dp[i][j][k]);
			}
		}
	}
}

