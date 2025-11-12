#include<bits/stdc++.h>
using namespace std;
signed main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,a[200010],sum=0;
	cin>>n>>k;
	bool q=1;
	for(int i=0; i<n; i++) {
		cin>>a[i];
		if(a[i]!=0) q=0;
	}
	if(q=1) {
		cout<<n/2;
		return 0;
	} else {
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				int ans=a[i];
				for(int l=i+1; l<=j; l++) {
					if(ans==a[l]) {
						ans=0;
					} else {
						ans=1;
					}
				}
				if(ans==k) {
					sum++;
				}
			}
		}
		cout<<sum;
		return 0;
	}
	return 0;
}
