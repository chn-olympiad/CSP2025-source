#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[10001],f[10001],mod=998244353;
char s[10001];
void dfs(long long lq,long long rf,long long x){
	if(x==n){
		if(lq>=m)ans++;
		ans%=mod;
		return;
	}
	if(lq>=m){
		long long t=1;
		for(int i=1;i<=n-x;i++)t*=i;
		t%=mod;
		ans+=t;
		//cout<<(n-x+1)*(n-x)/2<<endl;
		ans%=mod;
		return;
	}
	for(int i=1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			if(s[x+1]=='0'||rf>=a[i])dfs(lq,rf+1,x+1);
			else dfs(lq+1,rf,x+1);
			f[i]=0;
		}
	}
}
int main()
{
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>s[i];
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,0,0);
	cout<<ans%mod;
	return 0;
}
