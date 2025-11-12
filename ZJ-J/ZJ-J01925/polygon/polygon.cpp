#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=998244353;
int ans=0,s;
int c[5050][5050],n,a[5010];
void dfs(int x,int sum,int mx){
	if(x>n){
		if(sum>mx*2)ans++;
		ans%=mod;
		return ;
	}
	dfs(x+1,sum,mx);
	dfs(x+1,sum+a[x],a[x]);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	
	if(a[n]==1){
		c[0][0]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
			}
		}
		for(int i=3;i<=n;i++)ans=(ans+c[n][i])%mod;
		cout<<ans;
	}
	else if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}
	
	return 0;
}
//期望得分:100+100+30+64=294 
//ccf我求你了qwq 让我一等吧。。。 
 
