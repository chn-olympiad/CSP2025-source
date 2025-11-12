#include<bits/stdc++.h>
using namespace std;
const int N=210;
int T,n,mxc;
int dp[N][N][N],ans;
struct ST{
	int a,b,c;
}s[100010];
int cmp(ST x,ST y){
	return x.a-x.b>y.a-y.b;
}
void solve(){
	sort(s+1,s+1+n,cmp);
	for(int i=1;i<=n;i++){
		if(i<=n/2){
			ans+=s[i].a;
		}
		else ans+=s[i].b;
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		memset(dp,~0x3f,sizeof dp);
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>s[i].a>>s[i].b>>s[i].c;
			mxc=max(mxc,s[i].c);
		}
		if(mxc==0){
			solve();
			continue;
		}
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++){
			for(int j=0;j<=i;j++){
				for(int k=0;k+j<=i;k++){
					if(j+k<i)dp[i][j][k]=dp[i-1][j][k]+s[i].c;
					if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+s[i].a);
					if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+s[i].b);
				}
			}
		}
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j<=n/2)ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
