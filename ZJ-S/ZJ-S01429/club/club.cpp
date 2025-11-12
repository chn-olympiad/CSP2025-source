#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=205,M=1e5+10;
int n,t,dp[N][N][N];
struct node{
	int u,v,w;
}a[M];
bool cmp1(node x,node y){
	return x.u>y.u;
}
void FLdp(){
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k>n) break;
				if(i!=0) dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i+j+k].u);
				if(j!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j-1][k]+a[i+j+k].v);
				if(k!=0) dp[i][j][k]=max(dp[i][j][k],dp[i][j][k-1]+a[i+j+k].w);
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n/2;i++){
		for(int j=0;j<=n/2;j++){
			for(int k=0;k<=n/2;k++){
				if(i+j+k==n){
					ans=max(ans,dp[i][j][k]);
				}
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		bool f2=0,f3=0;
		memset(a,0,sizeof a);
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v>>a[i].w;
			if(a[i].v!=0) f2=1;
			if(a[i].w!=0) f3=1;
		}
		if(n<=200){
			memset(dp,0,sizeof dp);
			FLdp();
		}
		else{
			if(!f2&&!f3){
				sort(a+1,a+n+1,cmp1);
				int ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[i].u;
				}
				cout<<ans<<endl;
			}else if(!f3){
				sort(a+1,a+n+1,cmp1);
				int sum=0,ans=0;
				for(int i=1;i<=n/2;i++){
					ans+=a[i].u;
					sum+=a[i].u+a[i].v;
				}for(int i=n/2+1;i<=n;i++){
					ans+=a[i].v;
					sum+=a[i].u+a[i].v;
				}
				cout<<max(ans,sum-ans);
			}
			else{
				int ans=0;
				int t1=0,t2=0,t3=0;
				for(int i=1;i<=n;i++){
					int t=0;
					if(t1!=n/2) t=max(t,a[i].u);
					if(t2!=n/2) t=max(t,a[i].v);
					if(t3!=n/2) t=max(t,a[i].w);
					if(t==t1) t1++;
					else if(t==t2) t2++;
					else t3++;
					ans+=t;
				}
				cout<<ans<<endl;
			}
		}
	}
	return 0;
}
