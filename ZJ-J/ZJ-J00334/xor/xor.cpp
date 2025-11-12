#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,N2=1e3+1;
bool flagb,flagc,vis[N];
int n,k,a[N],b[N2][N2],dp[N2][N2];
inline void solve(){
	if(!flagb){
		if(k==1){
			int cln=n;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cln--;
				}
			}
			cout<<cln;
			return;
		}
		else{
			int	cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==0){
					cnt++;
				}
				else{
					if(a[i-1]==1){
						if(!vis[i-1]){	
							cnt++;
							vis[i]=true;
						}
					}
				}
			}
			cout<<cnt;
			return;
		}
	}
	if(!flagc){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				b[i][j]=a[i]^b[i-1][j];
			}
	 }
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(b[i][j]==k){
					dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j-1],dp[i-1][j]);
				}
			}
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,dp[n][i]);
		}
		cout<<ans;
	}
	return;
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!flagc){
			if(a[i]>255){
				flagc=true;
			}
			else{
				if(!flagb){	
					if(a[i]>1){
						flagb=true;
					}
				}
			}
		}
	}
	solve();
	return 0;
}
