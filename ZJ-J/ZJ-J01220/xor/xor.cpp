#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n,k;
int a[500005],sum[500005],ans=0;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>k;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		int tmp=a[i]^sum[i-1];
		sum[i]=tmp;
	}
	for(int now=1; now<=n;) {
		int mx=n+1,l,ml,r;
		for(l=now; l<=mx; l++) {
			for(r=l; r<=mx; r++) {
				int tmp=sum[r]^sum[l-1];
				if(tmp==k) {
					if(r<mx) mx=r,ml=l;
					break;
				}
			}
		}
		int tmp=sum[mx]^sum[ml-1];
		ans+=(tmp==k);
		now=mx+1;
	}
	cout<<ans;
	return 0;
}
