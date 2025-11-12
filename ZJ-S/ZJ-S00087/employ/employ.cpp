#include<bits/stdc++.h>
using namespace std;
int n,m,bo,mod=998244353,b[510],c[510],a[510];
long long sum,ans,f[510][510];
string s;
void dfs(int k,int y){
	if(k-y>m)++ans;
	if(k>n)return;
	for(int i=1;i<=n;++i)
	if(!b[i]){
		if(y<c[i]){
			b[i]=1;
			if(s[k-1]=='1')dfs(k+1,y);
			else dfs(k+1,y+1);
			b[i]=0;
		}
		else{
			b[i]=1;
			dfs(k+1,y+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=0;i<n;++i)
	if(s[i]=='0')bo=1;
	if(n>21&&!bo){
		f[0][0]=1;
		for(int i=1;i<=n+1;++i)for(int j=1;j<=i;++j)f[i][j]=(f[i-1][j]+f[i-1][j-1])%mod;
		for(int i=m-1;i<=n-1;++i)sum=(sum+f[n][i])%mod;
		cout<<sum*2%mod<<"\n";
		return 0;
	}
	for(int i=1;i<=n;++i)cin>>c[i];
	dfs(1,0);
	cout<<ans<<"\n";
	return 0;
}
