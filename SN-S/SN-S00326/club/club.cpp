#include<bits/stdc++.h>
#define int long long
using namespace std;
//像反悔贪心？ 我不会！！！ 
long long t,n,a[100005][4],ans;
void dfs(int tot,int xp,int yp,int zp){
	if(xp>n/2) return;
	if(yp>n/2) return;
	if(zp>n/2) return;
	if(xp+yp+zp==n+1){
		ans=max(ans,tot);
		return ;
	}
	dfs(tot+a[xp+yp+zp][1],xp+1,yp,zp);
	dfs(tot+a[xp+yp+zp][2],xp,yp+1,zp);
	dfs(tot+a[xp+yp+zp][3],xp,yp,zp+1);
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		if(n<=10) dfs(0,0,0,0);
		else{
			for(int i=1;i<=n;i++) ans+=max(a[i][1],max(a[i][2],a[i][3]));
		}
		cout<<ans<<"\n";
		ans=0;
	}
	return 0;
}
