#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int N=1e6+5;
const int mod=998244353;
int n,k,a[N],ans,b[N],mx,c[N];
bool flg=true;
void dfs(int dep,int lim,int lst){
	if(dep>lim){
		int cnt=0;
		for(int i=1;i<=lim;++i)	cnt+=c[i];
		if(cnt>c[lim]*2){
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=lst+1;i<=n;++i){
		c[dep]=a[i];
		dfs(dep+1,lim,i);
	}
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=1;i<=n;++i){
		if(a[i]!=1)flg=false;
	}
	if(flg){
		int x=1;
		for(int i=1;i<=n;++i){
			x*=2;
			x%=mod;
		}
		cout<<(x-n*n-1)%mod;	
		return 0;
	}
	sort(a+1,a+1+n);
	for(int i=3;i<=n;++i)dfs(1,i,0);
	cout<<ans;
	return 0;
}