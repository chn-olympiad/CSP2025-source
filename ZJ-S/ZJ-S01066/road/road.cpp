#include<bits/stdc++.h>
using namespace std;
struct kun{
	int i,j,n;
}ma[1000005];
struct city{
	int i,a[10005];
}ci[15];
//vector < vector<kun> > ma;
int n,m,k,x,y,xx;
long long ans;
long long dp[10005];
bool vis[10005];
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	scanf("%d%d%d",&n,&m,&k);
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=INT_MAX;
	}
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&ma[i].i,&ma[i].j,&ma[i].n);
	}
	for(int i=1;i<=k;i++){
		scanf("%d",&ci[i].i);
		for(int j=1;j<=n;j++){
			scanf("%d",&ci[i].a[j]);
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			dp[ma[j].i]=min(dp[ma[j].i],dp[ma[j].j]+ma[j].n);
			dp[ma[j].j]=min(dp[ma[j].j],dp[ma[j].i]+ma[j].n);
		}
//		for(int i=1;i<=n;i++){
//			cout<<dp[i]<<' ';
//		}
//		cout<<endl;
		for(int p=1;p<=k;p++){
//			cout<<1;
			for(int j=1;j<n;j++){
				for(int s=j+1;s<=n;s++){
					if(dp[s]>dp[j]+ci[p].a[j]+ci[p].a[s]+ci[p].i){
						cout<<p<<' '<<j<<k;
						dp[s]=dp[j]+ci[p].a[j]+ci[p].a[s]+ci[p].i;
					}
					if(dp[j]>dp[s]+ci[p].a[s]+ci[p].a[j]+ci[p].i){
						cout<<i<<' '<<j<<k;
						dp[j]=dp[s]+ci[p].a[j]+ci[p].a[s]+ci[p].i;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<dp[i]<<' ';
		ans+=dp[i];
	}
	cout<<ans;
	return 0;
}
//4 5 0
//1 2 6
//1 3 1
//1 4 4
//2 3 2
//3 4 5
