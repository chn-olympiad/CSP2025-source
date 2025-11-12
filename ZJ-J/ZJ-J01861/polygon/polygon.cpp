#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5010,mod=998244353;
int n,ans,a[N];
void xzk(int x,int ma,int sum){
	if(x>n){
		if(sum>ma*2){
			ans++;
			ans%=mod;
		}
		return;
	}
	xzk(x+1,ma,sum);
	sum+=a[x];
	ma=max(ma,a[x]);
	xzk(x+1,ma,sum);
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	xzk(1,0,0);
	cout<<ans%mod;
	return 0;
}