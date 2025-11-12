#include<bits/stdc++.h>
#define int long long
using namespace std;
void IOS(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}
int t,n;
const int N=1e5+5;
struct node{
	int a1,a2,a3;
}a[N];
int dp[105][105][105];
bool cmp(node x,node y){
	if(x.a1!=y.a1)return x.a1>y.a1;
	else if(x.a2!=y.a2)return x.a2>y.a2;
	return x.a3>y.a3;
}
signed main(){
	IOS();
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		bool f3=0,f2=0;
		for(int i=1;i<=n;++i){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a2!=0)f2=1;
			if(a[i].a3!=0)f3=1;
		}
		sort(a+1,a+1+n,cmp);
		if(!f2&&!f3){
			int ans=0;
			for(int i=1;i*2<=n;++i)ans+=a[i].a1;
			cout<<ans<<"\n";
		}
		memset(dp,0,sizeof dp);
		int ans=-1;
		for(int i=2;i<=n;++i)
			for(int j=0;j<=n/2;++j)
				for(int k=0;k<=n/2;++k)
					for(int l=0;l<=n/2;++l){
						if(j+k+l>n)continue;
						if(j!=0)dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].a1);
						if(k!=0)dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].a2);
						if(l!=0)dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].a3);
						if(j+k+l==n)ans=max(ans,dp[j][k][l]);
					}
		cout<<ans<<"\n";
	}
	return 0;
}
