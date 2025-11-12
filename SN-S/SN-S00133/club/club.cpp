#include<bits/stdc++.h>
//#define int long long
#define endl '\n'
using namespace std;
int n,m,t;
const int maxn=1e5+5;
const int mod=998244353;
const int inf=0x3f3f3f3f;
//const int INF=0x3f3f3f3f3f3f3f3fll;
struct cxh{
	int a,b,c;
}a[maxn];
bool cmp1(cxh x,cxh y){
	return x.a>y.a;
}
bool cmp2(cxh x,cxh y){
	if(x.a!=y.a)return x.a>y.a;
	else return x.b<y.b;
}
bool d[maxn];
int cnt1,cnt2,cnt3;
int dp[205][205][205];
//XTBT
//14:34
//开T1，好评，win7用出了win11的感觉，比早上好多了 
//开完题，没有大模拟，感觉要完 
//14:44
//MDT1貌似有坑 
//15:45
//回看T1，发现假了 
//16:30
//现在才12pts…… 
//17:06
//60pts，心态炸了 
signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//freopen(".out","w",stdout);
cin>>t;
while(t--){
	cin>>n;
	bool pp=0;bool p=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b>>a[i].c;
		if(a[i].b&&a[i].c)p=1;
		if(a[i].c)pp=1;
	}
if(n<=200){
	memset(dp,0,sizeof(dp));
	dp[1][1][0]=a[1].a;
	dp[1][0][1]=a[1].b;
	dp[1][0][0]=a[1].c;
	for(int i=0;i<=n;i+=2){
		dp[i][0][i/2]=dp[i-2][0][i/2-1]+a[i].b+a[i].c;
		dp[i][i/2][0]=dp[i-2][i/2-1][0]+a[i].a+a[i].c;
		dp[i][i/2][i/2]=dp[i-2][i/2-1][i/2-1]+a[i].a+a[i].b;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=min(i,n/2);j++){
			for(int k=0;k<=min(i,n/2);k++){
				if(k!=0)dp[i][j][k]=max(dp[i-1][j][k-1]+a[i].b,dp[i][j][k]);
				if(j!=0)dp[i][j][k]=max(dp[i-1][j-1][k]+a[i].a,dp[i][j][k]);
				if(k+j<=i-1)dp[i][j][k]=max(dp[i-1][j][k]+a[i].c,dp[i][j][k]);
			}
		}
	}
	int maxx=0;
	for(int i=0;i<=n;i++)for(int j=0;j<=n;j++){
		if(i+j<n/2)continue;
		maxx=max(maxx,dp[n][i][j]);
	}
	cout<<maxx<<endl;
	continue;
}
if(p==0){
	sort(a+1,a+n+1,cmp1);
	int ans=0;
	for(int i=1;i<=n/2;i++)ans+=a[i].a;
	cout<<ans<<endl;
	continue;
}
if(pp==0){
	int ans=0;
	int cnt=0;
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(cnt==n/2){
			ans+=a[i].b;
			continue;
		}
		int maxx=max(a[i].a,a[i].b);
		if(maxx==a[i].a)cnt++;
		ans+=maxx;
	}
	cout<<ans<<endl;
	continue;
}
	
}
	return 0;
}

