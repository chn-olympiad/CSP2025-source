#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k,ans,sum=-1;
unordered_map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		if(sum==-1){
			sum=a;
		}
		else sum^=a;
		if(mp.count((sum^k))){
			ans++;
			mp.clear();
			mp[0]=1;
			sum=-1;
			continue;
		}
		mp[sum]=1;
	}
	cout<<ans;
}
