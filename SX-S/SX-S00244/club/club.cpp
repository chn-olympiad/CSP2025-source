#include<bits/stdc++.h>
using namespace std;
int n,a[100005][4];
int dp[205][205][205];
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=i;k++){
				if(i-j-k<0) continue;
				dp[i][j][k]=0;
				if(j) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
				if(k) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
				if(i-j-k>0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			if(n-i-j<=n/2) ans=max(ans,dp[n][i][j]);
		}
	}
	printf("%d\n",ans);
}
bool cmp(int x,int y){
	return a[x][2]-a[x][1]>a[y][2]-a[y][1];
}
int p[100005];
void solve2(){
	for(int i=1;i<=n;i++) p[i]=i;
	sort(p+1,p+n+1,cmp);
	int ans=0;
	for(int i=1;i<=n;i++){
		if(i<=n/2) ans+=a[p[i]][2];
		else ans+=a[p[i]][1];
	}
	printf("%d\n",ans);
}
void solve3(){
	int ans=0;
	for(int i=1;i<=n;i++) ans+=max({a[i][1],a[i][2],a[i][3]});
	printf("%d\n",ans);
}
void solve(){
	scanf("%d",&n);
	bool f=true;
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		if(a[i][3]) f=false;
	}
	if(n<=200) solve1();
	else if(f) solve2();
	else solve3();
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}
