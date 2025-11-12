#include<bits/stdc++.h>
#define int long long
using namespace std;
int ar[500009];
int sum[500009];
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> ar[i];
		sum[i]=sum[i-1]^ar[i];
	}
	int last=0;
	int ans=0;
	for(int i=1;i<=n;i++){
		mp[0]=1;
		if(mp[k^(sum[i]^sum[last])]){
			ans++;
			last=i;
			mp.clear();
		}
		mp[sum[i]^sum[last]]=1;
	}
	cout << ans;
	return 0;
}

