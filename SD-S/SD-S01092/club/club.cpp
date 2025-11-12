#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define PII pair<int,int>
#define PLL pair<ll,ll>
#define PQ priority_queue
#define ump unordered_map
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e5+10,M=210;
struct AC{
	int d1,d2,d3,mx;
}a[N];
bool cmp(AC x,AC y){
	return x.mx>y.mx;
}
int n;
int dp[M][M];
void solve(){
	memset(dp,0,sizeof(dp));
	int cnt1=0,cnt2=0,cnt3=0;
	int ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].d1>>a[i].d2>>a[i].d3;
		if(a[i].d1==0) cnt1++;
		if(a[i].d2==0) cnt2++;
		if(a[i].d3==0) cnt3++;
		a[i].mx=max(a[i].d1,max(a[i].d2,a[i].d3));
	}
	if((cnt2==n&&cnt3==n)||(cnt1==n&&cnt2==n)||(cnt1==n&&cnt3==n)){
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n/2;i++) ans+=a[i].mx;
		cout<<ans<<'\n';
	}
	else if(cnt3==n){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=min(i,n/2);j++){
				dp[i][j]=max(dp[i-1][j-1]+a[i].d1,dp[i-1][j]+a[i].d2);
			}
		}
		cout<<dp[n][n/2]<<'\n';
	}
	else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=n;i++) ans+=a[i].mx;
		cout<<ans<<'\n';
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0);
	int T;
	cin>>T;
	while(T--){
		solve();
	}
	
	
	return 0;
} 
