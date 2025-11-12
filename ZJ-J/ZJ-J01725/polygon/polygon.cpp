#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5005,mod=998244353;
ll n,a[maxn],ans;
bool f[maxn];
void dfs(ll r,ll ma,ll pos){
	if(pos==r+1){
		ll k=0,s=0;
		for(int i=1;i<=r;i++){
			if(f[i]) s+=a[i],k++;
		}
		if(s+ma>2*ma&&k>=2) ans=(ans+1)%mod;
		return;
	}
	for(int i=0;i<=1;i++) f[pos]=i,dfs(r,ma,pos+1),f[pos]=0;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++) dfs(i-1,a[i],1);
	cout<<ans;
	return 0;
}
/*
By ZJ-J01725.
Luogu UID:1086453.
*/
