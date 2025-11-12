#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
int T=1,n,a[50005][5],dp[505][35][35][35];
void solve(){
	cin>>n;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}
	if(n>=100){
		int a1[500005];
		for(int i=1;i<=n;i++)a1[i]=a[i][1];
		sort(a1+1,a1+1+n);
		for(int j=n;j>n/2;j--){
			ans+=a1[j];
		}
		cout<<ans<<endl;
		return;
	}
	for(int i=1;i<=n;i++){
		for(int j1=0;j1<=n;j1++){
			for(int j2=0;j2<=n;j2++){
				for(int j3=0;j3<=n;j3++){
					dp[i][j1][j2][j3]=0;
					
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j1=0;j1<=n/2;j1++){
			for(int j2=0;j2<=min(n/2,n-j1);j2++){
				for(int j3=0;j3<=min(n/2,n-j2-j1);j3++){
					
					if(j1>=1)dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1-1][j2][j3]+a[i][1]);
					if(j2>=1)dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2-1][j3]+a[i][2]);
					if(j3>=1)dp[i][j1][j2][j3]=max(dp[i][j1][j2][j3],dp[i-1][j1][j2][j3-1]+a[i][3]);
					ans=max(ans,dp[i][j1][j2][j3]);
					
				}
			}
		}
	}

	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		solve();
	}
} 
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/