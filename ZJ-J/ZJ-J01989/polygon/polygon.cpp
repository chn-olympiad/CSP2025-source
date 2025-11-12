#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long n,ans;
long long a[5005];
long long C[5005][5005];
void dfs(long long i,long long s,long long ml,long long t){
	if(i>n){
		if(t<3) return;
		if(s<=2*ml) return;
		ans++;
		ans%=mod;
		return;
	}
	dfs(i+1,s+a[i],a[i],t+1);
	dfs(i+1,s,ml,t);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<25){
	    dfs(1,0,0,0);
	}else{
		C[1][1]=1;
		for(int i=2;i<=n+1;i++){
			for(int j=1;j<=i;j++){
				C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
			}
		}
		for(int i=4;i<=n+1;i++){
			ans=(ans+C[n+1][i])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}
