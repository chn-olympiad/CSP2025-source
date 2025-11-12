#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,i,j,ma,sum,a[5010],s[5010],vis[5010],c[5010][5010];
void dfs(int x,int y,int z,int now,int ans){
	int i;
	if(ans>y) sum=(sum+1)%mod;
	for(i=now+1;i<=z;i++)
		if(!vis[i]){
			vis[i]=1;
			dfs(x+1,y,z,i,ans+a[i]);
			vis[i]=0;
		}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(i=0;i<=n;i++){
		c[i][0]=c[i][i]=1;
		for(j=1;j<i;j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	for(i=1;i<=n;i++) cin>>a[i],ma=max(ma,a[i]);
	sort(a+1,a+n+1);
	if(ma==1){
		for(i=3;i<=n;i++) sum=(sum+c[n][i])%mod;
		cout<<sum;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]>a[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	for(i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(i=3;i<=n;i++){
		if(s[i-1]<=a[i]) continue;
		for(j=1;j<=n;j++) vis[j]=0;
		dfs(1,a[i],i-1,0,0);
	}
	cout<<sum;
}
