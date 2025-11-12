#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int h[5005];
const int mod=998244353;
int dp[500005];//dp i is many can catch it
int linshi[500005];
//int can[5005];//can i is can do
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;++i)
		cin>>h[i],sum+=h[i];
	sort(h+1,h+n+1);
	int ans=0;
	for(int i=1;i<=n;++i){
		int use=min(sum,100*i);
		int can=0;
		if(i>2){
			for(int j=h[i]+1;j<=use;++j)
				can=(can+dp[j])%mod;
		}
		for(int j=0;j<=use;++j)
			linshi[j]=dp[j];
		for(int j=0;j<=use;++j)
			dp[j+h[i]]=(linshi[j+h[i]]+linshi[j])%mod;
		dp[h[i]]=(dp[h[i]]+1)%mod;
		/*
		cout<<i<<' '<<can<<endl;
		for(int i=0;i<=use;++i)
			cout<<dp[i]<<' ';*/
		//cout<<endl;
		ans=(ans+can)%mod;
	}
	cout<<ans;
	return 0;
}
/*
5
1 2 3 4 5

5
2 2 3 8 10

*/
