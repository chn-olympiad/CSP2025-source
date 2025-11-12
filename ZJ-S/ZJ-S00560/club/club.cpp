#include<bits/stdc++.h>
using namespace std;
//14:59 55pts
//15:13 70pts
#define int long long
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define repn(x) rep(x,1,n)
#define chkmax(a,b) a=max(a,b)
const int N=1e5+7;
inline int read(){
	int w=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') w=w*10+c-'0',c=getchar();
	return w*f;
}
int dp[207][207][207],n,T;
void out(int i,int j,int k){
	cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<"\n";
}
struct node{
	int x,y,z,d;
}a[N],tmp[N];
void solve(){
	int ans=0;
	memset(dp,0,sizeof(dp));
	rep(i,1,n){
		rep(j,0,i){
			for(int k=0;j+k<=i;k++){
				int l=i-j-k;
				if(j>=1) chkmax(dp[i][j][k],dp[i-1][j-1][k]+a[i].x);
				if(k>=1) chkmax(dp[i][j][k],dp[i-1][j][k-1]+a[i].y);
				if(l>=1) chkmax(dp[i][j][k],dp[i-1][j][k]+a[i].z);
			}
		}
	}
	rep(j,0,n/2){
		rep(k,0,n/2){
			int l=n-j-k;
			if(l<=n/2&&j<=n/2&&k<=n/2) chkmax(ans,dp[n][j][k]);
//			ans=max(ans,dp[i][j][k]),out(i,j,k);
		}
	}
	cout<<ans<<"\n";		
}
inline bool cmp1(node A,node B){
	return A.x>B.x;
}
inline bool cmp2(node A,node B){
	return A.d>B.d;
}
void solve2(){
	bool subA=1,subB=1;
	repn(i){
		if(a[i].y!=0||a[i].z!=0) subA=0;
		if(a[i].z!=0) subB=0;
	}
	if(subA){
		int ans=0;
		sort(a+1,a+n+1,cmp1);
		for(int i=1;i<=n/2;i++) ans+=a[i].x;
		cout<<ans<<"\n";
	}
	else if(subB){
		int ans=0;
		repn(i) a[i].d=a[i].y-a[i].x;
		sort(a+1,a+n+1,cmp2);
		rep(i,1,n/2) ans+=a[i].y;
		rep(i,n/2+1,n) ans+=a[i].x;
		cout<<ans<<"\n"; 
	}
	else{
		return;
	}
}
signed main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		repn(i) a[i].x=read(),a[i].y=read(),a[i].z=read();
		if(n<=200) solve();
		else solve2();
	}
	return 0;
}
