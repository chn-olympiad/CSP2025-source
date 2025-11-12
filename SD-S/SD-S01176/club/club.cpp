#include<bits/stdc++.h>
using namespace std;
const int N=1e5+63;
int T,n;
int ans;
int dp[300][300][300];
struct aabb{
	int u,v,w;
}a[N];
bool cmp(aabb x,aabb y){
	if(x.u>0||y.u>0){
		return x.u>y.u;
	}
	else{
		return x.v<y.v;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		ans=0;
		bool flag=false;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].w);
			if(a[i].w){
				flag=true;
			}
		}
		if(!flag){
			for(int i=1;i<=n;i++){
				int x=min(a[i].u,a[i].v);
				ans+=x;
				a[i].u-=x;
				a[i].v-=x;
			}
			sort(a+1,a+n+1,cmp);
			int l=1;
			while(l<=n/2){
				ans+=a[l].u;
				l++;
			}
			while(l<=n){
				ans+=a[l].v;
				l++;
			}
		}
		else{
			for(int j=0;j<=n/2;j++){
				for(int k=0;k<=n/2;k++){
					if(j+k>n){
						break;
					} 
					for(int l=0;l<=n/2;l++){
						if(j+k+l>n){
							break;
						}
						dp[j][k][l]=0;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=min(i,n/2);j>=0;j--){
					for(int k=min(i-j,n/2);k>=0;k--){
						int l=i-j-k;
						if(l>n/2){
							break;
						}
						if(j) dp[j][k][l]=max(dp[j][k][l],dp[j-1][k][l]+a[i].u);
						if(k) dp[j][k][l]=max(dp[j][k][l],dp[j][k-1][l]+a[i].v);
						if(l) dp[j][k][l]=max(dp[j][k][l],dp[j][k][l-1]+a[i].w);
						ans=max(ans,dp[j][k][l]);
					}
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
