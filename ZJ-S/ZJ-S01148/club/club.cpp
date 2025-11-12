#include<bits/stdc++.h>
using namespace std;
int cmp(int h,int q){
	return h>q;
}
int T,n,a[10005][10],b[10005],summ,ans;
bool vis[10005];
int dp1[1005][1005],dp2[1005][1005],dp3[1005][1005];
void dfs(int sum,int l,int r,int t,int cnt,int qd){
	if(l>n/2) return ;
	if(r>n/2) return ;
	if(t>n/2) return ;
	if(cnt==n){
		ans=max(ans,sum);
		return ;
	}
	for(int i=qd;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			dfs(sum+a[i][1],l+1,r,t,cnt+1,i);
			dfs(sum+a[i][2],l,r+1,t,cnt+1,i);
			dfs(sum+a[i][3],l,r,t+1,cnt+1,i);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(vis,0,sizeof vis);
		cin>>n;
		ans=0;
		int f=0,g=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++) cin>>a[i][j];
		for(int i=1;i<=n;i++){
			if(a[i][2]!=0) f=1;
			else if(a[i][3]!=0) g=1;
		}
		if(!f&&!g){
			for(int i=1;i<=n;i++) b[i]=a[i][1];
			sort(b+1,b+1+n,cmp);
			for(int i=1;i<=n/2;i++) summ+=b[i];
			cout<<summ<<endl;
		}
		if(n<=10){
			dfs(0,0,0,0,0,1);
			cout<<ans<<endl;
		}else{
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n/2;j++){
					dp1[i][j]=max(dp1[i-1][j],dp1[i-1][j-1]+a[i][1]);
					dp2[i][j]=max(dp2[i-1][j],dp2[i-1][j-1]+a[i][2]);
					dp3[i][j]=max(dp3[i-1][j],dp3[i-1][j-1]+a[i][3]);
				}
			}
			cout<<dp1[n][n/2]+dp2[n][n/2]+dp3[n][n/2]<<endl;
		}
	}
	return 0;
}
