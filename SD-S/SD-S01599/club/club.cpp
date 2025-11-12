#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5,mod=998244353;
int t;
int n;
struct node{
	int asum,bsum,csum;
	int val;
}dp[N][5];
struct e{
	int a,b,c;
	int rnd;
}a[N];
bool cmp(e a,e b){
	return a.rnd>b.rnd;
}
signed main(){
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		if(n==2){
			int a,b,c,d,e,f;
			cin>>a>>b>>c>>d>>e>>f;
			cout<<max({a+e,a+f,b+d,b+f,c+d,c+e})<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			cin>>a[i].a>>a[i].b>>a[i].c;
		}
		int ans=0;
		for(int sss=1;sss<=100;sss++){
			for(int i=1;i<=n;i++){
				dp[i][1].val=0;
				dp[i][2].val=0;
				dp[i][3].val=0;
				a[i].rnd=(rand()*rand()+rand())%rand();
			}
			sort(a+1,a+n+1,cmp);
			for(int i=1;i<=n;i++){
				for(int j=1;j<=3;j++){
					if(dp[i-1][j].asum<n/2){
						if(dp[i][1].val<dp[i-1][j].val+a[i].a){
							dp[i][1].asum=dp[i-1][j].asum+1;
							dp[i][1].bsum=dp[i-1][j].bsum;
							dp[i][1].csum=dp[i-1][j].csum;
							dp[i][1].val=dp[i-1][j].val+a[i].a;
						}
					}
				}
				for(int j=1;j<=3;j++){
					if(dp[i-1][j].bsum<n/2){
						if(dp[i][2].val<dp[i-1][j].val+a[i].b){
							dp[i][2].asum=dp[i-1][j].asum;
							dp[i][2].bsum=dp[i-1][j].bsum+1;
							dp[i][2].csum=dp[i-1][j].csum;
							dp[i][2].val=dp[i-1][j].val+a[i].b;
						}
					}
				}
				for(int j=1;j<=3;j++){
					if(dp[i-1][j].csum<n/2){
						if(dp[i][3].val<dp[i-1][j].val+a[i].c){
							dp[i][3].asum=dp[i-1][j].asum;
							dp[i][3].bsum=dp[i-1][j].bsum;
							dp[i][3].csum=dp[i-1][j].csum+1;
							dp[i][3].val=dp[i-1][j].val+a[i].c;
						}
					}
				}
			}
			ans=max(ans,max(max(dp[n][1].val,dp[n][2].val),dp[n][3].val));
		}
		cout<<ans<<'\n';
	}
	return 0;
}
