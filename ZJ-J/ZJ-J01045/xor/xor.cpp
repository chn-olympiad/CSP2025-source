#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[500010],k,sum[500010];
int n,ans;
unordered_map<int,bool> mp;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=(sum[i-1]^a[i]);
		mp[0]=1;
		if(mp[(sum[i]^k)]==1){
			ans++;
			mp.clear();
			sum[i]=0;
		}else{
			mp[sum[i]]=1;
		}
	}
	cout<<ans;
	return 0;
}