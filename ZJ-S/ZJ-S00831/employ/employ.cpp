#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=506;
int const MOD=998244353;
int n,m;
char c[N];
bool d[N];
int p[N],sum[N];
bool f[N];
int dfs(int x){
	if(x==n+1)
		return 1;
	int ans=0;
	for(int i=1;i<=n;i++){
		if(sum[i]>p[x])break;
		if(f[i])continue;
		f[i]=1;
		ans+=dfs(x+1);
		f[i]=0;
		ans%=MOD;
	}
	return ans;
}
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int A=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
		d[i]=(c[i]=='1');
		sum[i]=sum[i-1]+d[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	sort(p+1,p+n+1);
	if(n<=20){
		cout<<dfs(1);
	}
	if(A==1){
	}
	if(m==1){
		
	}
	if(m==n){
	
	}
	return 0;
}