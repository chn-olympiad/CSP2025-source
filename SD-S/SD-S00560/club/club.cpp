#include<bits/stdc++.h>

using namespace std;

#define fst ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pii pair<int,int>
#define fi first
#define se second
#define endl '\n'

const int N=1e5+10;//×¢ÒâÐÞ¸Ä

bool ST;

int a[N][5];
int _; 
int n;
int p[N]; 

long long dp[205][5][205][205];

bool ED;


void solve(){
	cin>>n;
	long long maxn=0;
	int fa=0,fb=0;
	for(int i=1;i<=n;i++){
		cin>>a[i][1]>>a[i][2]>>a[i][3];
		maxn+=max({a[i][1],a[i][2],a[i][3]});
		if(a[i][2]) fa=1;
		if(a[i][3]) fb=1;
	}
	if(fa&&fb){
		int ans=0;
		for(int i=1;i<=n;i++){
			p[i]=a[i][1];
		}
		sort(p+1,p+1+n);
		for(int i=n;i>=n/2+1;i--){
			ans+=a[i][1];
		}
		cout<<ans<<endl;
		return ;
	}
	if(fb){
		
		return ;
	}
	if(n<=200){
		memset(dp,-0x3f,sizeof dp);
		dp[1][1][1][0]=a[1][1];
		dp[1][2][0][1]=a[1][2];
		dp[1][3][0][0]=a[1][3];
		for(int i=2;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					if(j) dp[i][1][j][k]=max({dp[i][1][j][k],a[i][1]+dp[i-1][1][j-1][k],a[i][1]+dp[i-1][2][j-1][k],a[i][1]+dp[i-1][3][j-1][k]});
					if(k) {
						dp[i][2][j][k]=max({dp[i][2][j][k],a[i][2]+dp[i-1][1][j][k-1],a[i][2]+dp[i-1][2][j][k-1],a[i][2]+dp[i-1][3][j][k-1]});
					}
				    dp[i][3][j][k]=max({dp[i][3][j][k],a[i][3]+dp[i-1][1][j][k],a[i][3]+dp[i-1][2][j][k],a[i][3]+dp[i-1][3][j][k]});
					
	//				cout<<i<<' '<<1<<' '<<j<<' '<<k<<' '<<dp[i][1][j][k]<<endl;
	//				cout<<i<<' '<<2<<' '<<j<<' '<<k<<' '<<dp[i][2][j][k]<<endl;
	//				cout<<i<<' '<<3<<' '<<j<<' '<<k<<' '<<dp[i][3][j][k]<<endl;
				}
			}
		}
		long long maxx=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if((n-i-j)>n/2) continue;
				maxx=max({maxx,dp[n][1][i][j],dp[n][2][i][j],dp[n][3][i][j]});
			}
		}
		cout<<maxx<<endl;
		return ;
	}
	cout<<maxn<<endl;
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
//	cout<<abs(&ED-&ST)/1024.0/1024.0<<endl;
	fst
	cin>>_;
	while(_--) solve();
	return 0;
} 
// Ren5Jie4Di4Ling5%
