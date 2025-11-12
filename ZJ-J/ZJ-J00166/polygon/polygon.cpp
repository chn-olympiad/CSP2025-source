#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int a[5001],ans=0,n;
long long dp[5001];
void dfs(int x,int k,int p,int op){
	if(k>p*2&&op==1){
		ans++;
		ans%=MOD;
	}
	if(x>n) return ;
	dfs(x+1,k+a[x],max(p,a[x]),1);
	dfs(x+1,k,p,0);
}
int main(){
    freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0,1);
	cout<<ans;
	return 0;
}
