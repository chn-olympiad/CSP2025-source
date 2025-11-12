#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++) {
		cin>>a[i];
	}
	int maxx=0;
	for(int l=0;l<n;l++) {
		for(int r=l;r<n;r++) {
			//cout<<l<<" "<<r<<" "<<maxx<<" "<<endl;
			int sum=a[l];
			if(l==2) {
				sum=0;
			}else {
				for(int i=l+1;i<=r;i++) {
					sum=sum^a[i];
				}
			}
			int nmax=r-l;
			if(sum==k&&nmax>maxx&&nmax!=n-1) {
				maxx=nmax;
			}
		}
	}
	cout<<maxx;
	return 0;
}
