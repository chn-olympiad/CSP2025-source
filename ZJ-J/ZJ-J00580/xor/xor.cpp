#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,a[500005],k,ans,sum;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		sum^=a[i];
		if(sum==k){
			ans++;
			sum=0;
		}
	}
	cout<<ans;
}
//30
