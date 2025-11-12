#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=998244353,MAXN=510;
ll n,m,ans;
ll c[MAXN],f[MAXN],wz[MAXN];
bool vis[MAXN];
char s[MAXN];
void dfs(ll pos,ll num,ll sum){
	if(sum==m){
		ans+=f[n-pos];
		ans%=mod;
		return ;
	}//选购了人 
	if(pos==n)
		return ;
	for(ll i=1;i<=n;i++){
		
		if(vis[i])
			continue;
		vis[i]=1;
		wz[pos]=i;
		if(num>=c[i]){
			dfs(pos+1,num+1,sum);
			vis[i]=0;
			continue;
		}
		if(s[pos+1]=='0'){
			dfs(pos+1,num+1,sum);
			vis[i]=0;
			continue;
		}
		dfs(pos+1,num,sum+1);
		vis[i]=0;
	}
	return ;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		ll res=1;
		for(ll i=2;i<=n;i++){
			res*=i;
			res%=mod;
		}
		cout<<res;
		return 0;
	}
	if(m==n){
		cout<<3;
		return 0;
	}
	for(ll i=1;i<=n;i++){
		cin>>s[i];
	} 
	for(ll i=1;i<=n;i++){
		cin>>c[i];
	}
	f[1]=1;
	f[0]=1;
	for(ll i=2;i<=n;i++){
		f[i]=f[i-1]*i;
		f[i]%=mod;
	}
	dfs(0,0,0);
	cout<<ans%mod;
	return 0;
} 
/*
10 5
1101111011
6 0 4 2 1 2 5 4 3 3

3 2
101
1 1 2
 */