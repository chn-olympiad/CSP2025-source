#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const int N=5010,mod=998244353;
int n,a[N];
int c[N][N];
int ans=0;
void dfs1(int k,int maxn,ll sum,int cnt){
	if(k==n+1){
		int tot=sum+maxn;
		if(tot>maxn*2&&cnt>=3){
			ans=(ans+1)%mod;
		}
		return;
	}
	if(a[k]>maxn)dfs1(k+1,a[k],sum+maxn,cnt+1);
	else dfs1(k+1,maxn,sum+a[k],cnt+1);
	dfs1(k+1,maxn,sum,cnt);
}
void init(int n){
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			if(j==0||i==j)c[i][j]=1;
			else c[i][j]=(c[i-1][j]%mod+c[i-1][j-1]%mod)%mod;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	if(n<=20){
		dfs1(1,0,0,0);
		cout<<ans;
	}
	else{
		init(n);
		for(int i=3;i<=n;i++)ans=(ans%mod+c[n][i]%mod)%mod;
		cout<<ans;
	}
	return 0;
}