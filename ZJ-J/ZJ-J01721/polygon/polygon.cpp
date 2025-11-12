#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e3+10;
int n,a[N],cnt,c[N][N],mod=998244353,ans=0;
void dfs(int i,int sum,int num,int x){
	if(i==n+1){
		if(x>=3 && sum>2*num) ans=(ans+1)%mod; 
		return ;
	} 
	dfs(i+1,sum+a[i],max(num,a[i]),x+1);
	dfs(i+1,sum,num,x);
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=max(a[i],cnt);
	}
	if(cnt==1){
		for(int j=0;j<=n;j++) c[j][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
			}
		}
		for(int i=3;i<=n;i++) ans=(ans+c[n][i])%mod;
		cout<<ans<<"\n";
		return 0;
	}
	dfs(1,0,0,0);
	cout<<ans<<"\n";
	return 0;
}