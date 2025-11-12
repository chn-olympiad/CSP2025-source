#include <bits/stdc++.h>
using namespace std;
const int N=5e3+5;
const int MOD=998244353;
int n,a[N];
long long ans,s[N];
void dfs(int k,int s,int s1,int maxx,int c){
	if(!c && s>=3 && s1>maxx*2)
		ans=(ans+1)%MOD,c=1;
	if(k==n+1) return;
	dfs(k+1,s+1,s1+a[k],max(maxx,a[k]),0);
	dfs(k+1,s,s1,maxx,c);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1) flag=0;
	}
	if(flag){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i;j++){
				if(j==i) s[j]=1;
				else s[j]=(s[j]*i/(i-j))%MOD;
			}
		}
		for(int i=3;i<=n;i++)
			ans=(ans+s[i])%MOD;
		cout<<ans<<'\n';
		return 0;
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0,0);
	cout<<ans;
	return 0;
}
