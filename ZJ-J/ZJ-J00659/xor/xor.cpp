#include<bits/stdc++.h>
#define ll long long
using namespace std;
unordered_map<ll,bool> mp;
ll n,k,a[500055],ans,sum;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	freopen("xor6.in","r",stdin);
	freopen("xor6.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	mp[0]=1;
	for(int i=1;i<=n;i++){
		int tsum=sum^a[i];
		int t=k^a[i];
		mp[sum]=1;
		if(mp[sum^t]){
			ans++;
			sum=0;
			mp.clear();
			mp[0]=1;
		}
		else sum^=a[i];
	}
	cout<<ans;
	return 0;
}