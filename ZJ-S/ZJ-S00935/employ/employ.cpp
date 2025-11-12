#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e2+10;
const int mod=998244353;
string s;
ll c[N],sum[N],f[N],a[N];
bool vis[N];
int n,m;
ll ans;
int dfs(int x,int cnt)
{	
//	cout<<x-1<<" "<<cnt<<"\n";
//	for(int i=1;i<x;i++)	
//		cout<<a[i]<<" ";
//	cout<<"\n\n";
	if(cnt>=m){
		ll ans=1;
		for(int i=2;i<=n-x;i++)
			ans=(ans*i)%mod;
//		for(int i=1;i<=x;i++)	
//			cout<<a[i]<<" ";
//		cout<<"\n"<<x<<" "<<ans<<"\n\n";
		return ans;
	} 
	if(cnt+sum[n]-sum[x]<m) return 0;
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(vis[i]) continue;
		vis[i]=true;a[x+1]=i;
		ans+=dfs(x+1,cnt+(sum[x+1]-sum[x]==1&&x-cnt<c[i]));
		ans%=mod;
		vis[i]=false;
	}
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(s[i-1]-'0');
	for(int i=1;i<=n;i++) cin>>c[i];
	if(sum[n]<m){
		cout<<0;
	} 
	else if(m==n) {
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i-sum[i]<c[i])
					f[i]++;
		for(int i=n;i>=1;i--)
			ans=(ans*(f[i]-(n-i)))%mod;
		cout<<ans;
	}
	else cout<<dfs(0,0);
	return 0;
}
