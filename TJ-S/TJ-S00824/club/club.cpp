#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define cin in
#define cout out
#define endl '\n'
int n;
int a[100005][3]={};
int dp[2005][1005]={};
ll dfs(int as,int bs,int cs){
	if(as+bs+cs==n){
		return 0;
	}
	ll ma=0;
	if(as!=n/2){
		ma=max(ma,dfs(as+1,bs,cs)+a[as+bs+cs][0]);
	}
	if(bs!=n/2){
		ma=max(ma,dfs(as,bs+1,cs)+a[as+bs+cs][1]);
	}
	if(cs!=n/2){ 
		ma=max(ma,dfs(as,bs,cs+1)+a[as+bs+cs][2 ]);
	}
	return ma;
}
int main(){
	fstream in,out;
	in.open("club.in",ios::in);
	out.open("club.out",ios::out);
	int T;
	cin >> T;
	while(T--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> a[i][0] >> a[i][1] >> a[i][2];
		}

		if(n<=28){
			cout << dfs(0,0,0) << endl;
		}else{
			for(int i=1;i<=n/2;i++){
				for(int k=0;k<n;k++){
					if(k==0){
						dp[i][k]=max(a[k][0],dp[i-1][k]);
					}else if(i==1){
						dp[i][k]=max(dp[i][k-1],a[k][0]);
					}else{
						dp[i][k]=max(dp[i][k-1],max(-1,dp[i-1][k-1]+a[k][0]));
					}
				}
			}
			for(int i=n/2+1;i<=n;i++){
				for(int k=0;k<n;k++){
					if(k==0){
						dp[i][k]=max(a[k][1],dp[i-1][k]);
					}else{
						dp[i][k]=max(dp[i][k-1],max(-1,dp[i-1][k-1]+a[k][1]));
					}
				}
			}
			for(int i=n;i<=n+n/2;i++){
				for(int k=0;k<n;k++){
					if(k==0){
						dp[i][k]=max(a[k][2],dp[i-1][k]);
					}else{
						dp[i][k]=max(dp[i][k-1],max(-1,dp[i-1][k-1]+a[k][2]));
					}
				}
			}
			cout << dp[n+n/2][n-1] << endl;
		}
	}
	return 0;
}