#include<bits/stdc++.h>
using namespace std;
const int M=998244353,N=505,L=(1<<20)+1;
int n,m;
int a[N];
char cc;
bool c[N];
int hz[N];
long long jie[N];
bool vis[N];
int ans=0;
void dfs(int t,int fail,int num){
	if(num+hz[t]<m)return;
	if(t==n+1){
		if(num>=m)ans++;
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			vis[i]=1;
			
			if(fail>=a[i])dfs(t+1,fail+1,num);
			else dfs(t+1,fail+(c[t]==0),num+c[t]);
			vis[i]=0;
		}
	}
}
int dp[N][N];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	bool flag=1;
	for(int i=1;i<=n;i++){
		cin>>cc;
		c[i]=cc-'0';
		if(c[i]==0)flag=0;
	}
	for(int i=n;i>=1;i--){
		hz[i]=hz[i+1]+c[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	jie[0]=1;
	for(int i=1;i<=n;i++){
		jie[i]=(jie[i-1]*i)%M;
	}
//	if(flag){
//		for(int j=0;j<=n-m;j++){
//			
//		}
//		dp[0][0]=1;
//		for(int i=1;i<=n;i++){
//			for(int j=0;j<=n-m&&j<=i;j++){
//				for(int i=1;i<=n;i++){
//					
//				}
//				dp[i][j]=dp[i-1][j]
//			}
//		}
//	}
//	else{
		dfs(1,0,0);
		cout<<ans;
//	}
	return 0;
}
