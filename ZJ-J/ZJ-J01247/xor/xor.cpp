#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[500005],b[500005],ans;
signed main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","r",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	b[1]=a[1];
	for(int i=2;i<=n;i++)b[i]=b[i-1]^a[i];
	int l=0,r=1;
	while(r<=n+1){
		if((b[l]^b[r])==k){
			ans++;
			l=r;
			r++;
		}
		else r++;
	}
	cout<<ans;
	return 0;
}
