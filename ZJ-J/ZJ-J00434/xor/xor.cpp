#include<bits/stdc++.h>
using namespace std;
#define f(i,x,y) for(int i=x;i<=y;i++)
map<int,map<int,int> > mp;
int a[500020];
int ans=0;
int n,k;
int dp[500020];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	f(i,1,n) cin>>a[i];
	f(i,1,n){
		int now=0;
		f(j,0,n-i){
			now^=a[i+j];
			mp[i][i+j]=now;
		}
	}
	f(i,1,n){
		dp[i]=max(dp[i],dp[i-1]);
		ans=max(ans,dp[i]);
		f(j,i,n){
			if(mp[i][j]==k){
				dp[j+1]=max(dp[j+1],dp[i]+1);
			}
		}
	}
	ans=max(ans,dp[n+1]);
	cout<<ans;
	return 0;
}
