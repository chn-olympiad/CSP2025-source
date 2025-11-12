#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,k;
int a[N],f[N],sum[N];
int ans;
map<int,bool>vis;
map<int,int>mp;
void solve(){
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		if(sum[mp[sum[i]]]==sum[i]){
			f[i]=max(f[i],f[mp[sum[i]]]+1);
		}
		mp[sum[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(sum[i]==k)f[i]=1;
	}
	if(k==0){
		solve();
		return 0;
	}
	for(int i=1;i<=n;i++){
		f[i]=f[i-1];
		vis[sum[i]]=true;
		mp[sum[i]]=i;
		if(sum[i]==k){
			f[i]=max(f[i],1ll);
//			cout<<i<<' '<<f[i]<<'\n';
		}
		if(!vis[sum[i]^k]){
			continue;
		}
		f[i]=max(f[i],f[mp[sum[i]^k]]+1);
//		cout<<i<<' '<<f[i]<<' '<<mp[sum[i]^k]<<' '<<f[mp[sum[i]^k]]<<' '<<'\n';
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,f[i]);
//		cout<<i<<' '<<f[i]<<'\n';
	}
	cout<<ans<<"\n";;
	return 0;
}
