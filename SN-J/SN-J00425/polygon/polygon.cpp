//考号:SN-J00425 姓名:强小轩 学校:渭南初级中学 
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
using namespace std;
typedef pair<int,int> Pii;
int n,a[5005],maxx,modd=998244353;
ll ans;
int dp[5005][10005];
int cntsum[10005];//当sum为i时cnt总和 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	if(maxx==1){
		ans=1;
		ans*=n;
		ans*=n-1;
		ans*=n-2;
		ans/=6;
		ans%=modd;
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+1+n);
	cntsum[0]=1;
	for(int i=1;i<=n;i++){
		for(int sum=0;sum<=maxx*2+1;sum++){
			//转移前的sum
			int nowsum=min(2*maxx+1,sum+a[i]);
			dp[i][nowsum]=(dp[i][nowsum]+cntsum[sum])%modd;
		}
		for(int sum=0;sum+a[i]<=maxx*2+1;sum++){
			//转移前的sum
			int nowsum=sum+a[i];
			cntsum[nowsum]=(cntsum[nowsum]+dp[i][nowsum])%modd;
		}
	}
	for(int i=3;i<=n;i++){
		for(int sum=a[i]*2+1;sum<=maxx*2+1;sum++){
			ans=(ans+dp[i][sum])%modd;
		}
	}
	cout<<ans<<'\n';
	return 0;
}
























