#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[5005];
signed main() {
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,f=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=3; i<=n; i++) {
		int s=0,h=0;
		for(int t=1; t<=n-i; t++) {
			for(int j=t; j<=i; j++) {
				s+=a[j];
				h=max(a[j],a[j+1]);
			}
			if(s>h){
				f++;
			}
		}
	}
	cout<<f;
	return 0;
}

