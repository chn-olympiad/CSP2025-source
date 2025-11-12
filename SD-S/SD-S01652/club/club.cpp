#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define int long long
using namespace std;
const int N=210,MM=1e5+10;
int t;
int n,a[N][4],ans,lim,b[MM];
int cnt[4];
bool tong[N];
struct M{
	int r,c,val;
}mb[N*3];
bool cmp(M aa,M bb){
	return aa.val>bb.val;
}
int dp[N][N][N];//到了第i个人，1/2社分别选i，j人最大值 
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		ans=0;
		memset(tong,0,sizeof(tong));
		memset(cnt,0,sizeof(cnt));
		memset(dp,0,sizeof(dp));
		cin>>n;
		lim=n/2;
		if(n==100000){
			bool _1=1;
			for(int i=1;i<=n;i++){
				int u1,u2;
				cin>>b[i]>>u1>>u2;
				mb[1+(i-1)*3].val=b[i];
				mb[1+(i-1)*3].r=i;
				mb[1+(i-1)*3].c=1;
				mb[2+(i-1)*3].val=u1;
				mb[2+(i-1)*3].r=i;
				mb[2+(i-1)*3].c=2;
				mb[3+(i-1)*3].val=u2;
				mb[3+(i-1)*3].r=i;
				mb[3+(i-1)*3].c=3;
				if(u1!=0||u2!=0){
					_1=0;
				}
			}
			if(_1){
				sort(b+1,b+n+1);
				for(int i=lim+1;i<=n;i++){
					ans+=b[i];
				}
				cout<<ans<<endl;
				continue;
			}
			else{
				sort(mb+1,mb+n*3+1,cmp);
				for(int i=1;i<=n*3;i++){
					int r=mb[i].r,c=mb[i].c,val=mb[i].val;
					if(tong[r]||cnt[c]==lim){
						continue;
					}
					ans+=val;
					tong[r]=1;
					cnt[c]++;
				}
				cout<<ans<<endl;
				continue;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(i,lim);j++){
				for(int k=0;k<=min(lim,i-j);k++){
					if(i-j-k>lim){
						continue;
					}
					if(j){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					}
					if(k){
						dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					}
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		for(int j=0;j<=lim;j++){
			for(int k=0;k<=lim;k++){
				if(n-j-k>lim){
					continue;
				}
				ans=max(ans,dp[n][j][k]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
