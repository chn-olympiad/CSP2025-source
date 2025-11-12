#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
int n,a[5005];
ll ans;
bool vis[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i = 1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i = 1;i<(1<<n);i++){
		for(int j = 0;j<n;j++){
			if((1<<j)&i) vis[j+1]=1;
		}
		int sum=0,mx = 0,cnt = 0;
		for(int j = 1;j<=n;j++)
			if(vis[j]) cnt++,sum+=a[j],mx = max(mx,a[j]);
		if(cnt>=3&&sum>mx*2) ans++,ans%=mod;
		memset(vis,0,sizeof(vis));
	}
	cout<<ans;
	return 0;
}
