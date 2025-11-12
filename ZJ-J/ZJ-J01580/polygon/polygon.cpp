#include<bits/stdc++.h>
using namespace std;
long long n,mod=998244353;
long long a[6000],ans=0;
long long f[6000];
void dfs(long long x,long long k,long long s){
	for(int i=x+1;i<=n;i++){
		if(f[i]==0){
			f[i]=1;
			if(k+1>=3&&a[i]<s){
				ans=(ans+1)%mod;
			}
			dfs(i,k+1,s+a[i]);
			f[i]=0;
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	dfs(0,0,0);
	cout<<ans;
	return 0;
}
