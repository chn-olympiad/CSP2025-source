#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,a[500005],ans;
map<int,int> mp;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i = 1;i <= n;i++){
		cin >> a[i]; 
	}
	for(int i = 1,sum = 0;i <= n;i++){
		sum ^= a[i];
		if(sum == k || mp[k ^ sum]){
			ans++;
			mp.clear();
			sum = 0;
		}
		else{
			mp[sum]++;
		}
	}
	cout << ans;
	return 0;
}
