#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+86;
int n;
struct node{
	int a1,a2,a3;
}a[N];
int ans;
void dfs(int s1,int s2,int s3,int sum){
	int i=s1+s2+s3+1;
	if(i>n){
		ans=max(ans,sum);
		return ;
	}
	if(s1<n/2){
		dfs(s1+1,s2,s3,sum+a[i].a1);
	}
	if(s2<n/2){
		dfs(s1,s2+1,s3,sum+a[i].a2);
	}
	if(s3<n/2){
		dfs(s1,s2,s3+1,sum+a[i].a3);
	}
	return ;
}
bool cmp(node x,node y){
	return x.a1>y.a1;
}
int dp[110][110][110][110];
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		bool f=0;
		scanf("%lld",&n);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&a[i].a1,&a[i].a2,&a[i].a3);
			if(a[i].a2!=0||a[i].a3!=0) f=1;
		}
		ans=0;
		if(f==0){
			sort(a+1,a+1+n,cmp);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
			}
			printf("%lld\n",ans);
			continue;
		}
		if(n>=30){
			memset(dp,0,sizeof(dp));
			for(int i=0;i<=n/2;i++){
				for(int j=0;j<=n/2;j++){
					for(int k=0;k<=n/2;k++){
						for(int id=i+j+k;id<=n;id++){
							if(i>0)dp[i][j][k][id]=max(dp[i-1][j][k][id-1]+a[id].a1,dp[i][j][k][id]);
							if(j>0)dp[i][j][k][id]=max(dp[i][j-1][k][id-1]+a[id].a2,dp[i][j][k][id]);
							if(k>0)dp[i][j][k][id]=max(dp[i][j][k-1][id-1]+a[id].a3,dp[i][j][k][id]);
							ans=max(ans,dp[i][j][k][id]);
						}
					}
				}
			}
			printf("%lld\n",ans);
			continue;
		}
		dfs(0,0,0,0);
		printf("%lld\n",ans);
	}
	return 0;
	
}
