#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=998244353;
int n,a[5005],ans,f=1,s=1,sum[5005][5005];
void dfs(int x,int sum,int p,int m){
	if(p>=m){
		if(sum>a[x]*2){
			ans++;
			ans%=mod;
		}else{
			f=0;
		}
		return;
	}
	for(int i=x+1;i<=n;i++){
		if(f) dfs(i,sum+a[i],p+1,m);
		else break;
	}
	f=1;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin.sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) s=0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>a[3]*2){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(s){
		sum[0][0]=1;sum[1][0]=1;sum[1][1]=1;
		for(int i=2;i<=n;i++){
			sum[i][0]=1;
			for(int j=1;j<=i;j++){
				sum[i][j]=sum[i-1][j]+sum[i-1][j-1];
				sum[i][j]%=mod;
			}
		}
		for(int m=3;m<=n;m++){
			ans+=sum[n][m]%mod;
		}
		cout<<ans<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int m=3;m<=n;m++){
		for(int i=1;i<=(n-m+1);i++){
			dfs(i,a[i],1,m);
		}
	}
	cout<<ans%mod<<endl;
	return 0;
}