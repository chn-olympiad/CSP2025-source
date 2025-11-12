#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,i,j,ans,C[510][510],a[510],b[510],c[510],f[510];
char ch;
const int mod=998244353;
bool pd(){
	int i,pass=0,fail=0;
	for (i=1;i<=n;i++){
		if (fail>=b[c[i]]||a[i]==0){fail++;continue;}
		pass++;
	}
	return pass>=m;
}
void dfs(int t){
	int i;
	if (t>n){
		if (pd()) ans=(ans+1)%mod;
		return ;
	}
	for (i=1;i<=n;i++)
		if (f[i]==0){
			f[i]=1;c[t]=i;
			dfs(t+1);
			f[i]=0;
		}
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>ch,a[i]=ch-'0';
	for (i=1;i<=n;i++) cin>>b[i];
	for (i=1;i<=n;i++)
		if (a[i]==0) break;
	if (i>n){
		for (i=1;i<=n;i++){
			C[i][0]=C[i][i]=1;
			for (j=1;j<i;j++) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
		for (i=m;i<=n;i++) ans=(ans+C[n][i])%mod;
		cout<<ans;
	}
	else{
		dfs(1);
		cout<<ans;
	}
	return 0;
}
