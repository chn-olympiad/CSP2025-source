#include <bits/stdc++.h>
using namespace std;
int n,i,j,ans,s,a[5010],f[5010],C[2010][2010];
const int mod=998244353;
bool pd(){
	int i,ma=0,s=0,sum=0;
	for (i=1;i<=n;i++)
		if (f[i]==1){
			s++;
			ma=max(ma,a[i]);
			sum+=a[i];
		}
	if (s<3) return 0;
	if (sum>ma*2) return 1;
	else return 0;
}
void dfs(int t){
	if (t>n){
		if (pd()) ans=(ans+1)%mod;
		return ;
	}
	f[t]=1;dfs(t+1);
	f[t]=0;dfs(t+1);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if (a[n]==1){
		for (i=1;i<=n;i++){
			C[i][0]=C[i][i]=1;
			for (j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		for (i=3;i<=n;i++) ans=(ans+C[n][i])%mod;
		cout<<ans;
		return 0;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
