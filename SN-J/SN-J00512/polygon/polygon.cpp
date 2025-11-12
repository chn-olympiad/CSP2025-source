#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,l[5005],q[5005],ans;
int C[5005][5005];
void dfs(int step,int sum,int maxn){
	if(step>n){
		if(sum>2*maxn) ans=(ans+1)%mod;
		return ;
	}
	dfs(step+1,sum+l[step],max(maxn,l[step]));
	dfs(step+1,sum,maxn);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>l[i];
	sort(l+1,l+n+1);
	if(l[n]==1){//24Pts
		C[1][1]=1;
		for(int i=2;i<=n+1;i++){
			C[i][1]=1;
			for(int j=2;j<=i;j++)
				C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
		for(int i=4;i<=n+1;i++) ans=(ans+C[n+1][i])%mod;
		cout<<ans<<"\n";
		return 0;
	}
	if(n<=20){//40Pts
		dfs(1,0,0);
		cout<<ans%mod<<"\n";
		return 0;
	} 
	for(int i=1;i<=n;i++) q[i]=q[i-1]+l[i];
	for(int i=3;i<=n;i++){
		if(q[i-1]<=l[i]) continue;
		ans=(ans+1)%mod; 
		int d=q[i-1]-l[i]-1;
		int x=1;
		for(int j=1;j<n;j++){
			if(l[j]>d) break;
			ans=(ans+1)%mod;
			if(q[j]<d&&j!=1){
				x*=j;
			}
		}
		ans=(ans+x)%mod;
	}
	cout<<ans<<"\n";
	return 0;
}
