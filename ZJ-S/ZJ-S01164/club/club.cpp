#include <bits/stdc++.h>
using namespace std;
int T,n,ma,a[100010],b[100010],c[100010],l,dp[201][101][101][101],s,ma1,ma2,ans;
void dfs(int t,int aa,int ax,int bb,int bx,int cc,int cx){
	if(ax>n/2||bx>n/2||cx>n/2) return ;
	if(t==n+1){
		ma=max(ma,aa+bb+cc);
		return ;
	}
	dfs(t+1,aa+a[t],ax+1,bb,bx,cc,cx);
	dfs(t+1,aa,ax,bb+b[t],bx+1,cc,cx);
	dfs(t+1,aa,ax,bb,bx,cc+c[t],cx+1);
}
bool cmp(int q,int h){
	return q>h;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>T;
	while(T--){
		cin>>n;ma=-2e9;s=0;ma1=-2e9,ma2=-2e9;ans=0;
		if(n<=10){
			for(int i=1;i<=n;i++)
				cin>>a[i]>>b[i]>>c[i];
			dfs(1,0,0,0,0,0,0);
			cout<<ma<<"\n";			
		}
		else if(n<=200){
			for(int i=1;i<=n;i++)
				cin>>a[i]>>b[i]>>c[i];
			memset(dp,0,sizeof(dp));
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(n/2,i);j++)	
					for(int k=0;k<=min(n/2,i-j);k++){
						l=i-j-k;
						if(l>n/2) continue;
						if(j>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j-1][k][l]+a[i]);
						if(k>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k-1][l]+b[i]);
						if(l>0) dp[i][j][k][l]=max(dp[i][j][k][l],dp[i-1][j][k][l-1]+c[i]);
					}
			}
			for(int i=0;i<=n/2;i++)
				for(int j=0;j<=n/2;j++){
					l=n-i-j;
					if(l>n/2) continue;
					ma=max(ma,dp[n][i][j][l]);
				}
			cout<<ma<<"\n";
		}
		else{
			for(int i=1;i<=n;i++)
				cin>>a[i]>>b[i]>>c[i],ma1=max(ma1,b[i]),ma2=max(ma2,c[i]);
			if(ma2==0&&ma1==0){
				sort(a+1,a+1+n,cmp);
				for(int i=1;i<=n/2;i++) s+=a[i];
				cout<<s<<"\n";
			}
			else{
				for(int i=1;i<=n;i++)
					ans+=max(a[i],max(b[i],c[i]));
				cout<<ans<<" ";
			}
		}
	}
	return 0;
}