#include<bits/stdc++.h>
using namespace std;
int t,n,a[202][4],b[100010];
int dp[35][20][20][20];
int dp2[205][105][105];
int dfs(int x,int cnt1,int cnt2,int cnt3){
	if(dp[x][cnt1][cnt2][cnt3]!=-1) return dp[x][cnt1][cnt2][cnt3];
	if(x==n+1) return 0;
	int maxn=INT_MIN;
	if(cnt3+1<=(n/2)) maxn=max(maxn,a[x][3]+dfs(x+1,cnt1,cnt2,cnt3+1));
	if(cnt1+1<=(n/2)) maxn=max(maxn,a[x][1]+dfs(x+1,cnt1+1,cnt2,cnt3));
	if(cnt2+1<=(n/2)) maxn=max(maxn,a[x][2]+dfs(x+1,cnt1,cnt2+1,cnt3));
	return dp[x][cnt1][cnt2][cnt3]=maxn;
}
int dfs2(int x,int cnt1,int cnt2){
	if(dp2[x][cnt1][cnt2]!=-1) return dp2[x][cnt1][cnt2];
	if(x==n+1) return 0;
	int maxn=INT_MIN;
	if(cnt1+1<=(n/2)) maxn=max(maxn,a[x][1]+dfs2(x+1,cnt1+1,cnt2));
	if(cnt2+1<=(n/2)) maxn=max(maxn,a[x][2]+dfs2(x+1,cnt1,cnt2+1));
	return dp2[x][cnt1][cnt2]=maxn;
}
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>t;
	while(t--){
		bool flag1=0,flag2=0;
		memset(dp,-1,sizeof(dp));
		memset(dp2,-1,sizeof(dp2));
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=3;++j){
				cin>>a[i][j];
				if(j==1) b[i]=a[i][j];
				if(j==2&&a[i][j]!=0) flag1=1;
				else if(j==3&&a[i][j]!=0) flag2=1;
			}
		}
		if(!flag1&&!flag2){
			sort(b+1,b+n+1,cmp);
			int sum=0;
			for(int i=1;i<=n/2;i++) sum+=b[i];
			cout<<sum<<'\n';
		}
		else if(flag1&&!flag2) cout<<dfs2(1,0,0)<<'\n';
		else cout<<dfs(1,0,0,0)<<'\n';
	}
	return 0;
}