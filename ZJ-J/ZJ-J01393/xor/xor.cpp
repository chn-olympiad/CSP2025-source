#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,cnt;
long long k,a[N],sum[N];
unordered_map<long long,int>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	mp[0]++;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]^a[i];
		if(mp[k^sum[i]]){
			cnt++;
			mp.clear();
		}
		mp[sum[i]]++;
	}
	cout<<cnt;
	return 0;
}
