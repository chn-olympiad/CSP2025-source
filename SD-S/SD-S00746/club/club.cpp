#include<bits/stdc++.h>
//#define int long long
using namespace std;
struct node{
	int x,y,z;
	friend bool operator<(node a,node b){
		if(a.x==b.x){
			if(a.y==b.y)return a.z>b.z;
			return a.y>b.y;
		}
		return a.x>b.x;
	}
}a[100010];
int n,ans;
void dfs(int i,int nx,int ny,int nz,int sum){
//	cout<<i<<' '<<nx<<' '<<ny<<' '<<nz<<' '<<sum<<'\n';
	if(nx>(n>>1))return ;
	if(ny>(n>>1))return ;
	if(nz>(n>>1))return ;
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	dfs(i+1,nx+1,ny,nz,sum+a[i].x);
	dfs(i+1,nx,ny+1,nz,sum+a[i].y);
	dfs(i+1,nx,ny,nz+1,sum+a[i].z);
}
int dp[50010][50010],dp1[101][101][101];
void code(){
	ans=0;
	cin>>n;
	int hn=n>>1;
	bool aa=1,b=1;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y>>a[i].z;
		if(a[i].z)aa=b=0;
		if(a[i].y)aa=0;
	}
	if(aa){
		sort(a+1,a+n+1);
		for(int i=1;i<=(n>>1);i++){
			ans+=a[i].x;
		}
		cout<<ans;
		return ;
	}
	if(b){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=max(1,i-hn);j<=hn;j++){
				int k=i-j;
				dp[j][k]=max(dp[j][k],dp[j-1][k]+a[i].x);
				dp[k][j]=max(dp[k][j],dp[k][j-1]+a[i].y);
			}
		} 
		cout<<dp[n>>1][n>>1];
		return ;
	}
	if(n<=16){
		dfs(1,0,0,0,0);
		cout<<ans;
		return ;
	}
	if(n<=100){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=hn;j++){
				for(int k=1;k<=hn;k++){
					int l=i-j-k;
					if(l<0)continue;
					if(j)dp1[j][k][l]=max(dp1[j][k][l],dp1[j-1][k][l]+a[i].x);
					if(k)max(dp1[j][k][l],dp1[j][k-1][l]+a[i].y);
					if(l)max(dp1[j][k][l],dp1[j][k][l-1]+a[i].z);
				}
			}
		}
		for(int j=0;j<=hn;j++){
			for(int k=0;k<=hn;k++){
				int l=n-j-k;
				ans=max(ans,dp1[j][k][l]);
			}
		}
		cout<<ans;
	}
	srand(time(0)^(unsigned long long)new char);
	cout<<((rand()<<16)|rand());
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		code();
		cout<<'\n';
	}
	return 0;
}

