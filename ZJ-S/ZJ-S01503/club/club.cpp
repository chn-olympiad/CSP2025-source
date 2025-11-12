#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+10;
struct node{
	ll a,b,c,d;
}s[N];
ll t,n,m,k,ans,dp[202][102][102];
bool cmp1(node x,node y){
	return x.b>y.b;
}
bool cmp2(node x,node y){
	return x.d>y.d;
}
void solve(){
	cin>>n;m=n/2;ans=0;
	for(int i=1;i<=n;i++){
		cin>>s[i].a>>s[i].b>>s[i].c;
		s[i].d=s[i].b-s[i].a;
	}
	if(n<=200){
		for(int i=0;i<=n;i++){
			if(i!=0)ans+=s[i].a;s[i].b-=s[i].a;s[i].c-=s[i].a;
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					dp[i][j][l]=-900000000;
				}
			}
		}k=-9000000000;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				for(int l=1;l<=m;l++){
					dp[i][j][l]=max(dp[i-1][j-1][l]+s[i].b,dp[i][j][l]);
					dp[i][j][l]=max(dp[i-1][j][l-1]+s[i].c,dp[i][j][l]);
					dp[i][j][l]=max(dp[i-1][j][l],dp[i][j][l]);
				}
			}
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(i+j<n/2)continue;
				k=max(k,dp[n][i][j]);
			}
		}
		ans+=k;
	}
	else{
		sort(s+1,s+n+1,cmp2);
		for(int i=1;i<=n;i++){
			if(i<=n/2)ans+=s[i].b;
			else ans+=s[i].a;
		}
	}
	cout<<ans<<endl;
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--)solve();
	return 0;
}