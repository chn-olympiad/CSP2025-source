#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],sum[500005];
map<int,bool> mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]^a[i];
	int ans=0,la=0;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		if(mp[k^sum[i]]){
			for(int j=la;j<i;j++) mp[sum[j]]=0;
			ans++,la=i;
		}
		mp[sum[i]]=1;
	}
	cout<<ans;
	return 0;
}
