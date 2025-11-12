#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=20,mod=998244353;
ll f[N],dp[N][1<<N],a[N],fac[510];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,pd=1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		char x;
		cin>>x;
		f[i]=x-'0';
		if(f[i])pd=0;
	}
	for(int i=0;i<n;i++)cin>>a[i];
	dp[0][0]=1;
	if(pd){
		cout<<0;
		return 0;
	}
	for(int i=0;i<1<<n;i++){
		int c1=0;
		for(int j=0;j<n;j++)if(i>>j&1)c1++;
		for(int j=0;j<=c1;j++){
			for(int k=0;k<n;k++)if(!(i>>k&1)){
				if(c1-j>=a[k]||!f[c1])dp[j][i|1<<k]+=dp[j][i];
				else dp[j+1][i|1<<k]+=dp[j][i];
			}
		}
	}
	ll ans=0;
	for(int i=m;i<=n;i++){
		ans+=dp[i][(1<<n)-1];
	}
	cout<<ans;
	return 0;
}