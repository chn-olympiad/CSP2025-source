#include <bits/stdc++.h>
using namespace std;
long long n,a[5005];
long long vis[5005];
long long ans=0;
void dfs(long long l,long long ma){
	if(l>2*ma){
		ans++;
	}
	long long ll,j=1;
	for(int i=1; i<=n; i++){
		if(vis[j+1]){
			vis[j]=false;
			ll+=a[i];
			long long mama=max(ma,a[i]);
			dfs(ll,mama);
			vis[i]=true;
			j++;
		}
		
		
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	dfs(a[1],0);
	cout<<ans;
	return 0;
}
