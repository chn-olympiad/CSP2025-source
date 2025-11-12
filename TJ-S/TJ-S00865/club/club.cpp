#include<bits/stdc++.h>
#define N 300010
using namespace std;
int n, T;
int dp[N][5], m[5];
int a[N][4], b[N];
int maxx(int a,int b,int c){
	if(a>=b){
		if(a>=c) return a;
		else return c;
	}
	else {
		if(b>=c) return b;
		else return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		int sum=0, ans=0;
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			sum+=a[i][2]+a[i][3];
		}
		if(n==2){
			int x=maxx(a[1][1],a[1][2],a[1][3]);
			int y=maxx(a[2][1],a[2][2],a[2][3]);
			if(x==a[1][1]&&y==a[2][1]){
				cout<<max(x+max(a[2][2],a[2][3]),y+max(a[1][2],a[1][3]))<<endl;
				continue;
			}
			if(x==a[1][2]&&y==a[2][2]){
				cout<<max(x+max(a[2][1],a[2][3]),y+max(a[1][1],a[1][3]))<<endl;
				continue;
			}
			if(x==a[1][3]&&y==a[2][3]){
				cout<<max(x+max(a[2][1],a[2][2]),y+max(a[1][1],a[1][2]))<<endl;
				continue;
			}
			cout<<x+y<<endl;
			continue;
		}
		if(sum==0){
			for(int i=1;i<=n;i++){
				b[i]=a[i][1];
			}
			sort(b+1,b+1+n);
			for(int i=n;i>n/2;i--){
				ans+=b[i];
			}
			cout<<ans<<endl;
			continue;
		}
		int ma=n/2;		
		dp[1][1]=a[1][1];
		dp[1][2]=a[1][2];
		dp[1][3]=a[1][3];
		for(int i=2;i<=n;i++){
			dp[i][1] = a[i][1] + maxx(dp[i-1][1], dp[i-1][2], dp[i-1][3]);
			dp[i][2] = a[i][2] + maxx(dp[i-1][1], dp[i-1][2], dp[i-1][3]);
			dp[i][3] = a[i][3] + maxx(dp[i-1][1], dp[i-1][2], dp[i-1][3]);
		}
		ans=maxx(dp[n][1],dp[n][2], dp[n][3]);
		cout<<ans<<endl;
	}
	return 0;
}
