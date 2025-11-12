#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],n,k;
int sum[N];
map<int,bool>mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	int ans=0;
	mp[0]=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]^a[i];
		if(mp[sum[i]^k]){
			ans++;
			mp.clear();
		}
		mp[sum[i]]=true;
	}
	cout<<ans;
	return 0;
}
