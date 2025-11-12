#include<bits/stdc++.h>
using namespace std;
int t,n;
struct point{
	int a,b,c;
}a[100005];
int ans;
int dp[10005][10005];
void solve(){
	ans=0;
	memset(dp,0,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=n/2;j>=0;j--){
			for(int k=n/2;k>=0;k--){
				//for(int l=n/2;l>=0;l--){
					int tp=dp[j][k];
					if(j>0)dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i].a);
					if(k>0)dp[j][k]=max(dp[j][k],dp[j][k-1]+a[i].b);
					if(j+k<i)dp[j][k]=max(dp[j][k],tp+a[i].c);
					//if(l>0)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].c);
				//cout<<i<<" "<<j<<" "<<k<<" "<<dp[j][k]<<endl;
				//}
			}
		}
	}
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(i+j>=n/2)ans=max(ans,dp[i][j]);
		}
	}
	cout<<ans<<endl;
}
bool cmp(point & x,point & y){
	return x.a>y.a;
}
void solveA(){
	ans=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=a[i].a;
	}
	cout<<ans<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool A=1;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].a,&a[i].b,&a[i].c);
			if(a[i].b)A=0;
		}
		if(A)solveA();
		else solve();
	}
}
