#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int maxv=5005;
const int mod=998244353;
int n,a[maxn],dp[maxn][maxv];
int qpow(int x,int y){
	if(y==0)return 1;
	long long k=qpow(x,y>>1);
	k=k*k%mod;
	if(y&1)k=k*x%mod;
	return k;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int V=0;
	for(int i=1;i<=n;i++)cin>>a[i],V=max(V,a[i]);
	sort(a+1,a+n+1);
	dp[0][0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int k=a[i];k<=V;k++){
			for(int x=0;x<=i-1;x++){
				dp[i][k]+=dp[x][k-a[i]];
				dp[i][k]%=mod;
			}
		}
		for(int x=0;x<=i-1;x++)for(int k=0;k<=a[i];k++)ans+=dp[x][k],ans%=mod;
	}
	cout<<(qpow(2,n)-1-ans+mod)%mod<<endl;
	return 0;
}
