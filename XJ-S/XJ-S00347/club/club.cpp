#include<bits/stdc++.h>
using namespace std;
#define int long long
int T,n,a[100005][4],sum[5],ans;
void dfs(int step,int cnt){
	if(step==n+1){
		ans=max(ans,cnt);
		return;
	}
	for(int i=1;i<=3;i++){
		if(sum[i]<n/2)	sum[i]++,dfs(step+1,cnt+a[step][i]),sum[i]--;
	}
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	cin>>T;
	while(T--){
		cin>>n;
		memset(sum,0,sizeof(sum));
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1,0);
		cout<<ans<<endl;
	}
	return 0;
}




