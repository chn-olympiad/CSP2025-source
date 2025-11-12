#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353,N=5e3+5;
bool flag;
int n,a[N],ans,c[N];
inline void dfs(int id,int sum){
	for(int i=id+1;i<=n;i++){
		if(sum+a[i]>2*a[i]){
			ans++;
		}	
		dfs(i,sum+a[i]);
	}
}
signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!flag){
			if(a[i]>1){
				flag=true;
			}
		}
	}
	sort(a+1,a+1+n);
	if(flag){
		dfs(0,0);
	}
	else{
		if(n>50){	
			c[0]=n;
			for(int i=1;i<=n;i++){
				c[i]=c[i-1]*(n-i+1)/i;
			}
			for(int i=3;i<=n;i++){
				ans=(ans+c[i])%mod;
			}
		}
		else{	
			dfs(0,0);
		}
	}
	cout<<ans%mod;
	return 0;
}
