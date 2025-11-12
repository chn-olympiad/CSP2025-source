#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
#define mid(l,r) (l+r>>1)
#define lowbit(x) (x&-x)
using namespace std;
const int N=1e5+10,M=2e2+10,mod=1e9+7;
const double eps=1e-1;
const long double pi=acos(-1);
int t,n,a[N][10],b[N],dp[M][M][M];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(a[i][2]||a[i][3]){
				flag=1;
				break;
			}
		}
		if(!flag){
			int sum=0;
			for(int i=1;i<=n;i++)b[i]=a[i][1];
			sort(b+1,b+n+1,cmp);
			for(int i=1;i<=n/2;i++)sum+=b[i];
			cout<<sum<<endl;
			continue;
		}
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=min(n/2,i);j++){
				for(int k=0;k<=min(n/2,i-j);k++){
					if(j)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]+a[i][1]);
					if(k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+a[i][2]);
					if(i-j-k)dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+a[i][3]);
				}
			}
		}
		int ans=0;
		for(int i=0;i<=n/2;i++){
			for(int j=0;j<=n/2;j++){
				if(n-i-j>n/2)continue;
				ans=max(ans,dp[n][i][j]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
