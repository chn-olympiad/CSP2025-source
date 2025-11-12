#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxn2=5e4+5;
struct qwe{
	int x,y,z;
}a[maxn];
int dp[205][105][105];
bool cmp(qwe aa,qwe bb){
	return aa.x>bb.x;
}
map<int,int> f[maxn];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(a,0,sizeof(a));
		int n;
		cin>>n;
		for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
		bool flag=1;
		for(int i=1;i<=n;i++){
			if(a[i].y!=0||a[i].z!=0){
				flag=0;
				break;
			}
		}
		if(flag){//5
			sort(a+1,a+n+1,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		bool flag2=1;
		for(int i=1;i<=n;i++){
			if(a[i].z!=0){
				flag2=0;
				break;
			}
		}
		if(flag2){//10
			f[1][1]=a[1].x;
			f[1][0]=a[1].y;
			for(int i=2;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					int k=i-j;
					if(k>n/2) continue;
					if(j==0) f[i][j]=max({f[i][j],f[i-1][j]+a[i].y});
					else if(k==0) f[i][j]=max({f[i][j],f[i-1][j-1]+a[i].x});
					else f[i][j]=max({f[i][j],f[i-1][j-1]+a[i].x,f[i-1][j]+a[i].y});
//					cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j]<<endl;
				}
			}
//			return 0;
			cout<<f[n][n/2]<<endl;
			for(int i=1;i<=n;i++){
				for(int j=0;j<=min(i,n/2);j++){
					f[i][j]=0;
				}
			}
			continue;
		}
//		if(n<=200){55
		memset(dp,0,sizeof(dp));
		dp[1][1][0]=a[1].x;
		dp[1][0][1]=a[1].y;
		dp[1][0][0]=a[1].z;
		for(int i=2;i<=n;i++){
			for(int j=0;j<=min(i,n/2);j++){
				for(int k=0;k<=min(i,n/2);k++){
					if(i-j-k>min(i,n/2)) continue;
					if(j+k>i) continue;
					if(j==0&&k==0){
						dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k]+a[i].z});
					}
					else if(j==0) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j][k-1]+a[i].y,dp[i-1][j][k]+a[i].z});
					else if(k==0) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j-1][k]+a[i].x,dp[i-1][j][k]+a[i].z});
					else if(i-j-k==0) dp[i][j][k]=max({dp[i][j][k],dp[i-1][j-1][k]+a[i].x,dp[i-1][j][k-1]+a[i].y});
					else dp[i][j][k]=max({dp[i][j][k],dp[i-1][j-1][k]+a[i].x,dp[i-1][j][k-1]+a[i].y,dp[i-1][j][k]+a[i].z});
//						cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
			}
		}
//			return 0;
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2) continue;
				ans=max(ans,dp[n][i][j]);
//				cout<<i<<" "<<j<<" "<<dp[n][i][j]<<"\n";
			}
//			cout<<endl;
		}
		cout<<ans<<endl;
		continue;
//		}
	}
	return 0;
}
//1h 60pts
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
最后一次考试 天天开心 
*/
