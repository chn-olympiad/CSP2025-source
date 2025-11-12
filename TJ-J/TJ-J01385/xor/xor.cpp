#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n+5];
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	if(k<=1) {
		int ans=0;
		for(int i=1; i<=n; i++) {
			if(a[i]==k) {
				ans++;
			}
		}
		cout<<ans;
	} else {
		int ans=0;
		for(int i=1,j=1; i<=n;) {
			int aa=0;
			for(int o=i; o<=j; o++) {
				aa=aa^a[o];
			}
			if(aa==k) {
				ans++;
				i=j+1;
				j=i;
			} else {
				j++;
			}
			if(j-1==n) {
				i++;
				j=i;
			}
		}
		cout<<ans;
	}
	return 0;
}
