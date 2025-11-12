#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N=5e5+10;
int n,k,a[N],cnt,dp[N],xr,jj=1;
map<int,vector<int> >mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dp[i]=dp[i-1]^a[i];
		mp[dp[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		xr^=a[i];
		if(a[i]==k||xr==k){
			cnt++;
			xr=0;
			jj=i+1;
		}else{
			int ls=dp[i]^k;
			if(mp.count(ls)==1){
				int l=0,r=mp[ls].size()-1;
				while(l<=r){
					int mid=(l+r)>>1;
					if(mp[ls][mid]>=jj-1&&mp[ls][mid]<i){
						cnt++;jj=i+1;
						xr=0;
						break;
					}else if(mp[ls][mid]<jj){
						l=mid+1;
					}else{
						r=mid-1;
					}
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}

