#include<bits/stdc++.h>
using namespace std;

int T,n,a[100005][4];
long long dp[202][102][102];
void solve1(){
	memset(dp,0,sizeof dp);
	long long ans=0;
	for(int i=1;i<=n;++i){
		for(int j=0;j<=(n>>1);++j){
			for(int k=0;k<=(n>>1);++k){
				int l=i-j-k;
				if(l<0||l>(n>>1))continue;
				if(j)dp[i][j][k]=max(dp[i][j][k], dp[i-1][j-1][k] + a[i][1]);
				if(k)dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k-1] + a[i][2]);
				if(l)dp[i][j][k]=max(dp[i][j][k], dp[i-1][j][k] + a[i][3]);
				if(i==n)ans=max(ans,dp[i][j][k]);
			}
		}
	}
	cout<<ans<<'\n';
}

void solve2(){
	struct node{
		int x,y;
		bool operator<(const node &o)const{
			return x-y>o.x-o.y;
		}
	}b[100005];
	for(int i=1;i<=n;++i){
		b[i]={a[i][1],a[i][2]};
	}
	sort(b+1,b+n+1);
	int ans=0;
	for(int i=1;i*2<=n;++i){
		ans+=b[i].x;
	}
	for(int i=n/2+1;i<=n;++i){
		ans+=b[i].y;
	}
	cout<<ans<<'\n';
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
		}
		if(n<=200)solve1();
		else solve2();
	}
	
	return 0;
}


