#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define dep(i,x,y) for(int i=x;i>=y;--i)
#define endl "\n"
#define N 5005
#define int long long
#define MAX 1145141919810
#define mod 998244353
#define TXYAKIOI 91
using namespace std;
int n,ans,ma=-MAX;
int a[N];
int yanghui[N][N];
inline void dfs(int now,int nowmax,int nowsum,int choose){
	if(now>n){
		if(nowsum>2*nowmax&&choose>=3){
			++ans;
			ans%=mod;
		}
		return;	
	}
	dfs(now+1,max(nowmax,a[now]),nowsum+a[now],choose+1);
	dfs(now+1,nowmax,nowsum,choose);
}
inline void Enchanted(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	rep(i,1,n){
		cin>>a[i];	
		ma=max(ma,a[i]);
	}
	if(ma==1){
		rep(i,1,n+1)yanghui[i][i]=yanghui[i][1]=1;
		rep(i,2,n+1)
			rep(j,2,i)
				yanghui[i][j]=(yanghui[i-1][j-1]+yanghui[i-1][j])%mod;
		rep(i,1,n-2)ans=(ans+yanghui[n+1][i])%mod;
		cout<<ans%mod;
		return;
	}
	dfs(1,0,0,0);
	cout<<ans%mod;
}
signed main(){Enchanted();return 0;}

