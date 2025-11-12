#include<bits/stdc++.h>
using namespace std;
long long n,k,sum[520000],a[520000],t=-1,ans;
long long mp[5001000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k){
			ans++;
			t=i;
			sum[i]=sum[i-1]^a[i];
			mp[sum[i]]=i;
			if(ans==1)mp[0]=0;
			continue;
		}
		sum[i]=sum[i-1]^a[i];
		if(mp[sum[i]^k]&&t<=mp[sum[i]^k]){
			t=i;ans++;if(ans==1)mp[0]=0;
		}
		mp[sum[i]]=i;
	}
	cout<<ans;
	return 0;
}
