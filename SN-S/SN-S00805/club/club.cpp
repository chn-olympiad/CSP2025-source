#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,t,a[510][510],ans;
void dfs(int k,int sum,int one,int two,int thr){
	if(k==n+1){
		ans=max(ans,sum);
		return;
	}
	if(one+1<=n/2)dfs(k+1,sum+a[k][1],one+1,two,thr);
	if(two+1<=n/2)dfs(k+1,sum+a[k][2],one,two+1,thr);
	if(thr+1<=n/2)dfs(k+1,sum+a[k][3],one,two,thr+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
 	cin>>t;
 	while(t--){
 		cin>>n;
 		ans=0;
 		for(int i=1;i<=n;i++){
 			for(int j=1;j<=3;j++)cin>>a[i][j];
		}
 		dfs(1,0,0,0,0);
 		cout<<ans<<endl;
	}
	return 0;
}
